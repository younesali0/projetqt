#include "mainwindow.h"
#include "connect.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    Connect c;
   c.createconnect();
    QApplication a(argc, argv);
    MainWindow w;

    w.show();
    return a.exec();
}
