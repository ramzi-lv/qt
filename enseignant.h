#ifndef ETABLISSEMENT_H
#define ETABLISSEMENT_H

#include <QDialog>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMainWindow>
#include <QMainWindow>
#include <QMainWindow>
#include <QFileDialog>
#include <QPixmap>
#include <QSqlQuery>
#include <QDateTime>
#include <QFile>
#include <QDebug>


class Enseignant
{
    public:
        Enseignant();
        Enseignant(QString,QString,QString,QString,QString);

//getters
        QString getcin();
        QString getnom();
        QString getprenom();
        QString getmatiere();
        QString getsalaire();


        void setcin(QString);
        void setnom(QString);
        void setprenom(QString );
        void setmatiere(QString);
        void setsalaire(QString );


        bool ajouter();
        QSqlQueryModel * afficher();
        bool supprimer(QString);
        bool modifier(QString);

        QSqlQueryModel *rechercher(QString);
        QSqlQueryModel *trier(QString);

private:
        QString cin,nom,prenom,matiere,salaire;


};



#endif // ETABLISSEMENT_H
