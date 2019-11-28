#ifndef BUS_H
#define BUS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class bus
{
public:
    bus();
       bool ajouter_bus();
    bus(int,QString,QString,QString,QString);
    void initialiser();
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficher_tri();
    QSqlQueryModel * afficher_tri_temps();
    QSqlQueryModel * rechercher(int);
QSqlQueryModel * afficher_serie();
QSqlQueryModel * rechercher_etat(QString);

    bool supprimer(int);
    void chercher(int);
    int get_serie();
    QString get_maison();
    QString get_etat();
    QString get_destination();
    QString get_temps_de_depart();
    void set_destination(QString destination){
        this->destination=destination;
    }

    void set_maison(QString maison){
        this->maison=maison;
    }
    QSqlQueryModel * afficher_etat();

    QSqlQueryModel * afficher_maison();
    void set_etat(QString etat){
        this->etat=etat;}
    bool modifier();

private:
    int serie;
    QString maison,etat,destination,temps_de_depart;


};

#endif // BUS_H
