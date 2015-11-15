/********************************************************************************
** Form generated from reading UI file 'settingpointdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGPOINTDIALOG_H
#define UI_SETTINGPOINTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SettingPointDialog
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *spinBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QFrame *frame;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SettingPointDialog)
    {
        if (SettingPointDialog->objectName().isEmpty())
            SettingPointDialog->setObjectName(QStringLiteral("SettingPointDialog"));
        SettingPointDialog->resize(174, 239);
        gridLayout = new QGridLayout(SettingPointDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(SettingPointDialog);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(SettingPointDialog);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(SettingPointDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        spinBox = new QSpinBox(SettingPointDialog);
        spinBox->setObjectName(QStringLiteral("spinBox"));

        horizontalLayout_2->addWidget(spinBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(SettingPointDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(30, 41));

        horizontalLayout_3->addWidget(label_3);

        frame = new QFrame(SettingPointDialog);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(71, 61));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        horizontalLayout_3->addWidget(frame);


        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(SettingPointDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(SettingPointDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), SettingPointDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SettingPointDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SettingPointDialog);
    } // setupUi

    void retranslateUi(QDialog *SettingPointDialog)
    {
        SettingPointDialog->setWindowTitle(QApplication::translate("SettingPointDialog", "Dialog", 0));
        label->setText(QApplication::translate("SettingPointDialog", "\351\242\234\350\211\262:", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("SettingPointDialog", "\351\273\221\350\211\262", 0)
         << QApplication::translate("SettingPointDialog", "\346\265\205\350\223\235", 0)
         << QApplication::translate("SettingPointDialog", "\347\273\277\350\211\262", 0)
         << QApplication::translate("SettingPointDialog", "\351\273\204\350\211\262", 0)
         << QApplication::translate("SettingPointDialog", "\350\223\235\350\211\262", 0)
        );
        label_2->setText(QApplication::translate("SettingPointDialog", "\345\244\247\345\260\217:", 0));
        label_3->setText(QApplication::translate("SettingPointDialog", "\351\242\204\350\247\210:", 0));
    } // retranslateUi

};

namespace Ui {
    class SettingPointDialog: public Ui_SettingPointDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGPOINTDIALOG_H
