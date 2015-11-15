/********************************************************************************
** Form generated from reading UI file 'settingrangedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGRANGEDIALOG_H
#define UI_SETTINGRANGEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SettingRangeDialog
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_2;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SettingRangeDialog)
    {
        if (SettingRangeDialog->objectName().isEmpty())
            SettingRangeDialog->setObjectName(QStringLiteral("SettingRangeDialog"));
        SettingRangeDialog->resize(298, 197);
        gridLayout = new QGridLayout(SettingRangeDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label = new QLabel(SettingRangeDialog);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_4->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEdit = new QLineEdit(SettingRangeDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        label_3 = new QLabel(SettingRangeDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        lineEdit_3 = new QLineEdit(SettingRangeDialog);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        horizontalLayout->addWidget(lineEdit_3);


        horizontalLayout_4->addLayout(horizontalLayout);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(SettingRangeDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lineEdit_2 = new QLineEdit(SettingRangeDialog);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        horizontalLayout_2->addWidget(lineEdit_2);

        label_4 = new QLabel(SettingRangeDialog);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);

        lineEdit_4 = new QLineEdit(SettingRangeDialog);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        horizontalLayout_2->addWidget(lineEdit_4);


        horizontalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(SettingRangeDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(SettingRangeDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), SettingRangeDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SettingRangeDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SettingRangeDialog);
    } // setupUi

    void retranslateUi(QDialog *SettingRangeDialog)
    {
        SettingRangeDialog->setWindowTitle(QApplication::translate("SettingRangeDialog", "Dialog", 0));
        label->setText(QApplication::translate("SettingRangeDialog", "\346\250\252\345\235\220\346\240\207(\346\225\264\346\225\260): ", 0));
        label_3->setText(QApplication::translate("SettingRangeDialog", "--", 0));
        label_2->setText(QApplication::translate("SettingRangeDialog", "\347\272\265\345\235\220\346\240\207(\346\225\264\346\225\260): ", 0));
        label_4->setText(QApplication::translate("SettingRangeDialog", "--", 0));
    } // retranslateUi

};

namespace Ui {
    class SettingRangeDialog: public Ui_SettingRangeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGRANGEDIALOG_H
