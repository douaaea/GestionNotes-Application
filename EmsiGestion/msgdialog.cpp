#include "msgdialog.h"
#include "ui_msgdialog.h"

msgDialog::msgDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::msgDialog)
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

msgDialog::~msgDialog()
{
    delete ui;
}

void msgDialog::on_pushButton_clicked()
{
    DB_connection.open();
    QSqlDatabase::database().transaction();

    QSqlQuery query;
    query.prepare("SELECT * FROM msg WHERE numEtudiant = :numEtudiant");
    query.bindValue(":numEtudiant", ui->lineEdit->text().toInt());
    int nbrRows=30;
    if(query.exec()){
        ui->tableWidget->setRowCount(nbrRows);
        int rowNumber=0;
        while(query.next()){
            ui->tableWidget->setItem(rowNumber,0,new QTableWidgetItem(QString(query.value("numEtudiant").toString())));
            ui->tableWidget->setItem(rowNumber,1,new QTableWidgetItem(QString(query.value("codeCours").toString())));
            ui->tableWidget->setItem(rowNumber,2,new QTableWidgetItem(QString(query.value("message").toString())));
            rowNumber=rowNumber+1;
        }
    }
    QSqlDatabase::database().commit();
    DB_connection.close();
}

