#include "mainwindow.h"
#include <QApplication>
#include <QImage>
#include <cstdlib>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.processMoveMarix();
    w.show();
    return a.exec();
}
