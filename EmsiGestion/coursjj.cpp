#include "cours.h"
#include "ui_cours.h"

Cours::Cours(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Cours)
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

Cours::~Cours()
{
    delete ui;
}

void Cours::on_pushButton_clicked()
{
    DB_Connection.open();
    QSqlDatabase::database().transaction();

    QSqlQuery QueryInsertData(DB_Connection);
    QueryInsertData.prepare("INSERT INTO Cours(codeCours,titre,idEnseignant) VALUES(:codeCours, :titre, :idEnseignant)");
    QueryInsertData.bindValue(":codeCours",ui->lineEdit->text());
    QueryInsertData.bindValue(":titre",ui->lineEdit_2->text());
    QueryInsertData.bindValue(":idEnseignant",ui->lineEdit_3->text());
    QueryInsertData.exec();



    QSqlDatabase::database().commit();
    DB_Connection.close();
}

