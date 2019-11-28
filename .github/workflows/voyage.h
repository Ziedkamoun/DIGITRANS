#ifndef VOYAGE_H
#define VOYAGE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class voyage
{
public:

    voyage();
    bool ajouter_voyage();
    voyage(int,QString,QString);
    void initialiser();
    QSqlQueryModel * afficher();
     bool supprimer(int);
     bool modifier();
     QSqlQueryModel * afficher_voyage();
     QSqlQueryModel * afficher_tri();
     QSqlQueryModel * afficher_destination();
     QString get_destination();
     QSqlQueryModel * rechercher(int);
     void set_destination(QString destination){
         this->destination=destination;}
     QSqlQueryModel * afficher_destination_select();


private:
int id;
QString temps_de_depart,destination;
};




#endif // VOYAGE_H
