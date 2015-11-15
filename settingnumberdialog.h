#ifndef SETTINGNUMBERDIALOG_H
#define SETTINGNUMBERDIALOG_H

#include <QDialog>
#include "ui_settingnumberdialog.h"

class MainWindow;

class SettingNumberDialog : public QDialog, public Ui::SettingNumberDialog
{
    Q_OBJECT

public:
    explicit SettingNumberDialog(QWidget *parent = 0);

private slots:
    void on_lineEdit_textChanged();
};

#endif // SETTINGNUMBERDIALOG_H
