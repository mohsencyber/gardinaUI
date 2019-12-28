#include "mainwindow.h"
#include "QPushButton"
#include "QHBoxLayout"
#include <QApplication>
#include <QPropertyAnimation>
#include "formvideo.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /*QWidget *window = new QWidget;
    window->setWindowTitle("Window Layout");
    QPushButton *button = new QPushButton("Button One");
    QPushButton *button1 = new QPushButton("Button Two");
    QPushButton *button2 = new QPushButton("Button Three");
    QHBoxLayout *hlayout = new QHBoxLayout;
    hlayout->addWidget(button);
    hlayout->addWidget(button1);
    hlayout->addWidget(button2);
    window->setLayout(hlayout);
    window->show();*/
    MainWindow w;
    //FormVideo wv(&w);
    //wv.show();
    w.show();

    return a.exec();
}
