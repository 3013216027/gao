#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>

#include <QTime>
#include <QDebug>
#include <QWidget>
#include <QSpinBox>
#include <QTextEdit>
#include <QDataStream>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QResizeEvent>
#include <QGraphicsScene>

#include "clostpair.h"
#include "mainwindow.h"
#include "inputdialog.h"
#include "ui_mainwindow.h"
#include "settingrangedialog.h"
#include "settingnumberdialog.h"

int MainWindow::RADIUS = 4; //点大小(小圆半径)
const double MainWindow::RESULT_RADIUS = 15.0; //标示计算结果的大圆

//构造函数
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    cp = new ClostPair();
    cnt = (int)cp->size();
    times = 0;
    ui->checkBox->setChecked(false); //默认关闭进度条~
    ui->checkBox->setDown(true); //复选框微亮= =
    progressBarOn = ui->checkBox->isChecked();
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    //Qt5.1+ connect(ui->graphicsView, SIGNAL(rubberBandChanged(QRect, QPointF, QPointF)), this, SLOT(flushSize(QRect, QPointF, QPointF)));
    //graphicsView
    int width = std::max(std::abs(cp->RANGE_WIDTH_MIN), std::abs(cp->RANGE_WIDTH_MAX)) + 4;
    int height = std::max(std::abs(cp->RANGE_HEIGHT_MIN), std::abs(cp->RANGE_HEIGHT_MAX)) + 4;
    /*
     * x-ray: (-width_min, 0, width_max, 0)
     * y-ray: (0, -height_min, 0, height_max)
     */
#ifdef DEBUG
    fprintf(stderr, "%d, %d\n", height, width);
#endif
    /* 初始化x-y坐标轴 */
    scene->addLine(-width, 0, width, 0);
    scene->addLine(0, -height, 0, height);

    //ui->graphicsView->adjustSize();
    ui->progressBar->setValue(ui->progressBar->maximum()); //进度条初始化
    //ui->
    //setFixedSize(sizeHint());
    setWindowTitle(QString::fromUtf8("最近点对计算器 v1.0"));
}

MainWindow::~MainWindow() {
    delete ui;
}

//退出菜单
void MainWindow::on_actionExit_triggered() {
    close();
}

//二进制文件保存
void MainWindow::on_actionSaveBinary_triggered() {
    QString path = QFileDialog::getSaveFileName(this, QString::fromUtf8("保存文件"), ".",
                                                QString::fromUtf8("最近点对文件(*.cdf);;数据文件(*.dat)"));
    if (path.isEmpty()) {
#ifdef DEBUG
        QMessageBox::information(this, tr("Save"), tr("Cancled!"));
#endif
    } else {
#ifdef DEBUG
        QMessageBox::information(this, tr("Save"), tr("Save to ") + path);
#endif
        QFile *file = new QFile(path);
        file->open(QIODevice::WriteOnly);
        QDataStream out(file);
        out << (qint32)cnt;
        for (auto it: cp->points) {
            //std::cerr << it.first << ", " << it.second << " | " << (qreal)it.first << ", " << (qreal)it.second << std::endl;
            out << (qreal)it.first << (qreal)it.second;
        }
        file->close();
        QMessageBox::information(this, QString::fromUtf8("保存"), QString::fromUtf8("保存成功!"));
    }
}

