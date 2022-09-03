#ifndef EVENT_H
#define EVENT_H
#include <string>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Event
{
public:
    int ID;
    QString Nom;
    QString Date;
    Event();
    Event(int,QString,QString);
    bool ajouter();
    bool modifier();
    bool Supprimer(int n);
   QSqlQueryModel * afficher();
   QSqlQueryModel * Trie_id();
   QSqlQueryModel * Trie_nom();
   QSqlQueryModel * Trie_date();
};

#endif // EVENT_H
