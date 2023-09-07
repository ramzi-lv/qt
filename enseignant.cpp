#include "enseignant.h"

#include "gestion_enseignant.h"
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QtDebug>
#include <QObject>
#include<QDate>
#include<QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>

Enseignant::Enseignant()
{

}

Enseignant::Enseignant(QString cin,QString nom,QString prenom,QString matiere,QString salaire)
{this->cin=cin;
    this->nom = nom;
    this->prenom = prenom;
    this->matiere = matiere;
    this->salaire = salaire;


}

  QString Enseignant::getcin(){return cin;}
  QString Enseignant::getnom(){return nom;}
  QString Enseignant::getprenom(){return prenom;}
  QString Enseignant::getmatiere(){return matiere;}
  QString Enseignant::getsalaire(){return salaire;}

  void Enseignant::setcin(QString cin){this->cin=cin;}
  void Enseignant::setnom(QString nom){this->nom=nom;}
  void Enseignant::setprenom(QString prenom){this->prenom=prenom;}
  void Enseignant::setmatiere(QString matiere){this->matiere=matiere;}
  void Enseignant::setsalaire(QString salaire ){this->salaire=salaire;}



bool Enseignant::ajouter()
{

    QSqlQuery query;

    query.prepare("INSERT INTO Enseignant (cin,nom,prenom,matiere,salaire)"
                  "values(:cin,:nom,:prenom,:matiere,:salaire)");
    query.bindValue(":cin",cin);
        query.bindValue(":nom",nom);
         query.bindValue(":prenom",prenom);
         query.bindValue(":matiere",matiere);
         query.bindValue(":salaire",salaire);

          return query.exec();

   };



QSqlQueryModel * Enseignant::afficher(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from Enseignant");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("matiere"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("salaire"));


    return model;
}

bool Enseignant::supprimer(QString cin)
{
    QSqlQuery query;
         QString res=cin;
         query.prepare("Delete from Enseignant where cin=:cin");
         query.bindValue(":cin",res);
         return query.exec();
}

bool Enseignant::modifier(QString cin)
{
QSqlQuery query;
        QString res= cin;

        query.prepare("UPDATE Enseignant SET cin=:cin,nom=:nom,prenom=:prenom,matiere=:matiere,salaire=:salaire where cin=:cin");

        query.bindValue(":cin", cin);
        query.bindValue(":nom",nom);
         query.bindValue(":prenom",prenom);
         query.bindValue(":matiere",matiere);
         query.bindValue(":salaire",salaire);
        return    query.exec();
}

QSqlQueryModel* Enseignant::rechercher(QString a)
{
    QSqlQueryModel * query=new QSqlQueryModel();
    query->setQuery("select * from Enseignant where (nom like '%"+a+"%' or nom like '"+a+"%' or  nom like '%"+a+"' or prenom like '%"+a+"%' or prenom like '"+a+"%' or  prenom like '%"+a+"'or cin like '%"+a+"%' or cin like '"+a+"%' or  cin like '%"+a+"') ");



    query->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
    query->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    query->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    query->setHeaderData(3,Qt::Horizontal,QObject::tr("matiere"));
    query->setHeaderData(4,Qt::Horizontal,QObject::tr("salaire"));
    return query;
}
QSqlQueryModel *Enseignant::trier(QString x)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    qDebug()<<x<<endl;

    if(x=="nom (A->Z)")
        model->setQuery("select*  from Enseignant order by nom");
    else if(x=="prenom (A->Z)")
        model->setQuery("select*  from Enseignant order by prenom");
    else if (x=="cin (des)")
        model->setQuery("select*  from Enseignant order by cin");
    else if (x=="Default")
            model->setQuery("select * from Enseignant");


    model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("matiere"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("salaire"));
        return model;
}
