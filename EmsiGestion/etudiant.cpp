#include "etudiant.h"
#include "ui_etudiant.h"
#include <QSqlQuery>

Etudiant::Etudiant(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Etudiant)
{
    ui->setupUi(this);
}

Etudiant::~Etudiant()
{
    delete ui;
}


Etudiant::Etudiant(int numeroEtudiant, const QString& nom, const QString& prenom, const QString& specialite)
    : numeroEtudiant(numeroEtudiant), nom(nom), prenom(prenom), specialite(specialite) {}

int Etudiant::getNumeroEtudiant() const {
    return numeroEtudiant;
}

QString Etudiant::getNom() const {
    return nom;
}

QString Etudiant::getPrenom() const {
    return prenom;
}

QString Etudiant::getSpecialite() const {
    return specialite;
}

bool Etudiant::insertIntoDatabase(int numeroEtudiant, const QString& nom, const QString& prenom, const QString& specialite) {

    QSqlQuery QueryInsertData;
    QueryInsertData.prepare("INSERT INTO Etudiant (numEtudiant, nom, prenom, specialite) "
                            "VALUES (:numero, :nom, :prenom, :specialite)");

    QueryInsertData.bindValue(":numero", numeroEtudiant);
    QueryInsertData.bindValue(":nom", nom);
    QueryInsertData.bindValue(":prenom", prenom);
    QueryInsertData.bindValue(":specialite", specialite);

    if (QueryInsertData.exec()) {
        qDebug() << "Etudiant enregistré avec succès.";
        return true;
    } else {
        qDebug() << "Erreur lors de l'enregistrement du etudiant :" << QueryInsertData.lastError().text();
        return false;
    }


}