void MainWindow::on_actionImportBinary_triggered() {
    //导入二进制数据
    QString path = QFileDialog::getOpenFileName(this, QString::fromUtf8("导入数据"), ".",
                                                QString::fromUtf8("最近点对文件(*.cdf);;数据文件(*.dat)"));
    if (path.isEmpty()) {
#ifdef DEBUG
        QMessageBox::information(this, tr("Import"), tr("Cancled!"));
#endif
    } else {
#ifdef DEBUG
        QMessageBox::information(this, tr("Import"), tr("Import from ") + path);
#endif
        QFile *file = new QFile(path);
        file->open(QIODevice::ReadOnly);
        QDataStream in(file);
        qint32 rev_cnt;
        qreal rev, rev2;
        bool error = false;
        in >> rev_cnt;
        cnt = (int)rev_cnt;

        //std::cerr << "cnt = " << rev_cnt << " | " << cnt << std::endl;
        cp->clear();
        cp->RANGE_WIDTH_MIN = -ClostPair::DEFAULT_WIDTH;
        cp->RANGE_WIDTH_MAX = ClostPair::DEFAULT_WIDTH;
        cp->RANGE_HEIGHT_MIN = -ClostPair::DEFAULT_HEIGHT;
        cp->RANGE_HEIGHT_MAX = ClostPair::DEFAULT_HEIGHT;
        for (int i = 0; i < cnt; ++i) {
            in >> rev >> rev2;
            if (rev > cp->RANGE_WIDTH_MAX) cp->RANGE_WIDTH_MAX = rev;
            if (rev < cp->RANGE_WIDTH_MIN) cp->RANGE_WIDTH_MIN = rev;
            if (rev2 > cp->RANGE_HEIGHT_MAX) cp->RANGE_HEIGHT_MAX = rev2;
            if (rev2 < cp->RANGE_HEIGHT_MIN) cp->RANGE_HEIGHT_MIN = rev2;
            if (error) {
                //读入错误数据
                return;
            }
            cp->points.emplace_back(std::make_pair((clost_pair_type)rev, (clost_pair_type)rev2));
        }
        file->close();
        flush();
        QMessageBox::information(this, QString::fromUtf8("导入数据"), QString::fromUtf8("成功导入 ")
                                 + QString::number(cnt) + QString::fromUtf8(" 个点!"));
    }
}

//生成数据
void MainWindow::on_actionGenerate_triggered() {
    if (cnt < 2) {
        QMessageBox::warning(this, QString::fromUtf8("警告"), QString::fromUtf8("当前设置的点数量为 ")
                             + QString::number(cnt) + QString::fromUtf8(", 设置无效, 请进入\"设置-点的数量\"修改！"));
        //warning.exec();
        return;
    }
    //statusBar()->clearMessage();
    QTime t1 = QTime::currentTime();
    statusBar()->showMessage(QString::fromUtf8("数据生成中..."));
    if (cp == NULL) {
#ifdef DEBUG
        //cp = new ClostPair((size_t)cnt);
        std::cerr << "Error at actionGenerate: cp is NULL!!!" << std::endl;
#endif
    } else {
        cp->rebuild(cnt, ui->progressBar, progressBarOn);
    }

    //QGraphicsScene* scene = new QGraphicsScene(this);
    //ui->graphicsView->setScene(scene);
    statusBar()->showMessage(QString::fromUtf8("重绘中，请稍后..."));
    flush(); //刷新坐标系,绘点
    QTime t2 = QTime::currentTime();
    statusBar()->showMessage(QString::fromUtf8("完成! 生成了 ") + QString::number(cnt)
                             + QString::fromUtf8(" 个点，用时 ") + QString::number(t1.msecsTo(t2)) + " ms.");
}

void MainWindow::on_actionWork_triggered() {
    if (cnt < 2) {
        QMessageBox::warning(this, QString::fromUtf8("警告"), QString::fromUtf8("当前设置的点数量为 ")
                             + QString::number(cnt) + QString::fromUtf8(", 设置无效, 请进入\"设置-点的数量\"修改！"));
        //warning.exec();
        return;
    }
    statusBar()->showMessage(QString::fromUtf8("计算中..."));
    QTime t1 = QTime::currentTime();
    cp->work(ui->progressBar, progressBarOn);
    best = cp->getBest(); //计算
    QTime t2 = QTime::currentTime();
    statusBar()->showMessage(QString::fromUtf8("完成! 用时 ") + QString::number(t1.msecsTo(t2)) + " ms. "
                            + QString::fromUtf8(" 最近点对是 (") + QString::number(best[0].first, 'f', 3) + ", "
                            + QString::number(best[0].second, 'f', 3) + QString::fromUtf8(")和(")
                            + QString::number(best[1].first, 'f', 3) + ", " + QString::number(best[1].second, 'f', 3) + "). "
                            + QString::fromUtf8("距离为 ") + QString::number(cp->mindistance, 'f', 6) + ".");
#ifdef DEBUG
    std::cerr << "(" << best[0].first << ", " << best[0].second << ") -> ("
              << best[1].first << ", " << best[1].second << ")" << std::endl;
#endif
    flush(true); //刷新坐标系，绘点，标记答案
}

