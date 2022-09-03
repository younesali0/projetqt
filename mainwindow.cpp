#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "magasin.h"
#include <string>
#include "event.h"
#include "connect.h"
#include <QDebug>
#include <qdebug.h>
#include <QMessageBox>
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
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(Magasin().afficher());
    ui->tableView_2->setModel(Event().afficher());
    ui->pushButton_10->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
     ui->pushButton_11->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
      ui->pushButton_12->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
       ui->pushButton_13->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
        ui->pushButton_14->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
         ui->pushButton_15->setStyleSheet("background-color: rgba(255, 255, 255, 0);");

         QChart *chart = new QChart();
       chart=Magasin().stat();
         QChartView *chartview = new QChartView(chart,ui->widget);
         chartview->resize(500,400);
         chartview->setRenderHint(QPainter::Antialiasing);



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    int id=ui->id_ajout->text().toInt();
    QString Nom=ui->nom_ajout->text();
    QString Adresse=ui->adresse_ajout->text();
    QString type = ui->comboBox->currentText();
    qDebug() << type;
    Magasin m(id,Nom,Adresse,type);
    int check=0;
    bool test=false;
    string n=Nom.toStdString();

    for (int i=0;i<Nom.length();i++){
        if (isdigit(n[i]))
        {check=1;}

    }
    if (check==0)
    test=m.ajouter();
    else { QMessageBox::information(nullptr, QObject::tr("OK"),
                                    QObject::tr("Format incorrect"), QMessageBox::Cancel);
    }

    if (test==true)
    { QMessageBox::information(nullptr, QObject::tr("OK"),
                               QObject::tr("Ajout done"), QMessageBox::Cancel);
    ui->tableView->setModel(Magasin().afficher());
    QChart *chart = new QChart();
  chart=Magasin().stat();
    QChartView *chartview = new QChartView(chart,ui->widget);
    chartview->resize(500,400);
    chartview->setRenderHint(QPainter::Antialiasing);}
    else
    { QMessageBox::information(nullptr, QObject::tr("OK"),
                               QObject::tr("NON"), QMessageBox::Cancel);}

}

void MainWindow::on_pushButton_3_clicked()
{
    int n=ui->id_supp->text().toInt();
  bool test=Magasin().Supprimer(n);
  if (test==true)
  { QMessageBox::information(nullptr, QObject::tr("OK"),
                             QObject::tr("Suppression done"), QMessageBox::Cancel);
  ui->tableView->setModel(Magasin().afficher());
  QChart *chart = new QChart();
chart=Magasin().stat();
  QChartView *chartview = new QChartView(chart,ui->widget);
  chartview->resize(500,400);
  chartview->setRenderHint(QPainter::Antialiasing);}
  else
  { QMessageBox::information(nullptr, QObject::tr("OK"),
                             QObject::tr("NON"), QMessageBox::Cancel);}
}

void MainWindow::on_pushButton_2_clicked()
{
    int id=ui->id_edit->text().toInt();
    QString Nom=ui->nom_edit->text();
    QString Adresse=ui->adresse_edit->text();
    QString type= ui->magasin_edit->text();
    Magasin m(id,Nom,Adresse,type);
    bool test=false;
    int check=0;
    string n=Nom.toStdString();
    for (int i=0;i<Nom.length();i++){
        if (isdigit(n[i]))
        {check=1;}

    }
    if (check==0)
   test=m.modifier();

        else
        { QMessageBox::information(nullptr, QObject::tr("OK"),
                                   QObject::tr("Format de nom incorrect"), QMessageBox::Cancel);}
    if (test==true)
    { QMessageBox::information(nullptr, QObject::tr("OK"),
                               QObject::tr("modification done"), QMessageBox::Cancel);
    ui->tableView->setModel(Magasin().afficher());
    QChart *chart = new QChart();
  chart=Magasin().stat();
    QChartView *chartview = new QChartView(chart,ui->widget);
    chartview->resize(500,400);
    chartview->setRenderHint(QPainter::Antialiasing);}
    else
    { QMessageBox::information(nullptr, QObject::tr("OK"),
                               QObject::tr("NON"), QMessageBox::Cancel);}
}

