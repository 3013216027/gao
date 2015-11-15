/********************************************************************************
** Form generated from reading UI file 'settingnumberdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGNUMBERDIALOG_H
#define UI_SETTINGNUMBERDIALOG_H

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

QT_BEGIN_NAMESPACE

class Ui_SettingNumberDialog
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SettingNumberDialog)
    {
        if (SettingNumberDialog->objectName().isEmpty())
            SettingNumberDialog->setObjectName(QStringLiteral("SettingNumberDialog"));
        SettingNumberDialog->resize(325, 153);
        gridLayout = new QGridLayout(SettingNumberDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(SettingNumberDialog);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEdit = new QLineEdit(SettingNumberDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        horizontalLayout_2->addLayout(horizontalLayout);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(SettingNumberDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setEnabled(true);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(SettingNumberDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), SettingNumberDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SettingNumberDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SettingNumberDialog);
    } // setupUi

    void retranslateUi(QDialog *SettingNumberDialog)
    {
        SettingNumberDialog->setWindowTitle(QApplication::translate("SettingNumberDialog", "Dialog", 0));
        label->setText(QApplication::translate("SettingNumberDialog", "\350\256\276\347\275\256\347\202\271\346\225\260:", 0));
    } // retranslateUi

};

namespace Ui {
    class SettingNumberDialog: public Ui_SettingNumberDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGNUMBERDIALOG_H
