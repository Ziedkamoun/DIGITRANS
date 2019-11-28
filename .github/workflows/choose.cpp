#include "choose.h"
#include "ui_choose.h"
#include "bus.h"
#include <QDebug>
#include "voyage.h"
#include <stdio.h>
#include <QSqlTableModel>
#include "QMessageBox"
#include "qmessagebox.h"
#include <QApplication>
#include "dialog2.h"
#include "statistique.h"
choose::choose(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::choose)
{
    ui->setupUi(this);
refresh();
QPixmap pix("D:/Desktop/final/pic.jpg");
ui->label_pic->setPixmap(pix);
ui->label_pic_2->setPixmap(pix);


}
choose::~choose()
{
    delete ui;
}
void choose::initialiser()
{
    ui->serie->clear();


    ui->temps_de_depart->clear();
}


void choose::refresh()
{
    ui->bus_afficher->setModel(tmpbus.afficher());
    ui->voyage_afficher->setModel(tmpvoyage.afficher());
    ui->comboBox->setModel(tmpvoyage.afficher_voyage());

    ui->comboBox_3->setModel(tmpbus.afficher_etat());
    ui->comboBox_4->setModel(tmpbus.afficher_maison());
    ui->comboBox_2->setModel(tmpvoyage.afficher_destination_select());

}

void choose::on_pushButton_9_clicked()
{
    //ajouter
    QString maison,etat,temps_de_depart;
    int serie;
//    int i;
serie=ui->serie->text().toInt();


temps_de_depart=ui->temps_de_depart->text();


bool test=false;

    if((serie>0)&&(serie<10000))
    {test=true;}



if (test){
bus b(serie,tmpbus.get_maison(),tmpbus.get_etat(),tmpbus.get_destination(),temps_de_depart);
if(b.ajouter_bus())
{
refresh();
initialiser();
}
else{    QMessageBox::information(nullptr, QObject::tr("Ajout echouée"),"Cette serie existe deja ou forme Incorrect!!!");
}}
else{
    QMessageBox::information(nullptr, QObject::tr("Ajout echouée"),"Cette serie existe deja ou forme Incorrect!!!");
}
}

void choose::on_pushButton_clicked()
{

   int serie=ui->serie->text().toInt();
    QString temps_de_depart=ui->temps_de_depart->text();

    bool test=false;

        if((serie>0)&&(serie<10000))
        {test=true;}



    if (test){
    bus b1(serie,tmpbus.get_maison(),tmpbus.get_etat(),tmpbus.get_destination(),temps_de_depart);
   if( b1.modifier()){
       refresh();
       initialiser();

   }
   else{ QMessageBox::information(nullptr, QObject::tr("Ajout echouée"),"Cette serie n'existe pas ou forme Incorrect!!!");}
}
else
    {    QMessageBox::information(nullptr, QObject::tr("Ajout echouée"),"Cette serie n'existe pas ou forme Incorrect!!!");

}}


/*
void choose::on_pushButton_8_clicked()
{
//646846846849684
    QString maison,etat,temps_de_depart;
    int serie;
serie=ui->serie->text().toInt();
maison=ui->maison->text();
etat=ui->etat->text();
temps_de_depart=ui->temps_de_depart->text();
bus b(serie,maison,etat,tmpbus.get_destination(),temps_de_depart);
if(b.ajouter_bus())
{
    ui->bus_afficher->setModel(tmpbus.afficher_tri());

    initialiser();
}
else{
    QMessageBox::information(nullptr, QObject::tr("Ajout echouée"),"Cette serie existe deja");

}
}*/


void choose::on_pushButton_2_clicked()
{
    int serie=ui->serie2->text().toInt();
    bool test=tmpbus.supprimer(serie);
    if(test)
    {refresh();

    }



}

void choose::on_pushButton_7_clicked()
{
  /*  QSqlQueryModel * test=tmpbus.rechercher(ui->trouver->text().toInt());
    if(test==nullptr)
    {
   QMessageBox::information(nullptr, QObject::tr("Rechercher"),"Cette serie n'existe pas");
}
    else{
    QMessageBox::information(nullptr, QObject::tr("Rechercher"),"Cette serie existe va voir dans rechercher");

 //   ui->bus_afficher->setModel(tmpbus.rechercher(ui->trouver->text().toInt()));*/
    ui->bus_afficher->setModel(tmpbus.rechercher(ui->trouver->text().toInt()));}



void choose::on_pushButton_11_clicked()
{
    int id;
    QString destination;
    QString temps_de_depart;
  id=ui->id->text().toInt();
 temps_de_depart=ui->temps_de_depart_3->text();
    voyage v(id,tmpvoyage.get_destination(),temps_de_depart);
    bool test=false;
    if(id>0)
    {test=true;}

    if(test)
    {
    if(v.ajouter_voyage())
    { refresh();
    }
    else{
        QMessageBox::information(nullptr, QObject::tr("Ajout echouée"),"Cet ID existe deja ou forme in correct!!!!");

    }}else{  QMessageBox::information(nullptr, QObject::tr("Ajout echouée"),"Cet ID existe deja ou forme Incorrect!!!");
    }}


void choose::on_pushButton_5_clicked()
{
    int id;
    id=ui->supp->text().toInt();
    bool test=tmpvoyage.supprimer(id);
    if(test)
    {  refresh();


}
}

void choose::on_pushButton_6_clicked()
{
   int id=ui->id->text().toInt();
     QString temps_de_depart=ui->temps_de_depart_3->text();
     voyage v1(id,tmpvoyage.get_destination(),temps_de_depart);
    if( v1.modifier()){refresh();

    }

}

void choose::on_comboBox_activated(const QString &arg1)
{
tmpbus.set_destination(arg1);

}


void choose::on_pushButton_8_clicked()
{
    ui->bus_afficher->setModel(tmpbus.afficher_tri());

}

void choose::on_pushButton_12_clicked()
{
    ui->bus_afficher->setModel(tmpbus.afficher_tri_temps());

}

void choose::on_pushButton_13_clicked()
{
    ui->bus_afficher->setModel(tmpbus.afficher());

}


void choose::on_trouver_textChanged(const int &arg1)
{
    ui->bus_afficher->setModel(tmpbus.rechercher(arg1));
}

void choose::on_comboBox_3_activated(const QString &arg1)
{
    tmpbus.set_etat(arg1);
}

void choose::on_comboBox_4_activated(const QString &arg1)
{
    tmpbus.set_maison(arg1);
}



void choose::on_pushButton_14_clicked()
{
    ui->voyage_afficher->setModel(tmpvoyage.afficher_tri());
}

void choose::on_pushButton_16_clicked()
{
    ui->voyage_afficher->setModel(tmpvoyage.afficher_destination());

}

void choose::on_pushButton_15_clicked()
{
    ui->voyage_afficher->setModel(tmpvoyage.afficher());

}

void choose::on_comboBox_2_activated(const QString &arg1)
{
    tmpvoyage.set_destination(arg1);
}

void choose::on_pushButton_17_clicked()
{
    ui->voyage_afficher->setModel(tmpvoyage.rechercher(ui->trouver_2->text().toInt()));

}

void choose::on_pushButton_18_clicked()
{
    Dialog2 d;
    d.exec();
}

void choose::on_pushButton_19_clicked()
{
    ui->bus_afficher->setModel(tmpbus.rechercher_etat(ui->trouver_etat->text()));
}

void choose::on_pushButton_20_clicked()
{
    statistique s;
    s.exec();
}
