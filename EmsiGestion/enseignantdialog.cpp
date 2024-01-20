#include "enseignantdialog.h"
#include "ui_enseignantdialog.h"

enseignantDialog::enseignantDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::enseignantDialog)
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

enseignantDialog::~enseignantDialog()
{
    delete ui;
}

void enseignantDialog::on_pushButton_clicked()
{       DB_connection.open();
    QSqlDatabase::database().transaction();
    int identifiant = ui->lineEdit->text().toInt();
    QString nom = ui->lineEdit_2->text();
    QString prenom = ui->lineEdit_3->text();

    // Create Enseignant object
    Enseignant enseignant(identifiant, nom, prenom);

    // Insert into database
    enseignant.insertIntoDatabase(identifiant, nom, prenom);
    QSqlDatabase::database().commit();
    DB_connection.close();
}

