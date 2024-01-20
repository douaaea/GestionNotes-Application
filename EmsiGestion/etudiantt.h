#ifndef ETUDIANTT_H
#define ETUDIANTT_H

#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QString>
namespace Ui {
class Etudiantt;
}

class Etudiantt : public QDialog
{
    Q_OBJECT

public:
    explicit Etudiantt(QWidget *parent = nullptr);
    ~Etudiantt();
    Etudiant();
    Etudiant(int numeroEtudiant, const QString& nom, const QString& prenom, const QString& specialite);

    int getNumeroEtudiant() const;
    QString getNom() const;
    QString getPrenom() const;
    QString getSpecialite() const;


private:
    Ui::Etudiantt *ui;
     QSqlDatabase DB_Connection;
};

#endif // ETUDIANTT_H
