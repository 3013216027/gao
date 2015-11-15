#include "settingrangedialog.h"
#include "ui_settingrangedialog.h"

#include <QPushButton>
#include <iostream>

SettingRangeDialog::SettingRangeDialog(QWidget *parent) : QDialog(parent) {
    setupUi(this);
    setWindowTitle(QString::fromUtf8("设置点坐标范围"));
    buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);

    QRegExp regExp("-{0,1}0{0,}[1-9][0-9]{0,2}");
    QRegExp regExp2("-{0,1}0{0,}[1-9][0-9]{0,2}");
    QRegExp regExp3("-{0,1}0{0,}[1-9][0-9]{0,2}");
    QRegExp regExp4("-{0,1}0{0,}[1-9][0-9]{0,2}");
    lineEdit->setValidator(new QRegExpValidator(regExp, this));
    lineEdit_2->setValidator(new QRegExpValidator(regExp2, this));
    lineEdit_3->setValidator(new QRegExpValidator(regExp3, this));
    lineEdit_4->setValidator(new QRegExpValidator(regExp4, this));

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
}

bool SettingRangeDialog::check() {
    QLineEdit* editor[4] = {lineEdit, lineEdit_2, lineEdit_3, lineEdit_4};
    for (int i = 0; i < 4; ++i) {
        if (!editor[i]->hasAcceptableInput()) {
            return false;
        }
    }
    return editor[0]->text().toInt() < editor[2]->text().toInt() && editor[1]->text().toInt() < editor[3]->text().toInt();
}

void SettingRangeDialog::on_lineEdit_textChanged(const QString &arg1) {
#ifdef DEBUG
    std::cerr << "text change1: " << arg1.toStdString() << std::endl;
#endif
    buttonBox->button(QDialogButtonBox::Ok)->setEnabled(check());
}

void SettingRangeDialog::on_lineEdit_2_textChanged(const QString &arg1) {
#ifdef DEBUG
    std::cerr << "text change2: " << arg1.toStdString() << std::endl;
#endif
    buttonBox->button(QDialogButtonBox::Ok)->setEnabled(check());
}

void SettingRangeDialog::on_lineEdit_3_textChanged(const QString &arg1) {
#ifdef DEBUG
    std::cerr << "text changed3: " << arg1.toStdString() << std::endl;
#endif
    buttonBox->button(QDialogButtonBox::Ok)->setEnabled(check());
}

void SettingRangeDialog::on_lineEdit_4_textChanged(const QString &arg1) {
#ifdef DEBUG
    std::cerr << "text changed4: " << arg1.toStdString() << std::endl;
#endif
    buttonBox->button(QDialogButtonBox::Ok)->setEnabled(check());
}
