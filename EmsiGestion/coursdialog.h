#ifndef COURSDIALOG_H
#define COURSDIALOG_H
#include "cours.h"
#include <QDialog>
#include <QtSql>
namespace Ui {
class coursDialog;
}

class coursDialog : public QDialog
{
    Q_OBJECT

public:
    explicit coursDialog(QWidget *parent = nullptr);
    ~coursDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::coursDialog *ui;
      QSqlDatabase DB_connection;
};

#endif // COURSDIALOG_H
