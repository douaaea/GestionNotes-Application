#ifndef CONSULTDIALOG_H
#define CONSULTDIALOG_H

#include <QDialog>
#include <QtSql>
#include "note.h"

namespace Ui {
class consultDialog;
}

class consultDialog : public QDialog
{
    Q_OBJECT

public:
    explicit consultDialog(QWidget *parent = nullptr);
    ~consultDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::consultDialog *ui;
       QSqlDatabase DB_connection;
};

#endif // CONSULTDIALOG_H
