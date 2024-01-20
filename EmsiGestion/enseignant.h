#ifndef ENSEIGNANT_H
#define ENSEIGNANT_H
#include <QDialog>
#include <QString>
#include <QDebug>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>


namespace Ui {
class Enseignant;
}

class Enseignant : public QDialog
{
    Q_OBJECT

public:
    explicit Enseignant(QWidget *parent = nullptr);
    Enseignant(int identifiant, const QString& nom, const QString& prenom);

    int getIdentifiant() const;
    QString getNom() const;
    QString getPrenom() const;

    // Database operations
    bool insertIntoDatabase(int identifiant, const QString& nom, const QString& prenom);

    ~Enseignant();

private:
    Ui::Enseignant *ui;
    int identifiant;
    QString nom;
    QString prenom;

};

#endif // ENSEIGNANT_H
