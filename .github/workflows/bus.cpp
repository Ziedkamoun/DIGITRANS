#include "bus.h"
#include <QString>
#include <QDebug>
#include "QMessageBox"

bus::bus()
{

}
bus::bus(int nv_serie, QString nv_maison, QString nv_etat, QString nv_destination, QString nv_temps_de_depart)
{
    serie=nv_serie;
    maison=nv_maison;
    etat=nv_etat;
    destination=nv_destination;
    temps_de_depart=nv_temps_de_depart;
}

bool bus::ajouter_bus()
{

    QSqlQuery query;
    query.prepare("INSERT INTO BUS(TEMPS_DE_DEPART,SERIE,MAISON,ETAT,DESTINATION)" "VALUES(:TEMPS_DE_DEPART,:SERIE,:MAISON,:ETAT,:DESTINATION)");
    query.bindValue(":SERIE",serie);
    query.bindValue(":MAISON",maison);
    query.bindValue(":ETAT",etat);
    query.bindValue(":DESTINATION",destination);
    query.bindValue(":TEMPS_DE_DEPART",temps_de_depart);
    return query.exec();

}
QSqlQueryModel * bus::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from bus");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("TEMPS_DE_DEPART"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("SERIE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("MAISON"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("ETAT"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DESTINATION"));

    return model;
}
QSqlQueryModel * bus::afficher_tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from bus order by serie");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("TEMPS_DE_DEPART"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("SERIE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("MAISON"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("ETAT"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DESTINATION"));

    return model;
}
QSqlQueryModel * bus::afficher_tri_temps()
{
    QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from bus order by temps_de_depart");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("TEMPS_DE_DEPART"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("SERIE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("MAISON"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("ETAT"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DESTINATION"));

    return model;
}
bool bus::supprimer(int serie)
{
    QSqlQuery query;
    QString res=QString::number(serie);
    query.prepare("Delete from bus where SERIE =:serie");
    query.bindValue(":serie",serie);
    return  query.exec();
}

QSqlQueryModel * bus::rechercher(int serie){

    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * from bus where SERIE =:serie");
    query.bindValue(":serie",serie);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("TEMPS_DE_DEPART"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("SERIE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("MAISON"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ETAT"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DESTINATION"));
    return model;
}


QSqlQueryModel * bus::rechercher_etat(QString etat){

    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * from bus where ETAT =:etat");
    query.bindValue(":etat",etat);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("TEMPS_DE_DEPART"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("SERIE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("MAISON"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ETAT"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DESTINATION"));
    return model;
}

int bus::get_serie()
{return serie;}
QString bus::get_maison()
{return maison;}
QString bus::get_etat()
{return  etat;}
QString bus::get_destination()
{return destination;}
QString bus::get_temps_de_depart()
{return temps_de_depart;}

bool bus::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE bus set TEMPS_DE_DEPART=:TEMPS_DE_DEPART,MAISON=:MAISON,ETAT=:ETAT,DESTINATION=:DESTINATION where SERIE =:serie");
    query.bindValue(":TEMPS_DE_DEPART",temps_de_depart);
    query.bindValue(":MAISON",maison);
    query.bindValue(":ETAT",etat);
    query.bindValue(":DESTINATION",destination);
    query.bindValue(":serie",serie);
    query.exec();
    if(query.numRowsAffected()>0){
        return  true;
    }else{
        return false;
    }
   }

QSqlQueryModel * bus::afficher_etat()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from etat");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("etat"));
    return model;
}

QSqlQueryModel * bus::afficher_maison()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from maison");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("maison"));
    return model;
}
