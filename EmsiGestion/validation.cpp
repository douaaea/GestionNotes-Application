#include "validation.h"
#include "ui_validation.h"
#include "msg.h"

validation::validation(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::validation)
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

validation::~validation()
{
    delete ui;
}

void validation::on_pushButton_2_clicked()
{      DB_connection.open();
    QSqlDatabase::database().transaction();
    int etudiantAssocie = ui->lineEdit->text().toInt();
    int coursAssocie = ui->lineEdit_2->text().toInt();
    float noteObtenue = ui->lineEdit_3->text().toFloat();
    QString dateEvaluation = ui->dateEdit->date().toString();

    // Create note object
    note No(etudiantAssocie,coursAssocie,noteObtenue,dateEvaluation);

    // Insert into database
    No.insertIntoDatabase(etudiantAssocie,coursAssocie,noteObtenue,dateEvaluation);

        QString message = "nouvelle note ajoutee ! Consulter votre notes.";

        msg M(message,etudiantAssocie,coursAssocie);

        // Insert into database
        M.insertMsg(message,etudiantAssocie,coursAssocie);



     QSqlDatabase::database().commit();
        DB_connection.close();


}


void validation::on_pushButton_3_clicked()
{     DB_connection.open();
    QSqlDatabase::database().transaction();
    int etudiantAssocie = ui->lineEdit->text().toInt();
    int coursAssocie = ui->lineEdit_2->text().toInt();
    float noteObtenue = ui->lineEdit_3->text().toFloat();
    QString dateEvaluation = ui->dateEdit->date().toString();


    note No(etudiantAssocie,coursAssocie,noteObtenue,dateEvaluation);



    No.updateInDatabase(etudiantAssocie,coursAssocie,noteObtenue,dateEvaluation);
    QSqlDatabase::database().commit();
    DB_connection.close();

}


void validation::on_pushButton_4_clicked()
{     DB_connection.open();
    QSqlDatabase::database().transaction();
    int etudiantAssocie = ui->lineEdit->text().toInt();
    int coursAssocie = ui->lineEdit_2->text().toInt();
    float noteObtenue = ui->lineEdit_3->text().toFloat();
    QString dateEvaluation = ui->dateEdit->date().toString();


    // Create note object
    note No(etudiantAssocie,coursAssocie,noteObtenue,dateEvaluation);



    No.deleteFromDatabase(etudiantAssocie,coursAssocie);
    QSqlDatabase::database().commit();
    DB_connection.close();
}


void validation::on_pushButton_clicked()
{
    DB_connection.open();
    QSqlDatabase::database().transaction();

    QSqlQuery query;
    query.prepare("SELECT * FROM Note");
    int nbrRows=30;
    if(query.exec()){
        ui->tableWidget->setRowCount(nbrRows);
        int rowNumber=0;
        while(query.next()){
            ui->tableWidget->setItem(rowNumber,0,new QTableWidgetItem(QString(query.value("numEtudiant").toString())));
             ui->tableWidget->setItem(rowNumber,1,new QTableWidgetItem(QString(query.value("codeCours").toString())));
             ui->tableWidget->setItem(rowNumber,2,new QTableWidgetItem(QString(query.value("noteObtenue").toString())));
              ui->tableWidget->setItem(rowNumber,3,new QTableWidgetItem(QString(query.value("dateEvaluation").toString())));
                rowNumber=rowNumber+1;
        }
    }
    QSqlDatabase::database().commit();
    DB_connection.close();
}

