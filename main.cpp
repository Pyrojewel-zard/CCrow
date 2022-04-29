#include "mainwindow.h"
#include <QApplication>
//#include <tracker.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
//    widmap w;
//    Trackdata w;
//    tracker w;
    w.show();

    return a.exec();
}
