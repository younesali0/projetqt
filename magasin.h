#ifndef MAGASIN_H
#define MAGASIN_H
#include <string>
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
using namespace std;
QT_CHARTS_USE_NAMESPACE
class Magasin
{

public:
    Magasin();
   Magasin(int,QString,QString,QString);
    int ID;
    QString NOM ;
    QString Adresse;
    QString type;
    bool ajouter();
    bool modifier();
    bool Supprimer(int n);
   QSqlQueryModel * afficher();
    QSqlQueryModel * recherche(QString n);
    QSqlQueryModel * Trie_ID();
    QSqlQueryModel * Trie_NOM();
    QSqlQueryModel * Trie_adresse();
    QChart * stat();

};

#endif // MAGASIN_H
