#include "mainwindow.h"
#include "formmovie.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Formmovie m(&w);
    m.show();

    return a.exec();
}
