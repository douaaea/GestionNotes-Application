#ifndef ENSEIGNANTOL_H
#define ENSEIGNANTOL_H

#include <QDialog>
#include <QtSql>
#include <QDebug>

namespace Ui {
class Enseignant;
}

class Enseignant : public QDialog
{
    Q_OBJECT

public:
    explicit Enseignant(QWidget *parent = nullptr);
    ~Enseignant();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Enseignant *ui;
    QSqlDatabase DB_Connection;
};

#endif // ENSEIGNANTOL_H