void MainWindow::on_pushButton_4_clicked()
{
    int id=ui->id_event->text().toInt();
    QString Nom=ui->nom_event->text();
    QString Adresse=ui->date_event->text();
    Event e(id,Nom,Adresse);
    int check=0;
     bool test=false;
    string n=Nom.toStdString();
    for (int i=0;i<Nom.length();i++){
        if (isdigit(n[i]))
        {check=1;}

    }
    if (check==0)
   test=e.ajouter();
else  { QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Format incorrect"), QMessageBox::Cancel);}
    if (test==true)
    { QMessageBox::information(nullptr, QObject::tr("OK"),
                               QObject::tr("Ajout done"), QMessageBox::Cancel);
        ui->tableView_2->setModel(Event().afficher());
    }
    else
    { QMessageBox::information(nullptr, QObject::tr("OK"),
                               QObject::tr("NON"), QMessageBox::Cancel);}
}

void MainWindow::on_pushButton_6_clicked()
{
    int n=ui->event_supp->text().toInt();
  bool test=Event().Supprimer(n);
  if (test==true)
  { QMessageBox::information(nullptr, QObject::tr("OK"),
                             QObject::tr("Suppression done"), QMessageBox::Cancel);
      ui->tableView_2->setModel(Event().afficher());
}
  else
  { QMessageBox::information(nullptr, QObject::tr("OK"),
                             QObject::tr("NON"), QMessageBox::Cancel);}
}

void MainWindow::on_pushButton_5_clicked()
{
    int id=ui->edit_id->text().toInt();
    QString Nom=ui->edit_nom->text();
    QString Adresse=ui->edit_date->text();
    Event e(id,Nom,Adresse);
    int check=0;
     bool test=false;
    string n=Nom.toStdString();
    for (int i=0;i<Nom.length();i++){
        if (isdigit(n[i]))
        {check=1;}

    }
    if (check==0)
    test=e.modifier();
    else { QMessageBox::information(nullptr, QObject::tr("OK"),
                                    QObject::tr("Format incorrect"), QMessageBox::Cancel);}
    if (test==true)
    { QMessageBox::information(nullptr, QObject::tr("OK"),
                               QObject::tr("modification done"), QMessageBox::Cancel);
        ui->tableView_2->setModel(Event().afficher());
   }
    else
    { QMessageBox::information(nullptr, QObject::tr("OK"),
                               QObject::tr("NON"), QMessageBox::Cancel);}
}

void MainWindow::on_id_edit_selectionChanged()
{

}

void MainWindow::on_id_edit_editingFinished()
{
    QString id=ui->id_edit->text();
    QSqlQuery q;
    q.prepare ("Select * from magasin where id_magasin = :id");
    q.bindValue(":id",id);
    q.exec();
   q.first();
   if(!q.first())
    { QMessageBox::information(nullptr, QObject::tr("OK"),
                               QObject::tr("ID not found"), QMessageBox::Cancel);}

    ui->nom_edit->setText(q.value(1).toString());
    ui->adresse_edit->setText(q.value(2).toString());
    ui->magasin_edit->setText(q.value(3).toString());
}

void MainWindow::on_edit_id_editingFinished()
{
    QString id=ui->edit_id->text();
    QSqlQuery q;
    q.prepare ("Select * from event where id_event = :id");
    q.bindValue(":id",id);
    q.exec();
   q.first();
   if(!q.first())
    { QMessageBox::information(nullptr, QObject::tr("OK"),
                               QObject::tr("ID not found"), QMessageBox::Cancel);}

    ui->edit_nom->setText(q.value(1).toString());
    ui->edit_date->setText(q.value(2).toString());
}

void MainWindow::on_pushButton_8_clicked()
{
   QString rech= ui->rechercher_magasin->text();
   ui->tableView->setModel(Magasin().recherche(rech));
}

void MainWindow::on_pushButton_9_clicked()
{
      ui->tableView->setModel(Magasin().afficher());
}

void MainWindow::on_pushButton_10_clicked()
{
    ui->tableView->setModel(Magasin().Trie_ID());
}

void MainWindow::on_pushButton_11_clicked()
{
    ui->tableView->setModel(Magasin().Trie_NOM());
}

void MainWindow::on_pushButton_12_clicked()
{
    ui->tableView->setModel(Magasin().Trie_adresse());
}

void MainWindow::on_pushButton_13_clicked()
{
    ui->tableView_2->setModel(Event().Trie_id());
}

void MainWindow::on_pushButton_14_clicked()
{
    ui->tableView_2->setModel(Event().Trie_nom());
}

void MainWindow::on_pushButton_15_clicked()
{
    ui->tableView_2->setModel(Event().Trie_date());
}
