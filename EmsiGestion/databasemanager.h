#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QDialog>
#include <QtSql>
#include <QString>

namespace Ui {
class DatabaseManager;
}

class DatabaseManager : public QDialog
{
    Q_OBJECT

public:
    explicit DatabaseManager(QWidget *parent = nullptr);
    DatabaseManager();
    ~DatabaseManager();

    bool openDatabase(const QString& path);
    void closeDatabase();
    bool createTables();

private:
    Ui::DatabaseManager *ui;
    QSqlDatabase db;
};

#endif // DATABASEMANAGER_H