//菜单-生成数据
void MainWindow::on_pushButton_2_clicked() {
    on_actionGenerate_triggered();
}

//菜单-计算最近点对
void MainWindow::on_pushButton_clicked() {
    on_actionWork_triggered();
}

//刷新坐标系和绘图板
void MainWindow::flush(bool showResult) {
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    int width = std::max(std::abs(cp->RANGE_WIDTH_MIN), std::abs(cp->RANGE_WIDTH_MAX)) + 4; //OFFSET
    int height = std::max(std::abs(cp->RANGE_HEIGHT_MIN), std::abs(cp->RANGE_HEIGHT_MAX)) + 4;
    /*
     * x-ray: (-width, 0, width, 0)
     * y-ray: (0, -height, 0, height)
     */
    if (showResult) {
        //标记最近点对所在区域
        double cx = (best[0].first + best[1].first) * 0.5;
        double cy = (best[0].second + best[1].second) * 0.5;
        double ra = sqrt((cx - best[0].first) * (cx - best[0].first) + (cy - best[0].second) * (cy - best[0].second));
        if (ra < MainWindow::RESULT_RADIUS) {
            scene->addEllipse(cx - MainWindow::RESULT_RADIUS, -cy - MainWindow::RESULT_RADIUS,
                              MainWindow::RESULT_RADIUS * 2.0, MainWindow::RESULT_RADIUS * 2.0, QPen(), QBrush(Qt::white));
        }
    }

    /* 重绘坐标轴 */
    scene->addLine(-width, 0, width, 0);
    scene->addLine(0, -height, 0, height);

    /* 重绘点 */
    for (auto it: cp->points) {
        scene->addEllipse(it.first - (MainWindow::RADIUS >> 1), -it.second - (MainWindow::RADIUS >> 1),
                          MainWindow::RADIUS, MainWindow::RADIUS, QPen(), QBrush(Qt::cyan));
    }

    //最近点对着色
    if (showResult) {
        scene->addEllipse(best[0].first - (MainWindow::RADIUS >> 1), -best[0].second - (MainWindow::RADIUS >> 1),
                MainWindow::RADIUS, MainWindow::RADIUS, QPen(), QBrush(Qt::red));
        scene->addEllipse(best[1].first - (MainWindow::RADIUS >> 1), -best[1].second - (MainWindow::RADIUS >> 1),
                MainWindow::RADIUS, MainWindow::RADIUS, QPen(), QBrush(Qt::red));
        scene->addLine(best[0].first, -best[0].second, best[1].first, -best[1].second, QPen(Qt::red));
    }

    ui->pushButton->setEnabled(cnt > 1); //点数>=2时，设置“计算最近点对”按钮为可点击状态
    //setFixedSize(sizeHint());
}

//重制图形大小
void MainWindow::flushSize() {
#ifdef DEBUG
    static int cnt = 0;
    fprintf(stderr, "%d:\n", ++cnt);
    for (auto it: reg) {
        fprintf(stderr, "%f %f %f %f\n", it.topLeft().rx(), it.topLeft().ry(), it.width(), it.height());
    }
#endif
}

