#include "coursdialog.h"
#include "ui_coursdialog.h"

coursDialog::coursDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::coursDialog)
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

coursDialog::~coursDialog()
{
    delete ui;
}

void coursDialog::on_pushButton_clicked()
{     DB_connection.open();
    QSqlDatabase::database().transaction();
    int codeCours = ui->lineEdit->text().toInt();
    QString titre = ui->lineEdit_2->text();
    int idEnseignant = ui->lineEdit_3->text().toInt();

    // Create Enseignant object
    cours cou(codeCours, titre, idEnseignant);

    // Insert into database
    cou.insertCours(codeCours, titre, idEnseignant);
    QSqlDatabase::database().commit();
    DB_connection.close();
}

