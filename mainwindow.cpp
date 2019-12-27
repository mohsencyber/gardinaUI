#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "buttonhoverwatcher.h"
#include <QVideoWidget>
#include <QMediaPlayer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("gardina");

    ButtonHoverWatcher * watcheroxygen = new ButtonHoverWatcher(this);
    ButtonHoverWatcher * watcherozone = new ButtonHoverWatcher(this);
    ButtonHoverWatcher * watchervacuum = new ButtonHoverWatcher(this);
    watcherozone->setIconSize(QSize(110,90));
    watcheroxygen->setIconSize(QSize(110,90));
    watchervacuum->setIconSize(QSize(110,90));
    watcherozone->setIcon(":/images/button_ozone_highlight_bg.png",":/images/button_ozone_bg.png");
    watcheroxygen->setIcon(":/images/button_oxygen_highlight_bg.png",":/images/button_oxygen_bg.png");
    watchervacuum->setIcon(":/images/button_vacuum_highlight_bg.png",":/images/button_vacuum_bg.png");
    ui->Oxygen_button->installEventFilter(watcheroxygen);
    ui->Ozone_button->installEventFilter(watcherozone);
    ui->vacuum_button->installEventFilter(watchervacuum);
    ui->Ozone_button->setFlat(false);
    ui->Oxygen_button->setFlat(false);
    ui->vacuum_button->setFlat(false);
    //ui->Ozone_button->setStyleSheet("border-image:url(:/images/button_ozone_bg.png");
    //ui->vacuum_button->setStyleSheet("border-image:url(:/images/button_vacuum_bg.png");
    //ui->Oxygen_button->setStyleSheet("border-image:url(:/images/button_oxygen_bg.png");
    ui->Ozone_button->setIcon(QIcon(":/images/button_Ozone_bg.png"));
    ui->Oxygen_button->setIcon(QIcon(":/images/button_Oxygen_bg.png"));
    ui->vacuum_button->setIcon(QIcon(":/images/button_Vacuum_bg.png"));
    this->setStyleSheet( "#MainWindow { "
                         " border-image: url(:/images/gardina_main_bg.png) 0 0 0 0 stretch stretch;"
                         "}");

    //ui->Ozone_button->setStyleSheet("{ QPushButton:flat {   border: none; }}");
    //ui->Oxygen_button->setStyleSheet("border-image:url(:/images/button_ozone_highlight_bg.png");

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    close();
}

void MainWindow::on_Ozone_button_clicked()
{
    qmsg.setText("ozone form viewed?");
    qmsg.setIcon(QMessageBox::NoIcon);
    qmsg.setStandardButtons(QMessageBox::Ok);
    qmsg.exec();
}



void MainWindow::on_Oxygen_button_clicked()
{
    qmsg.setText("Oxygen form viewed?");
    qmsg.setIcon(QMessageBox::NoIcon);
    qmsg.setStandardButtons(QMessageBox::Ok);
    qmsg.exec();
}

void MainWindow::on_vacuum_button_clicked()
{
    qmsg.setText("Vacuum form viewed?");
    qmsg.setIcon(QMessageBox::NoIcon);
    qmsg.setStandardButtons(QMessageBox::Ok);
    qmsg.exec();
}
