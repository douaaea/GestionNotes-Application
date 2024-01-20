#include "cours.h"
#include "ui_cours.h"
#include <QSqlQuery>


cours::cours(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::cours)
{
    ui->setupUi(this);

}

cours::~cours()
{
    delete ui;
}

cours::cours(const int codeCours, const QString& titre, const int enseignantResponsable)
    : codeCours(codeCours), titre(titre), enseignantResponsable(enseignantResponsable) {}

int cours::getCodeCours() const {
    return codeCours;
}

QString cours::getTitre() const {
    return titre;
}

int cours::getEnseignantResponsable() const {
    return enseignantResponsable;
}

bool cours::insertCours(const int codeCours, const QString& titre, const int enseignantResponsable) {

    QSqlQuery QueryInsertData;
    QueryInsertData.prepare("INSERT INTO Cours (codeCours, titre, idEnseignant) "
                  "VALUES (:code, :titre, :enseignant)");
    QueryInsertData.bindValue(":code", codeCours);
    QueryInsertData.bindValue(":titre", titre);
    QueryInsertData.bindValue(":enseignant", enseignantResponsable);

    if (QueryInsertData.exec()) {
        qDebug() << "Cours enregistré avec succès.";


        return true;
    } else {
        qDebug() << "Erreur lors de l'enregistrement du cours:" << QueryInsertData.lastError().text();
        return false;
    }

}



