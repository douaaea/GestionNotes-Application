#ifndef ETUDIANT_H
#define ETUDIANT_H

#include <QDialog>
#include <QDebug>
#include <QString>
#include <QtSql>

namespace Ui {
class Etudiant;
}

class Etudiant : public QDialog
{
    Q_OBJECT

public:
    explicit Etudiant(QWidget *parent = nullptr);

    Etudiant(int numeroEtudiant, const QString& nom, const QString& prenom, const QString& specialite);

    int getNumeroEtudiant() const;
    QString getNom() const;
    QString getPrenom() const;
    QString getSpecialite() const;

    // Database operations
    bool insertIntoDatabase(int numeroEtudiant, const QString& nom, const QString& prenom, const QString& specialite);

    ~Etudiant();

private:
    Ui::Etudiant *ui;
    int numeroEtudiant;
    QString nom;
    QString prenom;
    QString specialite;


};

#endif // ETUDIANT_H
