#ifndef ENSEIGNANTDIALOG_H
#define ENSEIGNANTDIALOG_H

#include <QDialog>
#include "enseignant.h"
#include <QtSql>

namespace Ui {
class enseignantDialog;
}

class enseignantDialog : public QDialog
{
    Q_OBJECT

public:
    explicit enseignantDialog(QWidget *parent = nullptr);
    ~enseignantDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::enseignantDialog *ui;
       QSqlDatabase DB_connection;
};

#endif // ENSEIGNANTDIALOG_H
