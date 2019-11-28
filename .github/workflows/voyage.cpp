#include "voyage.h"
#include <QString>
#include <QDebug>
voyage::voyage()
{

}
voyage::voyage(int nv_id,QString nv_destination,QString nv_temps_de_depart)
{
    id=nv_id;
    destination=nv_destination;
    temps_de_depart=nv_temps_de_depart;
}
QString voyage::get_destination()
{return  destination;}
bool voyage::ajouter_voyage()
{

    QSqlQuery query;
    query.prepare("INSERT INTO VOYAGE(ID,DESTINATION,TEMPS_DE_DEPART)" "VALUES(:ID,:DESTINATION,:TEMPS_DE_DEPART)");
    query.bindValue(":ID",id);
    query.bindValue(":DESTINATION",destination);
    query.bindValue(":TEMPS_DE_DEPART",temps_de_depart);
    return query.exec();

}

QSqlQueryModel * voyage::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from voyage");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("DESTINATION"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("TEMPS_DE_DEPART"));

    return model;
}
QSqlQueryModel * voyage::afficher_tri()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from voyage order by ID");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("DESTINATION"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("TEMPS_DE_DEPART"));

    return model;
}

QSqlQueryModel * voyage::afficher_destination()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from voyage order by DESTINATION");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("DESTINATION"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("TEMPS_DE_DEPART"));

    return model;
}
QSqlQueryModel * voyage::afficher_voyage()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select id from voyage");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    return model;
}

bool voyage::supprimer(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("Delete from voyage where ID =:id");
    query.bindValue(":id",id);
    return  query.exec();
}

bool voyage::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE voyage set TEMPS_DE_DEPART=:TEMPS_DE_DEPART,DESTINATION=:DESTINATION where ID =:id");
    query.bindValue(":TEMPS_DE_DEPART",temps_de_depart);
    query.bindValue(":DESTINATION",destination);
    query.bindValue(":id",id);
    query.exec();
    if(query.numRowsAffected()>0){
        return true;
    }else{
        return false;
    }
   }

QSqlQueryModel * voyage::afficher_destination_select()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from gouvernorat");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("gouvernorat"));
    return model;
}
QSqlQueryModel * voyage::rechercher(int id){

    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * from voyage where ID =:id");
    query.bindValue(":id",id);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DESTINATION"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TEMPS_DE_DEPART"));
    return model;
}
