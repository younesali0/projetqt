#include "connect.h"

Connect::Connect()
{

}
bool Connect::createconnect()
{bool test=false;
db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2A");
db.setUserName("system");//inserer nom de l'utilisateur
db.setPassword("3004");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;
    return  test;
}
void Connect::closeConnection(){


    db.close();}
