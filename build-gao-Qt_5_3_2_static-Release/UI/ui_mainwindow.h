/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionGenerate;
    QAction *actionWork;
    QAction *actionAbout;
    QAction *actionImportBinary;
    QAction *actionSaveBinary;
    QAction *actionExit;
    QAction *actionNumber;
    QAction *actionRange;
    QAction *actionAboutQt;
    QAction *actionImportText;
    QAction *actionSaveText;
    QAction *actionInput;
    QAction *actionA;
    QAction *actionInterface_Introduction;
    QAction *actionPoint_tp;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGraphicsView *graphicsView;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label;
    QCheckBox *checkBox;
    QProgressBar *progressBar;
    QMenuBar *menuBar;
    QMenu *menuTools;
    QMenu *menuFile;
    QMenu *menu_Import;
    QMenu *menu_Save;
    QMenu *menuHelp;
    QMenu *menuSetting;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(689, 620);
        actionGenerate = new QAction(MainWindow);
        actionGenerate->setObjectName(QStringLiteral("actionGenerate"));
        actionWork = new QAction(MainWindow);
        actionWork->setObjectName(QStringLiteral("actionWork"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionImportBinary = new QAction(MainWindow);
        actionImportBinary->setObjectName(QStringLiteral("actionImportBinary"));
        actionImportBinary->setEnabled(true);
        actionSaveBinary = new QAction(MainWindow);
        actionSaveBinary->setObjectName(QStringLiteral("actionSaveBinary"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionNumber = new QAction(MainWindow);
        actionNumber->setObjectName(QStringLiteral("actionNumber"));
        actionRange = new QAction(MainWindow);
        actionRange->setObjectName(QStringLiteral("actionRange"));
        actionAboutQt = new QAction(MainWindow);
        actionAboutQt->setObjectName(QStringLiteral("actionAboutQt"));
        actionImportText = new QAction(MainWindow);
        actionImportText->setObjectName(QStringLiteral("actionImportText"));
        actionSaveText = new QAction(MainWindow);
        actionSaveText->setObjectName(QStringLiteral("actionSaveText"));
        actionInput = new QAction(MainWindow);
        actionInput->setObjectName(QStringLiteral("actionInput"));
        actionA = new QAction(MainWindow);
        actionA->setObjectName(QStringLiteral("actionA"));
        actionInterface_Introduction = new QAction(MainWindow);
        actionInterface_Introduction->setObjectName(QStringLiteral("actionInterface_Introduction"));
        actionPoint_tp = new QAction(MainWindow);
        actionPoint_tp->setObjectName(QStringLiteral("actionPoint_tp"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setMinimumSize(QSize(388, 217));

        gridLayout_2->addWidget(graphicsView, 0, 0, 1, 3);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(53, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 1, 1, 1);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setEnabled(false);

        gridLayout->addWidget(pushButton, 0, 4, 1, 1);

        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 0, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        horizontalLayout->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(groupBox);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        horizontalLayout->addWidget(pushButton_5);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 5, 1, 1);

        pushButton_2->raise();
        pushButton->raise();

        gridLayout_2->addWidget(groupBox, 1, 0, 1, 3);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 2, 0, 1, 1);

        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setChecked(true);

        gridLayout_2->addWidget(checkBox, 2, 1, 1, 1);

        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        gridLayout_2->addWidget(progressBar, 2, 2, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 689, 23));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menu_Import = new QMenu(menuFile);
        menu_Import->setObjectName(QStringLiteral("menu_Import"));
        menu_Save = new QMenu(menuFile);
        menu_Save->setObjectName(QStringLiteral("menu_Save"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuSetting = new QMenu(menuBar);
        menuSetting->setObjectName(QStringLiteral("menuSetting"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setInputMethodHints(Qt::ImhNone);
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuSetting->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuTools->addAction(actionGenerate);
        menuTools->addAction(actionWork);
        menuFile->addAction(actionInput);
        menuFile->addAction(menu_Import->menuAction());
        menuFile->addAction(menu_Save->menuAction());
        menuFile->addAction(actionExit);
        menu_Import->addAction(actionImportText);
        menu_Import->addAction(actionImportBinary);
        menu_Save->addAction(actionSaveText);
        menu_Save->addAction(actionSaveBinary);
        menuHelp->addAction(actionInterface_Introduction);
        menuHelp->addAction(actionA);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionAboutQt);
        menuSetting->addAction(actionNumber);
        menuSetting->addAction(actionRange);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Clost-pair Caculator", 0));
        actionGenerate->setText(QApplication::translate("MainWindow", "\347\224\237\346\210\220\351\232\217\346\234\272\347\202\271(&G)", 0));
        actionWork->setText(QApplication::translate("MainWindow", "\350\256\241\347\256\227\346\234\200\350\277\221\347\202\271\345\257\271(&R)", 0));
        actionAbout->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216\346\234\254\350\275\257\344\273\266(&A)", 0));
        actionImportBinary->setText(QApplication::translate("MainWindow", "\345\257\274\345\205\245\344\272\214\350\277\233\345\210\266\346\225\260\346\215\256(&O)", 0));
        actionImportBinary->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        actionSaveBinary->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\344\270\272\344\272\214\350\277\233\345\210\266\346\226\207\344\273\266(&B)", 0));
        actionSaveBinary->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0));
        actionExit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272(X)", 0));
        actionExit->setShortcut(QApplication::translate("MainWindow", "Ctrl+X", 0));
        actionNumber->setText(QApplication::translate("MainWindow", "\347\202\271\347\232\204\346\225\260\351\207\217(&P)", 0));
        actionRange->setText(QApplication::translate("MainWindow", "\345\235\220\346\240\207\350\214\203\345\233\264(&C)", 0));
        actionAboutQt->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216QT(&Q)", 0));
        actionImportText->setText(QApplication::translate("MainWindow", "\345\257\274\345\205\245\346\226\207\346\234\254\346\225\260\346\215\256(&P)", 0));
        actionImportText->setShortcut(QApplication::translate("MainWindow", "Ctrl+P", 0));
        actionSaveText->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\344\270\272\346\226\207\346\234\254(&T)", 0));
        actionInput->setText(QApplication::translate("MainWindow", "\346\211\213\345\212\250\350\276\223\345\205\245(&U)", 0));
        actionA->setText(QApplication::translate("MainWindow", "\345\212\237\350\203\275\344\273\213\347\273\215(&E)", 0));
        actionInterface_Introduction->setText(QApplication::translate("MainWindow", "\347\225\214\351\235\242\344\273\213\347\273\215(&I)", 0));
        actionPoint_tp->setText(QApplication::translate("MainWindow", "\347\273\230\345\210\266\347\202\271\350\256\276\347\275\256", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "\346\223\215\344\275\234\346\240\217", 0));
        pushButton->setText(QApplication::translate("MainWindow", "\350\256\241\347\256\227", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "\347\224\237\346\210\220\346\225\260\346\215\256", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "\346\224\276\345\244\247", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "\347\274\251\345\260\217", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "\351\207\215\347\275\256\345\244\247\345\260\217", 0));
        label->setText(QApplication::translate("MainWindow", "\345\274\200\345\220\257\350\277\233\345\272\246\346\235\241", 0));
        checkBox->setText(QString());
        menuTools->setTitle(QApplication::translate("MainWindow", "\345\212\237\350\203\275(&D)", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266(&F)", 0));
        menu_Import->setTitle(QApplication::translate("MainWindow", "\345\257\274\345\205\245(&I)", 0));
        menu_Save->setTitle(QApplication::translate("MainWindow", "\344\277\235\345\255\230(&S)", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251(&H)", 0));
        menuSetting->setTitle(QApplication::translate("MainWindow", "\350\256\276\347\275\256(&W)", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
