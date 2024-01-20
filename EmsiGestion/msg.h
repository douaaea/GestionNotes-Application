#ifndef MSG_H
#define MSG_H

#include <QDialog>
#include <QString>
#include <QDebug>
#include <QtSql>


namespace Ui {
class msg;
}

class msg : public QDialog
{
    Q_OBJECT

public:
    explicit msg(QWidget *parent = nullptr);
    msg( QString& message, int numEtudiant, int codeCours);

    int getCours() const;
    int getid() const;
    QString getMessage() const;
    int getEtudiant() const;
  bool insertMsg(QString& message, int numEtudiant, int codeCours);
  ~msg();

private:
    Ui::msg *ui;
    int id;
    QString message;
    int numEtudiant;
    int codeCours;

};

#endif // MSG_H