//菜单-设置点的数量
void MainWindow::on_actionNumber_triggered() {
    SettingNumberDialog setNumber(this);
    setNumber.lineEdit->setText(QString::number(cnt));
    //setNumber.buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    if (setNumber.exec()) {
        cnt = setNumber.lineEdit->text().toInt();
    }
}

//菜单-设置点坐标范围
void MainWindow::on_actionRange_triggered() {
    SettingRangeDialog setRange(this);
    setRange.lineEdit->setText(QString::number(cp->RANGE_WIDTH_MIN));
    setRange.lineEdit_3->setText(QString::number(cp->RANGE_WIDTH_MAX));
    setRange.lineEdit_2->setText(QString::number(cp->RANGE_HEIGHT_MIN));
    setRange.lineEdit_4->setText(QString::number(cp->RANGE_HEIGHT_MAX));
    //setRange.buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    if (setRange.exec()) {
        cp->RANGE_WIDTH_MIN = setRange.lineEdit->text().toInt();
        cp->RANGE_WIDTH_MAX = setRange.lineEdit_3->text().toInt();
        cp->RANGE_HEIGHT_MIN = setRange.lineEdit_2->text().toInt();
        cp->RANGE_HEIGHT_MAX = setRange.lineEdit_4->text().toInt();
    }
    //flush();
}

//菜单-关于本软件
void MainWindow::on_actionAbout_triggered() {
    QMessageBox::about(this, QString::fromUtf8("关于本软件"),
                       QString::fromUtf8("<h2><strong>本软件用于计算平面最近点对</strong></h2><hr>"
                                           "<p>更多帮助请访问<a href=\"https://www.zybuluo.com/3013216027/note/210408\">"
                                           "最近点对计算器v1.0功能说明</a></p><p align=\"right\">郑冬健 2015年10月于天津大学北洋园<br/>"
                                           "Copyright(c) 2015 zhengdongjian@tju.edu.cn All Rights Reserved.</p>"));
}

//菜单-关于-界面介绍
void MainWindow::on_actionInterface_Introduction_triggered() {
    QMessageBox::about(this, QString::fromUtf8("界面介绍"),
                       QString::fromUtf8("<h4><strong>界面介绍</strong></h4><ul><li>绘图框：用作绘图，坐标轴用于划分平面4个象限</li>"
                                          "<li>操作栏 <br><ul><li>放大、缩小、重置大小：用于调整绘图窗口的放缩，方便观察</li><li>生成数据：功"
                                          "能同<code>功能-生成随机点</code></li><li>计算：功能同'功能-计算最近点对'</li></ul></li><li>进度"
                                          "条：勾选'开启进度条'选框可开启进度条，在生成数据和计算最近点对时可以提供良好的用户体验，直观地显示程序的运"
                                          "行进度。尤其当点数量相当多时，进度条可以达到较好的辅助显示效果。</li><li>状态栏：在生成数据、计算最近点对"
                                          "、数据导入/导出等完成后，辅助报告运行结果，提供一些对用户有帮助的辅助信息</li></ul><p>更多帮助请访问<a h"
                                          "ref=\"https://www.zybuluo.com/3013216027/note/210408\">最近点对计算器v1.0功能说明</a></p>"));
}

