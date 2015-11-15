#include "inputdialog.h"
#include "ui_inputdialog.h"

InputDialog::InputDialog(QWidget *parent) : QDialog(parent)
{
    setupUi(this);
    setWindowTitle(QString::fromUtf8("输入点坐标"));
}
