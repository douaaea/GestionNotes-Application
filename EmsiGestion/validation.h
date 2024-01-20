#ifndef VALIDATION_H
#define VALIDATION_H

#include <QDialog>
#include <QtSql>
#include "note.h"

namespace Ui {
class validation;
}

class validation : public QDialog
{
    Q_OBJECT

public:
    explicit validation(QWidget *parent = nullptr);
    ~validation();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();


private:
    Ui::validation *ui;
       QSqlDatabase DB_connection;

};

#endif // VALIDATION_H