//菜单-关于-功能介绍
void MainWindow::on_actionA_triggered() {
    QMessageBox::about(this, QString::fromUtf8("菜单功能介绍"),
                       QString::fromUtf8("<h4><strong>文件</strong></h4><ul><li>手动输入：可直接手动输入点坐标，具有自检功能，能对不合法"
                                            "的输入（如只有一个点，坐标输入不完整，异常字符等）作相应处理</li><li>导入 <br><ul><li>导入文本数据：可"
                                            "导入普通文本格式保存的坐标数据，适合较小规模数据的保存、修改和访问。可处理异常字符、坐标数据不完整(如某个点"
                                            "只有横坐标没有纵坐标)、点数量不足2个等异常情况。</li><li>导入二进制数据：可导入二进制格式保存的坐标数据，"
                                            "适合大规模数据的保存、分享(相比普通文本可节省约10%的数据文件占用的磁盘空间)</li></ul></li><li>保存 <br>"
                                            "<ul><li>保存为文本：可导出当前点为文本数据，适合少量数据的保存，占用磁盘空间大。程序初始化会随机一小部分点，"
                                            "因此在程序启动后直接保存数据亦可成功</li><li>保存为二进制数据：可导出当前点为二进制数据，适合大量数据的保存，"
                                            "占用磁盘空间相对较小。</li></ul></li><li>退出：退出程序</li></ul><h4><strong>功能</strong></h4><ul>"
                                            "<li>生成随机点：根据'设置'中关于点的坐标范围和点的数量的限制，随机生成满足条件的相应数量的点，并自动完成绘制。"
                                            "随机生成点时会自动根据坐标范围和点数量的限制作做合法性检查。</li><li>计算最近点对：计算最近点对并在图中标识，"
                                            "当两点距离较大，差别较明显时，程序直接用红线和红点标识结果；当两点距离很小时，程序会自动添加一个圈以标识结果，方"
                                            "便观察。结果会同步地在状态栏显示。</li></ul><h4><strong>设置</strong></h4><ul><li>点的数量：设置欲生成"
                                            "的点的数量</li><li>坐标范围：设置欲生成的点的坐标范围</li></ul><p>更多帮助请访问"
                                            "<a href=\"https://www.zybuluo.com/3013216027/note/210408\">最近点对计算器v1.0功能说明</a></p>"));
}

//菜单-关于qt
void MainWindow::on_actionAboutQt_triggered() {
    QMessageBox::aboutQt(this, QString::fromUtf8("关于QT"));
}

/*
 * size auto fit, increase and decrease
 */
void MainWindow::sizeFit() {
    while (times > 0) {
        sizeDecrease();
    }
    while (times < 0) {
        sizeIncrease();
    }
#ifdef DEBUG
    std::cerr << ui->graphicsView->width() << ", " << ui->graphicsView->height() << ", " << times << std::endl;
#endif
}

//放大
void MainWindow::sizeIncrease() {
    ui->graphicsView->scale(2.0, 2.0);
    ++times;
#ifdef DEBUG
    std::cerr << ui->graphicsView->width() << ", " << ui->graphicsView->height() << ", " << times << std::endl;
#endif
}

//缩小
void MainWindow::sizeDecrease() {
    ui->graphicsView->scale(0.5, 0.5);
    --times;
#ifdef DEBUG
    std::cerr << ui->graphicsView->width() << ", " << ui->graphicsView->height() << ", " << times << std::endl;
#endif
}

//放大按钮
void MainWindow::on_pushButton_3_clicked()
{
    sizeIncrease();
}

//缩小按钮
void MainWindow::on_pushButton_4_clicked()
{
    sizeDecrease();
}

//重置大小按钮
void MainWindow::on_pushButton_5_clicked()
{
    sizeFit();
}

//进度条释放
void MainWindow::on_progressBar_destroyed()
{
    //Nothing to do.
}

//“开启进度条”复选框
void MainWindow::on_checkBox_clicked()
{
    progressBarOn = ui->checkBox->isChecked();
}

/* 窗口放大/缩小时重绘调整坐标系 */
void MainWindow::resizeEvent(QResizeEvent* re) {
    if (re->oldSize().width() == -1) {
        //first start up
        return;
    }
    /* a signal resizeEvent was sent when the main window size was changed */
}

