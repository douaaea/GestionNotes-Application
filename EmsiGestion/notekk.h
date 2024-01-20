#ifndef NOTEKK_H
#define NOTEKK_H

#include <QDialog>
#include <QtSql>
#include <QDebug>
namespace Ui {
class Note;
}

class Note : public QDialog
{
    Q_OBJECT

public:
    explicit Note(QWidget *parent = nullptr);
    ~Note();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Note *ui;
    QSqlDatabase DB_Connection;
};

#endif // NOTEKK_H
