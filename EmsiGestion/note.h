#ifndef NOTE_H
#define NOTE_H

#include <QDialog>
#include <QtSql>
#include <QString>
#include <QDebug>
#include "msg.h"


namespace Ui {
class note;
}

class note : public QDialog
{
    Q_OBJECT

public:
    explicit note(QWidget *parent = nullptr);
    note(int etudiantAssocie, int coursAssocie, float noteObtenue, const QString &dateEvaluation);

    int getEtudiantAssocie() const;
    int getCoursAssocie() const;
    float getNoteObtenue() const;
    QString getDateEvaluation() const;

    // Database operations
    bool insertIntoDatabase(int etudiantAssocie,  int coursAssocie, float noteObtenue, const QString& dateEvaluation);
    bool updateInDatabase( int etudiantAssocie, int coursAssocie, float noteObtenue, const QString& dateEvaluation);
    bool deleteFromDatabase( int etudiantAssocie, int coursAssocie);
    ~note();


private:
    Ui::note *ui;
    int etudiantAssocie;
    int coursAssocie;
    float noteObtenue;
    QString dateEvaluation;
    QSqlDatabase DB_connection;


};

#endif // NOTE_H
