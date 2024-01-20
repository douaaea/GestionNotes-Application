#include "msg.h"
#include "ui_msg.h"
#include <QSqlQuery>

msg::msg(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::msg)
{
    ui->setupUi(this);
}

msg::~msg()
{
    delete ui;
}
msg::msg(QString& message, int numEtudiant, int codeCours)
    :  message(message), numEtudiant(numEtudiant),codeCours(codeCours) {}


int msg::getCours() const {
    return codeCours;
}

QString msg::getMessage() const {
    return message;
}

int msg::getEtudiant() const {
    return numEtudiant;
}

bool msg::insertMsg(QString& message, int numEtudiant, int codeCours) {

    QSqlQuery QueryInsertData;
    QueryInsertData.prepare("INSERT INTO msg (id,message,numEtudiant,codeCours) "
                  "VALUES (:id, :message, :etudiant,:cours)");
    QueryInsertData.bindValue(":message", message);
    QueryInsertData.bindValue(":etudiant", numEtudiant);
     QueryInsertData.bindValue(":cours", codeCours);

    if (QueryInsertData.exec()) {
        qDebug() << "msg enregistré avec succès.";


        return true;
    } else {
        qDebug() << "Erreur lors de l'enregistrement du msg:" << QueryInsertData.lastError().text();
        return false;
    }

}
