#include "event.h"
#include <QDebug>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
Event::Event()
{

}
Event::Event(int i,QString i1,QString i2){
    this->ID=i;
    this->Nom=i1;
    this->Date=i2;


}
bool Event::ajouter(){

QSqlQuery q;


q.prepare("insert INTO Event (ID_event,NOM_event,Datee) values (:id,:nom,:adresse)");
q.bindValue(":id",ID);
q.bindValue(":nom",Nom);
q.bindValue(":adresse",Date);

return q.exec();


}
bool Event::Supprimer(int n){
    QSqlQuery q;


    q.prepare("DELETE FROM event where id_event = :id");
    q.bindValue(":id",n);
    return q.exec();




}
bool Event::modifier(){

    QSqlQuery q;


    q.prepare("Update Event set nom_event= :nom , Datee =:adresse where id_event= :id");
    q.bindValue(":id",ID);
    q.bindValue(":nom",Nom);
    q.bindValue(":adresse",Date);

    return q.exec();




}
QSqlQueryModel * Event::afficher(){

    QSqlQueryModel  * mod=new QSqlQueryModel();
    mod->setQuery("SELECT * FROM event");
    mod->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_Event"));
    mod->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom_Event"));
    mod->setHeaderData(2,Qt::Horizontal,QObject::tr("Date"));


    return mod ;



}
QSqlQueryModel * Event::Trie_id(){

    QSqlQueryModel  * mod=new QSqlQueryModel();
    mod->setQuery("SELECT * FROM event order by ID_event");
    mod->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_Event"));
    mod->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom_Event"));
    mod->setHeaderData(2,Qt::Horizontal,QObject::tr("Date"));


    return mod ;



}
QSqlQueryModel * Event::Trie_nom(){

    QSqlQueryModel  * mod=new QSqlQueryModel();
    mod->setQuery("SELECT * FROM event order by nom_event");
    mod->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_Event"));
    mod->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom_Event"));
    mod->setHeaderData(2,Qt::Horizontal,QObject::tr("Date"));


    return mod ;



}
QSqlQueryModel * Event::Trie_date(){

    QSqlQueryModel  * mod=new QSqlQueryModel();
    mod->setQuery("SELECT * FROM event order by datee");
    mod->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_Event"));
    mod->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom_Event"));
    mod->setHeaderData(2,Qt::Horizontal,QObject::tr("Date"));


    return mod ;



}
