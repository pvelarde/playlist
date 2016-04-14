#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    // set the intial conditions for the window!
    w.setStyleSheet("background-color:rgb(204, 238, 255);");




    w.show();
    return a.exec();
}
