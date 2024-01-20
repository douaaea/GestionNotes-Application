#ifndef COURS_H
#define COURS_H

#include <QDialog>
#include <QString>
#include <QDebug>
#include <QtSql>

namespace Ui {
class cours;
}

class cours : public QDialog
{
    Q_OBJECT

public:
    explicit cours(QWidget *parent = nullptr);

    cours(const int codeCours, const QString& titre, const int enseignantResponsable);

    int getCodeCours() const;
    QString getTitre() const;
    int getEnseignantResponsable() const;

    // Database operations
    bool insertCours(const int codeCours, const QString& titre, const int enseignantResponsable);


    ~cours();

private:
    Ui::cours *ui;
    int codeCours;
    QString titre;
    int enseignantResponsable;


};

#endif // COURS_H
