#ifndef CONNECT_H
#define CONNECT_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
class Connect
{
public:
    Connect();
    QSqlDatabase db;


    bool createconnect();
    void closeConnection();
};

#endif // CONNECT_H
