#include "enseignantol.h"
#include "ui_enseignant.h"

Enseignant::Enseignant(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Enseignant)
{
    ui->setupUi(this);
    DB_Connection = QSqlDatabase::addDatabase("QSQLITE");
    DB_Connection .setDatabaseName("C:\\Users\\Hp\\Desktop\\approject\\DBapp.db");
    if(DB_Connection.open()){
        qDebug()<<"Database is Connected";
    }
    else{
        qDebug() <<"Database is Not Connected";
        qDebug() <<"Error:"<<DB_Connection.lastError();
    }
}

Enseignant::~Enseignant()
{
    delete ui;
}

void Enseignant::on_pushButton_clicked()
{
    DB_Connection.open();
    QSqlDatabase::database().transaction();

    QSqlQuery QueryInsertData(DB_Connection);
    QueryInsertData.prepare("INSERT INTO Enseignant(idEns,nom,prenom) VALUES(:idEns, :nom, :prenom)");
    QueryInsertData.bindValue(":numEtudiant",ui->lineEdit->text());
    QueryInsertData.bindValue(":nom",ui->lineEdit_2->text());
    QueryInsertData.bindValue(":prenom",ui->lineEdit_3->text());


    QueryInsertData.exec();



    QSqlDatabase::database().commit();
    DB_Connection.close();
}

