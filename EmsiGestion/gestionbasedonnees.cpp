#include "gestionbasedonnees.h"
#include "ui_gestionbasedonnees.h"

GestionBaseDonnees::GestionBaseDonnees(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GestionBaseDonnees)
{
    ui->setupUi(this);
}

GestionBaseDonnees::~GestionBaseDonnees()
{
    delete ui;
}
