#include "etudiantdialog.h"
#include "ui_etudiantdialog.h"

etudiantDialog::etudiantDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::etudiantDialog)
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

etudiantDialog::~etudiantDialog()
{
    delete ui;
}

void etudiantDialog::on_pushButton_clicked()
{    DB_connection.open();
    QSqlDatabase::database().transaction();
    int numeroEtudiant = ui->lineEdit->text().toInt();
    QString nom = ui->lineEdit_2->text();
    QString prenom = ui->lineEdit_3->text();
    QString specialite = ui->comboBox->currentText();

    // Create Etudiant object
    Etudiant etudiant(numeroEtudiant, nom, prenom, specialite);

    // Insert into database
    etudiant.insertIntoDatabase(numeroEtudiant, nom, prenom, specialite);
    QSqlDatabase::database().commit();
    DB_connection.close();
}

