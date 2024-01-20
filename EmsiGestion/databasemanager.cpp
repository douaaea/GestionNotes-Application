#include "databasemanager.h"
#include "ui_databasemanager.h"


DatabaseManager::DatabaseManager() {}

DatabaseManager::DatabaseManager(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DatabaseManager)
{
    ui->setupUi(this);
}

DatabaseManager::~DatabaseManager()
{    closeDatabase();
    delete ui;
}
bool DatabaseManager::openDatabase(const QString& path) {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);

    if (!db.open()) {
        qDebug() << "Error: Could not open database.";
        return false;
    }

    return true;
}

void DatabaseManager::closeDatabase() {
    if (db.isOpen()) {
        db.close();
    }
}


