#ifndef ETUDIANTDIALOG_H
#define ETUDIANTDIALOG_H

#include <QDialog>
#include "etudiant.h"
#include <QtSql>


namespace Ui {
class etudiantDialog;
}

class etudiantDialog : public QDialog
{
    Q_OBJECT

public:
    explicit etudiantDialog(QWidget *parent = nullptr);
    ~etudiantDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::etudiantDialog *ui;
      QSqlDatabase DB_connection;
};

#endif // ETUDIANTDIALOG_H
