#include <QPushButton>
#include "settingnumberdialog.h"
#include "ui_settingnumberdialog.h"
//#include "clostpair.h"

SettingNumberDialog::SettingNumberDialog(QWidget *parent) : QDialog(parent) {
    setupUi(this);
    setWindowTitle(QString::fromUtf8("设置点数量"));
    buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);

    QRegExp regExp("[2-9]|[1-9][0-9]{1,4}");
    lineEdit->setValidator(new QRegExpValidator(regExp, this));

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
}

void SettingNumberDialog::on_lineEdit_textChanged() {
    buttonBox->button(QDialogButtonBox::Ok)->setEnabled(lineEdit->hasAcceptableInput());
}
