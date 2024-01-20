#ifndef MSGDIALOG_H
#define MSGDIALOG_H

#include <QDialog>
#include <QtSql>
#include "note.h"

namespace Ui {
class msgDialog;
}

class msgDialog : public QDialog
{
    Q_OBJECT

public:
    explicit msgDialog(QWidget *parent = nullptr);
    ~msgDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::msgDialog *ui;
       QSqlDatabase DB_connection;
};

#endif // MSGDIALOG_H
