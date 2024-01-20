#ifndef COURSJJ_H
#define COURSJJ_H

#include <QDialog>
#include <QtSql>
#include <QDebug>
namespace Ui {
class Cours;
}

class Cours : public QDialog
{
    Q_OBJECT

public:
    explicit Cours(QWidget *parent = nullptr);
    ~Cours();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Cours *ui;
    QSqlDatabase DB_Connection;
};

#endif // COURSJJ_H
