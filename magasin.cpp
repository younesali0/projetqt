#include "magasin.h"
#include <string>
using namespace std;
#include <QDebug>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChartView>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
QT_CHARTS_USE_NAMESPACE
Magasin::Magasin()
{

}
Magasin::Magasin(int i,QString i1,QString i2,QString i3){

    this->ID=i;
    this->NOM=i1;
    this->Adresse=i2;
    this->type=i3;
}
bool Magasin::ajouter(){

QSqlQuery q;


q.prepare("insert INTO MAGASIN (id_magasin,NOM_MAGASIN,Adresse,type) values (:id,:nom,:adresse,:type)");
q.bindValue(":id",ID);
q.bindValue(":nom",NOM);
q.bindValue(":adresse",Adresse);
q.bindValue(":type",type);
return q.exec();



}
bool Magasin::Supprimer(int n){
    QSqlQuery q;


    q.prepare("DELETE FROM MAGASIN where id_magasin = :id");
    q.bindValue(":id",n);
    return q.exec();




}
bool Magasin::modifier(){

    QSqlQuery q;


    q.prepare("Update Magasin set nom_magasin= :nom , adresse =:adresse , type =:type where id_magasin= :id");
    q.bindValue(":id",ID);
    q.bindValue(":nom",NOM);
    q.bindValue(":adresse",Adresse);
q.bindValue(":type",type);
    return q.exec();




}
QSqlQueryModel * Magasin::afficher(){

    QSqlQueryModel  * mod=new QSqlQueryModel();
    mod->setQuery("SELECT * FROM MAGASIN");
    mod->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_Magasin"));
    mod->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom_Magasin"));
    mod->setHeaderData(2,Qt::Horizontal,QObject::tr("Adresse"));
    mod->setHeaderData(3,Qt::Horizontal,QObject::tr("Type"));


    return mod ;



}
QSqlQueryModel * Magasin::recherche(QString n){

    QSqlQuery q;
    q.prepare("SELECT * FROM magasin where id_magasin = :nom or nom_magasin = :nom or adresse = :nom ");
    q.bindValue(":nom",n);
    q.exec();
    QSqlQueryModel  * mod=new QSqlQueryModel();
    mod->setQuery(q);

    mod->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_Magasin"));
    mod->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom_Magasin"));
    mod->setHeaderData(2,Qt::Horizontal,QObject::tr("Adresse"));
mod->setHeaderData(3,Qt::Horizontal,QObject::tr("Type"));

    return mod ;






}
QSqlQueryModel * Magasin::Trie_ID(){


    QSqlQueryModel  * mod=new QSqlQueryModel();
    mod->setQuery("SELECT * FROM MAGASIN ORDER BY id_magasin");
    mod->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_Magasin"));
    mod->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom_Magasin"));
    mod->setHeaderData(2,Qt::Horizontal,QObject::tr("Adresse"));
mod->setHeaderData(3,Qt::Horizontal,QObject::tr("Type"));

    return mod ;








}
QSqlQueryModel * Magasin::Trie_NOM(){


    QSqlQueryModel  * mod=new QSqlQueryModel();
    mod->setQuery("SELECT * FROM MAGASIN ORDER BY NOM_magasin");
    mod->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_Magasin"));
    mod->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom_Magasin"));
    mod->setHeaderData(2,Qt::Horizontal,QObject::tr("Adresse"));
mod->setHeaderData(3,Qt::Horizontal,QObject::tr("Type"));

    return mod ;








}
QSqlQueryModel * Magasin::Trie_adresse(){


    QSqlQueryModel  * mod=new QSqlQueryModel();
    mod->setQuery("SELECT * FROM MAGASIN ORDER BY adresse");
    mod->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_Magasin"));
    mod->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom_Magasin"));
    mod->setHeaderData(2,Qt::Horizontal,QObject::tr("Adresse"));

mod->setHeaderData(3,Qt::Horizontal,QObject::tr("Type"));
    return mod ;








}
QChart * Magasin::stat(){


    QSqlQuery q,q1,q2,q3,q4,q5;
    q.exec("Select * from Magasin");
    int tot=0;
    while (q.next())
        tot++;
   qDebug() << "total =" << tot;
    q1.prepare("Select * from Magasin where type = :nom ");
    q1.bindValue(":nom","Vetements");
    q1.exec();

    int tot_don=0;
    while (q1.next())
        tot_don++;
 qDebug() << "pourcentage don =" << tot_don;
    qreal pour_Vetments=(tot_don*100)/tot;

    q2.prepare("Select * from Magasin where type = :nom ");
    q2.bindValue(":nom","Voitures");
    q2.exec();
    int tot_event=0;
    while (q2.next())
        tot_event++;

    qreal pour_Voiture=(tot_event*100)/tot;

    q3.prepare("Select * from Magasin where type = :nom ");
    q3.bindValue(":nom","Supermarche");
    q3.exec();
    int tot_dep=0;
    while (q3.next())
        tot_dep++;
    qreal pour_supermarche=(tot_dep*100)/tot;



    QPieSeries *series = new QPieSeries();
     series->append("Vetements",pour_Vetments);
     series->append("Voiture",pour_Voiture);
     series->append("Supermarche",pour_supermarche);

     QPieSlice *slice0= series->slices().at(0);
     slice0->setLabelVisible();
     QPieSlice *slice1 = series->slices().at(1);

     slice1->setLabelVisible();

     slice1->setBrush(Qt::green);

     QPieSlice *slice2= series->slices().at(2);
     slice2->setLabelVisible();
      slice2->setBrush(Qt::red);

     QChart *chart = new QChart();
     chart->addSeries(series);
     chart->setTitle("Type des magasin");
     chart->legend()->hide();



    return chart;



}
