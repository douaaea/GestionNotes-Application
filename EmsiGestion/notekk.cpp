#include "notekk.h"
#include "ui_note.h"

Note::Note(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Note)
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

Note::~Note()
{
    delete ui;
}

void Note::on_pushButton_clicked()
{

    DB_Connection.open();
    QSqlDatabase::database().transaction();

    QSqlQuery QueryInsertData(DB_Connection);
    QueryInsertData.prepare("INSERT INTO Note(numEtudiant,codeCours,noteObtenue,dateEvaluation) VALUES(:numEtudiant, :codeCours, :noteObtenue, :dateEvaluation)");
    QueryInsertData.bindValue(":numEtudiant",ui->lineEdit->text());
    QueryInsertData.bindValue(":codeCours",ui->lineEdit_2->text());
    QueryInsertData.bindValue(":noteObtenue",ui->lineEdit_3->text());
    QueryInsertData.bindValue(":dateEvaluation",ui->dateEdit->currentSection());

    QueryInsertData.exec();

    qDebug()<<"error:"<<ui->dateEdit->currentSection();


    QSqlDatabase::database().commit();
    DB_Connection.close();
}

