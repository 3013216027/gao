#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <utility>

#include <QPoint>
#include <QMainWindow>
#include <QGraphicsScene>

#include "clostpair.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:

private slots:
    /* 菜单、按钮等行为，详见.cpp文件 */
    void on_actionExit_triggered(); //文件-退出

    void on_actionSaveBinary_triggered(); //文件-保存-保存为二进制文件

    void on_actionGenerate_triggered(); //生成数据

    void on_actionWork_triggered(); //计算最近点对

    void on_pushButton_2_clicked(); //功能-生成数据

    void on_pushButton_clicked(); //功能-计算最近点对

    void on_actionImportBinary_triggered(); //导入二进制数据

    void on_actionNumber_triggered(); //设置点数量

    void flush(bool showResult = false); //刷新

    void flushSize(); //scale

    void on_actionRange_triggered(); //设置坐标范围

    void on_actionAbout_triggered(); //关于本软件

    void on_actionAboutQt_triggered(); //关于QT

    void on_pushButton_3_clicked(); //放大

    void on_pushButton_4_clicked(); //缩小

    void on_pushButton_5_clicked(); //重置

    void on_progressBar_destroyed(); //进度条释放

    void on_checkBox_clicked(); //“开启进度条”复选框被选择/反选择

    void on_actionImportText_triggered(); //文件-导入文本数据

    void on_actionSaveText_triggered(); //文件-保存为文本

    void on_actionInput_triggered(); //文件-手动输入点坐标

    void on_actionInterface_Introduction_triggered();

    void on_actionA_triggered();

private:
    /* 缩放控制 */
    void sizeFit(); //取消缩放
    void sizeIncrease(); //放大
    void sizeDecrease(); //缩小

    Ui::MainWindow *ui;
    ClostPair* cp; //最近点对类
    QGraphicsScene* scene; //画板，维护其指向graphicsView的scene
    int cnt; //点数量，和cp->size()同步
    int times; //放缩倍数，大于0表示放大倍数，小于0表示缩小倍数，默认0表示不缩放
    bool progressBarOn; //进度条开关
    std::vector<std::pair<clost_pair_type, clost_pair_type> > best; //最近点对
    static int RADIUS; //点大小
    static const double RESULT_RADIUS; //结果标记区域
    //std::pair<int, int> size;

    //std::pair<QPoint, QPoint> best;
protected:
    void resizeEvent(QResizeEvent* re);
//    virtual QSize sizeHint() const;
};

#endif // MAINWINDOW_H
