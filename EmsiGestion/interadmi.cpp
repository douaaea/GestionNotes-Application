#include "interadmi.h"
#include "ui_interadmi.h"
#include "etudiantdialog.h"
#include "cours.h"
#include "enseignantdialog.h"
#include "validation.h"
#include "note.h"
#include "coursdialog.h"

interAdmi::interAdmi(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::interAdmi)
{
    ui->setupUi(this);
}

interAdmi::~interAdmi()
{
    delete ui;
}




void interAdmi::on_pushButton_clicked()
{
    etudiantDialog etd;
    etd.setModal(true);
    etd.exec();
}


void interAdmi::on_pushButton_2_clicked()
{
    coursDialog c;
    c.setModal(true);
    c.exec();
}


void interAdmi::on_pushButton_3_clicked()
{
    enseignantDialog ens;
    ens.setModal(true);
    ens.exec();
}


void interAdmi::on_pushButton_5_clicked()
{
    validation n;
    n.setModal(true);
    n.exec();
}




