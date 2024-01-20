#include "enseignant.h"
#include "ui_enseignant.h"
#include <QSqlQuery>

Enseignant::Enseignant(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Enseignant)
{
    ui->setupUi(this);

}

Enseignant::~Enseignant()
{
    delete ui;
}


Enseignant::Enseignant(int identifiant, const QString& nom, const QString& prenom)
    : identifiant(identifiant), nom(nom), prenom(prenom) {}

int Enseignant::getIdentifiant() const {
    return identifiant;
}

QString Enseignant::getNom() const {
    return nom;
}

QString Enseignant::getPrenom() const {
    return prenom;
}

bool Enseignant::insertIntoDatabase(int identifiant, const QString& nom, const QString& prenom) {

    QSqlQuery QueryInsertData;
    QueryInsertData.prepare("INSERT INTO Enseignant (idEns, nom, prenom) "
                  "VALUES (:identifiant, :nom, :prenom)");
    QueryInsertData.bindValue(":identifiant", identifiant);
    QueryInsertData.bindValue(":nom", nom);
    QueryInsertData.bindValue(":prenom", prenom);

    if (QueryInsertData.exec()) {
        qDebug() << "Enseignant enregistré avec succès.";


        return true;
    } else {
        qDebug() << "Erreur lors de l'enregistrement de l enseignant:" << QueryInsertData.lastError().text();
        return false;
    }

}

