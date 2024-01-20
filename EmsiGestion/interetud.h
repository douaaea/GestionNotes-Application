#ifndef INTERETUD_H
#define INTERETUD_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class InterEtud;
}

class InterEtud : public QDialog
{
    Q_OBJECT

public:
    explicit InterEtud(QWidget *parent = nullptr);
    ~InterEtud();


private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::InterEtud *ui;
};

#endif // INTERETUD_H