//菜单-导入文本坐标数据
void MainWindow::on_actionImportText_triggered()
{
    QMessageBox warning(this);
    warning.setInformativeText(QString::fromUtf8("请将所有需要导入的点保存为如下格式的文本(.txt)文件：\n"
                                                 "x1 y1\n"
                                                 "x2 y2\n"
                                                 "...\n"
                                                 "xn yn\n"
                                                 "两个数之间可用任意空白符(回车，空格，制表符等)分隔\n***不需要输入点个数!***\n"));
    warning.exec();

    //if (warning.show())

    QString path = QFileDialog::getOpenFileName(this, QString::fromUtf8("导入点"), ".",
                                                QString::fromUtf8("文本文件(*.txt)"));
    if (path.isEmpty()) {
#ifdef DEBUG
        QMessageBox::information(this, tr("Import"), tr("Cancled!"));
#endif
    } else {
#ifdef DEBUG
        QMessageBox::information(this, tr("Import"), tr("Import from ") + path);
#endif
        QFile *file = new QFile(path);
        file->open(QIODevice::ReadOnly);
        QTextStream in(file);
        qreal rev, rev2;
        cnt = 0;

        //std::cerr << "cnt = " << rev_cnt << " | " << cnt << std::endl;
        cp->clear();
        cp->RANGE_WIDTH_MIN = -ClostPair::DEFAULT_WIDTH;
        cp->RANGE_WIDTH_MAX = ClostPair::DEFAULT_WIDTH;
        cp->RANGE_HEIGHT_MIN = -ClostPair::DEFAULT_HEIGHT;
        cp->RANGE_HEIGHT_MAX = ClostPair::DEFAULT_HEIGHT;

        in.skipWhiteSpace();
        while (!in.atEnd()) {
            in >> rev >> rev2;
            in.skipWhiteSpace();
            if (in.status()) {
                QMessageBox error(this);
                error.setInformativeText(QString::fromUtf8("读取文件数据错误！请检查文件数据格式是否正确(无效字符，无法成对匹配的坐标等)！"));
                error.exec();
                file->close();
                return;
            }
            //std::cerr << rev << ", " << rev2 << std::endl;
            if (rev > cp->RANGE_WIDTH_MAX) cp->RANGE_WIDTH_MAX = rev;
            if (rev < cp->RANGE_WIDTH_MIN) cp->RANGE_WIDTH_MIN = rev;
            if (rev2 > cp->RANGE_HEIGHT_MAX) cp->RANGE_HEIGHT_MAX = rev2;
            if (rev2 < cp->RANGE_HEIGHT_MIN) cp->RANGE_HEIGHT_MIN = rev2;
            cp->points.emplace_back(std::make_pair((clost_pair_type)rev, (clost_pair_type)rev2));
            ++cnt;
        }
        file->close();
        if (cnt > 1) {
            flush();
            QMessageBox::information(this, QString::fromUtf8("导入文本数据"), QString::fromUtf8("成功导入 ")
                                     + QString::number(cnt) + QString::fromUtf8(" 个点!"));
        } else {
            QMessageBox::warning(this, QString::fromUtf8("导入文本数据"), QString::fromUtf8("导入点数少于2个，导入失败！"));
            cnt = 2;
        }
    }
}

//菜单-保存文本数据
void MainWindow::on_actionSaveText_triggered()
{
    QString path = QFileDialog::getSaveFileName(this, QString::fromUtf8("保存文件"), ".",
                                                QString::fromUtf8("文本文件(*.txt)"));
    if (path.isEmpty()) {
#ifdef DEBUG
        QMessageBox::information(this, tr("Save"), tr("Cancled!"));
#endif
    } else {
#ifdef DEBUG
        QMessageBox::information(this, tr("Save"), tr("Save to ") + path);
#endif
        QFile *file = new QFile(path);
        file->open(QIODevice::WriteOnly);
        QTextStream out(file);
        for (auto it: cp->points) {
            out << (qreal)it.first << " " << (qreal)it.second << "\r\n";
        }
        file->close();
        QMessageBox::information(this, QString::fromUtf8("保存"), QString::fromUtf8("保存成功!"));
    }
}

