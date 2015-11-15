#ifndef SETTINGRANGEDIALOG_H
#define SETTINGRANGEDIALOG_H

#include <QDialog>
#include "ui_settingrangedialog.h"

class SettingRangeDialog : public QDialog, public Ui::SettingRangeDialog
{
    Q_OBJECT

public:
    explicit SettingRangeDialog(QWidget *parent = 0);
private slots:
    void on_lineEdit_textChanged(const QString &arg1);
    void on_lineEdit_2_textChanged(const QString &arg1);
    void on_lineEdit_3_textChanged(const QString &arg1);
    void on_lineEdit_4_textChanged(const QString &arg1);

private:
    bool check();
};

#endif // SETTINGRANGEDIALOG_H
