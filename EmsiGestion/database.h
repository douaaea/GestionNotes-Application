#ifndef DATABASE_H
#define DATABASE_H

#include <QDialog>
#include <QtSql>
#include <QString>

namespace Ui {
class database;
}

class database : public QDialog
{
    Q_OBJECT

public:
    DatabaseManager();
    ~DatabaseManager();

    bool openDatabase(const QString& path);
    void closeDatabase();
    bool createTables();

private:
    QSqlDatabase db;

public:
    explicit database(QWidget *parent = nullptr);
    ~database();

private:
    Ui::database *ui;
};

#endif // DATABASE_H