//菜单-文件-手动输入点坐标
void MainWindow::on_actionInput_triggered()
{
    QMessageBox warning(this);
    warning.setInformativeText(QString::fromUtf8("***注意*** 此操作会清空当前图中的点!"
                                                 "请按以下格式输入点坐标：\n"
                                                 "x1 y1\n"
                                                 "x2 y2\n"
                                                 "...\n"
                                                 "xn yn\n"
                                                 "两个数之间可用任意空白符(回车，空格，制表符等)分隔，不需要输入点的个数"));
    warning.exec();

    InputDialog input(this);
    /* 重新输入事件循环 */
ReInput:
    if (!input.exec()) {
        return;
    }
    //std::cerr << "execute input" << std::endl;
    QString txt = input.textEdit->toPlainText();
    /* 需要检查输入数据是否正确，选用stringstream */
    std::stringstream in;
    in << txt.toStdString();
    while (isspace(in.peek())) in.ignore();
    //std::cerr << txt.toStdString() << std::endl;

    cnt = 0;
    cp->clear();
    cp->RANGE_WIDTH_MIN = -ClostPair::DEFAULT_WIDTH;
    cp->RANGE_WIDTH_MAX = ClostPair::DEFAULT_WIDTH;
    cp->RANGE_HEIGHT_MIN = -ClostPair::DEFAULT_HEIGHT;
    cp->RANGE_HEIGHT_MAX = ClostPair::DEFAULT_HEIGHT;
    double rev, rev2;
    while (!in.fail() && !in.eof()) {
        in >> rev >> rev2;
        /* ignore space char may cause fail error by eof problem...
        while (isspace(in.peek()) || in.peek() == '\n') {
            //std::cerr << "ignore :" << (char)in.peek() << ":" << std::endl;
            in.ignore();
        }*/
        if (in.fail()) break; //读入失败(如输入中包含字母，无效字符，输入数据无法全部匹配成点坐标等)

        //std::cerr << "rev2 = " << rev2 << std::endl;
        //rev2 = -rev2; bug fix: no need to pre-change.绘图时转换，此处无需转换
        if (rev > cp->RANGE_WIDTH_MAX) cp->RANGE_WIDTH_MAX = rev;
        if (rev < cp->RANGE_WIDTH_MIN) cp->RANGE_WIDTH_MIN = rev;
        if (rev2 > cp->RANGE_HEIGHT_MAX) cp->RANGE_HEIGHT_MAX = rev2;
        if (rev2 < cp->RANGE_HEIGHT_MIN) cp->RANGE_HEIGHT_MIN = rev2;
        //std::cerr << "get a point " << rev << ", " << rev2 << std::endl;
        cp->points.emplace_back(std::make_pair((clost_pair_type)rev, (clost_pair_type)rev2));
        ++cnt;
    }
    if (in.fail()) {
        //读入错误
        //std::cerr << "fail" << std::endl;
        QMessageBox error(this);
        error.setInformativeText(QString::fromUtf8("输入错误，请检查输入数据格式(字母，无效字符，最后一个数字匹配不到纵坐标无法构成完整点坐标等)！"));
        error.exec(); //阻塞式错误提醒

        //回退输入数据，重新输入
        input.textEdit->setText(txt);
        in.clear();
        in.ignore(1000007);
        //std::cerr << "goto reinput" << std::endl;
        goto ReInput;
    } else if (cnt < 2) {
        //点数过少，回退
        QMessageBox error(this);
        error.setInformativeText(QString::fromUtf8("请注意，输入的点数少于2个，无法用于计算最近点对，请增加点数!"));
        error.exec();
        input.textEdit->setText(txt);
        goto ReInput;
    } else {
        //读入成功，完毕
        flush();
        QMessageBox::information(this, QString::fromUtf8("导入文本"), QString::fromUtf8("成功导入 ")
                                 + QString::number(cnt) + QString::fromUtf8(" 个点!"));
    }
    //std::cerr << "finish" << std::endl;
}
