#ifndef BASEDONNES_H
#define BASEDONNES_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>
#include <QVariantList>
#include <QSqlRecord>
#include <QtSql>

class GestionBaseDonnees{
private:
    QSqlDatabase m_db;

public:
    GestionBaseDonnees() {
        m_db = QSqlDatabase::addDatabase("QSQLITE");
        m_db.setDatabaseName("C:\\Users\\Hp\\Desktop\\approject\\DBapp.db");
        if (!m_db.open()) {
            qDebug() << "Error opening database:" << m_db.lastError().text();
        } else {
            qDebug() << "Database connected!";
        }
    }

    ~GestionBaseDonnees() {
        m_db.close();
    }





};

#endif // BASEDONNES_H
