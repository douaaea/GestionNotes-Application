#ifndef INTERADMI_H
#define INTERADMI_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class interAdmi;
}

class interAdmi : public QDialog
{
    Q_OBJECT

public:
    explicit interAdmi(QWidget *parent = nullptr);
    ~interAdmi();



private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::interAdmi *ui;
};

#endif // INTERADMI_H
