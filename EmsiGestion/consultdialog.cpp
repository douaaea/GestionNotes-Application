#include "consultdialog.h"
#include "ui_consultdialog.h"

consultDialog::consultDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::consultDialog)
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

consultDialog::~consultDialog()
{
    delete ui;
}

void consultDialog::on_pushButton_clicked()
{
    DB_connection.open();
    QSqlDatabase::database().transaction();

    QSqlQuery query;
    query.prepare("SELECT * FROM Note WHERE numEtudiant = :numEtudiant");
    query.bindValue(":numEtudiant", ui->lineEdit->text().toInt());
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

