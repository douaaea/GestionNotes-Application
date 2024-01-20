#include "note.h"
#include "ui_note.h"
#include <QSqlQuery>

note::note(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::note)
{
    ui->setupUi(this);
    DB_connection = QSqlDatabase::addDatabase("QSQLITE");
    DB_connection.setDatabaseName("C:\\Users\\Hp\\Desktop\\approject\\DBapp.db");
    if (!DB_connection.open()) {
        qDebug() << "Error opening database:" <<DB_connection.lastError().text();
    } else {
        qDebug() << "Database connected!";
    }
}

note::~note()
{
    delete ui;
}

note::note(const int etudiantAssocie, const int coursAssocie, float noteObtenue, const QString& dateEvaluation)
    : etudiantAssocie(etudiantAssocie), coursAssocie(coursAssocie), noteObtenue(noteObtenue), dateEvaluation(dateEvaluation) {}

int note::getEtudiantAssocie() const {
    return etudiantAssocie;
}


int note::getCoursAssocie() const {
    return coursAssocie;
}

float note::getNoteObtenue() const {
    return noteObtenue;
}

QString note::getDateEvaluation() const {
    return dateEvaluation;
}

bool note::insertIntoDatabase(const int etudiantAssocie, const int coursAssocie, float noteObtenue, const QString& dateEvaluation) {

    QSqlQuery QueryInsertData;
    QueryInsertData.prepare("INSERT INTO Note (numEtudiant, codeCours, noteObtenue, dateEvaluation) "
                  "VALUES (:numEtudiant, :codeCours, :noteObtenue, :dateEvaluation)");
    QueryInsertData.bindValue(":numEtudiant", etudiantAssocie);
    QueryInsertData.bindValue(":codeCours", coursAssocie);
    QueryInsertData.bindValue(":noteObtenue", noteObtenue);
    QueryInsertData.bindValue(":dateEvaluation", dateEvaluation);


    if (QueryInsertData.exec()) {
        qDebug() << "NOTE enregistré avec succès.";



        return true;
    } else {
        qDebug() << "Erreur lors de l'enregistrement du note:" << QueryInsertData.lastError().text();
        return false;
    }


}

bool note::updateInDatabase(int etudiantAssocie,  int coursAssocie, float noteObtenue, const QString& dateEvaluation) {
    QSqlQuery query;
    query.prepare("UPDATE Note SET noteObtenue = :noteObtenue, dateEvaluation = :dateEvaluation "
                  "WHERE numEtudiant = :numEtudiant AND codeCours = :codeCours");
    query.bindValue(":numEtudiant", etudiantAssocie);
    query.bindValue(":codeCours", coursAssocie);
    query.bindValue(":noteObtenue", noteObtenue);
    query.bindValue(":dateEvaluation", dateEvaluation);

    return query.exec();
}

bool note::deleteFromDatabase( int etudiantAssocie, int coursAssocie) {

    QSqlQuery query;
    query.prepare("DELETE FROM Note WHERE numEtudiant = :numEtudiant AND codeCours = :codeCours");
    query.bindValue(":numEtudiant", etudiantAssocie);
    query.bindValue(":codeCours", coursAssocie);

    return query.exec();
}





