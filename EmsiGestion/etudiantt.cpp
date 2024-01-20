#include "etudiantt.h"
#include "ui_etudiantt.h"

Etudiantt::Etudiantt(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Etudiantt)
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

Etudiantt::~Etudiantt()
{
    delete ui;
}

void Etudiantt::on_pushButton_clicked()
{
    DB_Connection.open();
    QSqlDatabase::database().transaction();

    QSqlQuery QueryInsertData(DB_Connection);
    QueryInsertData.prepare("INSERT INTO Etudiant(numEtudiant,nom,prenom,specialite) VALUES(:numEtudiant, :nom, :prenom, :specialite)");
    QueryInsertData.bindValue(":numEtudiant",ui->lineEdit->text());
    QueryInsertData.bindValue(":nom",ui->lineEdit_2->text());
    QueryInsertData.bindValue(":prenom",ui->lineEdit_3->text());
    QueryInsertData.bindValue(":specialite",ui->comboBox->currentText());

    QueryInsertData.exec();



    QSqlDatabase::database().commit();
    DB_Connection.close();
}

