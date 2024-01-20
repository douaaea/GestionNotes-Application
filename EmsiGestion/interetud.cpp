#include "interetud.h"
#include "ui_interetud.h"
#include "consultdialog.h"
#include "msgdialog.h"


InterEtud::InterEtud(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::InterEtud)
{
    ui->setupUi(this);
}

InterEtud::~InterEtud()
{
    delete ui;
}




void InterEtud::on_pushButton_3_clicked()
{
    consultDialog c;
    c.setModal(true);
    c.exec();
}


void InterEtud::on_pushButton_2_clicked()
{
    msgDialog m;
    m.setModal(true);
    m.exec();
}

