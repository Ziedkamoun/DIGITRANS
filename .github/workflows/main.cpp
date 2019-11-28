#include "mainwindow.h"
#include "connextion.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    connextion c;
    if(c.ouvrir_connextion())
    {
    w.show();
    }



    return a.exec();
}
