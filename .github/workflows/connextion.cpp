#include "connextion.h"
#include <QSqlError>

connextion::connextion()
{

}
QString connextion::get_id()
{return id;}
QString connextion::get_password()
{return password;}
bool connextion::ouvrir_connextion()
{
    bool test=false;
    QSqlDatabase DB= QSqlDatabase::addDatabase("QODBC");
    DB.setConnectOptions();
    DB.setDatabaseName("Amine");
    DB.setUserName("amine");
    DB.setPassword("esprit18");
    if(DB.open())
    {test=true;}
    else
    {throw QString ("Erreur Paramétres"+DB.lastError().text());}

    return test;
}
