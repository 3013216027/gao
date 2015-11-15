#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QDialog>

#include "ui_inputdialog.h"

namespace Ui {
class InputDialog;
}

class InputDialog : public QDialog, public Ui::InputDialog
{
    Q_OBJECT

public:
    explicit InputDialog(QWidget *parent = 0);

private slots:

private:
    Ui::InputDialog *ui;
};

#endif // INPUTDIALOG_H
