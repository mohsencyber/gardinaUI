#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QProcess"
#include "QStringList"
#include "buttonhoverwatcher.h"
#include "QToolButton"
#include "formaccess.h"
#include "formOxygen.h"
#include "formvaccum.h"
#include "frameozone.h"
#include "framelogin.h"
#include <QSettings>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    this->showFullScreen();

    QProcess process;
//#ifdef QT_NO_DEBUG
    process.execute("omxplayer video.mp4");
//#endif

#ifdef QT_NO_DEBUG
    ui->pushButton->setDisabled(true);
    ui->pushButton->setHidden(true);
#endif
    this->setWindowTitle("gardina");

    int x,y,w,h;
    this->geometry().getRect(&x,&y,&w,&h);
    bool Oxygen_enable = true;
    bool Ozone_enable = true;
    bool Vacuum_enable = true;

    QSettings TLSetting("/home/pi/myapp/ctl.dat",QSettings::IniFormat);
    int l_ctl;
    l_ctl=TLSetting.value("ctl","0").toInt();

    QSettings setting("/home/pi/myapp/gardina.cfg",QSettings::IniFormat);
    QString l_portname = setting.value("portname").toString();
    int l_baudrate = setting.value("baudrate").toInt();
    bool lbsecure = setting.value("secure","no").toString().toUpper()=="YES";

    if ( lbsecure ){
        FrameLogin  *frameLogin = new FrameLogin();
        frameLogin->showFullScreen();
    }

    bool lbExitEnable = true, lbShutDownEnable = true;

    if ( l_ctl >  800*3600 ){
        //QMessageBox::information(nullptr,"","This version is expired. Please reset the left time.");//,QMessageBox::Ok);
        //Ozone_enable=false;
        //Vacuum_enable=false;
    }

    lbExitEnable = setting.value("exit_enable","no").toString().toUpper()=="YES";
    lbShutDownEnable = setting.value("shutdown_enable","no").toString().toUpper()=="YES";

    m_serialPort = new MySerialPort(l_portname,l_baudrate);
    ButtonHoverWatcher * watcheroxygen = new ButtonHoverWatcher(this);
    ButtonHoverWatcher * watcherozone = new ButtonHoverWatcher(this);
    ButtonHoverWatcher * watchervacuum = new ButtonHoverWatcher(this);
    ButtonHoverWatcher * watcheraccess = new ButtonHoverWatcher(this);

    if ( Oxygen_enable ){
        watcheroxygen->setIconSize(QSize(180,170));
        watcheroxygen->setIcon(":/button_oxygen_highlight_bg.png",":/button_oxygen_bg.png");
        ui->Oxygen_button->installEventFilter(watcheroxygen);
    }else{
        ui->Oxygen_button->setDisabled(true);
        ui->Oxygen_button->setStyleSheet("border:none;text-align:left;image:url(:/button_oxygen_bg.png)");
    }

    if ( Ozone_enable ){
        watcherozone->setIconSize(QSize(180,170));
        watcherozone->setIcon(":/button_ozone_highlight_bg.png",":/button_ozone_bg.png");
        ui->Ozone_button->installEventFilter(watcherozone);
    }else{
        ui->Ozone_button->setDisabled(true);
        ui->Ozone_button->setStyleSheet("border:none;text-align:left;image:url(:/button_ozone_bg_gray.png)");
    }

    if ( Vacuum_enable ){
        watchervacuum->setIconSize(QSize(180,170));
        watchervacuum->setIcon(":/button_vacuum_highlight_bg.png",":/button_vacuum_bg.png");
        ui->vacuum_button->installEventFilter(watchervacuum);
    }else{
        ui->vacuum_button->setDisabled(true);
        ui->vacuum_button->setStyleSheet("border:none;text-align:left;image:url(:/button_vacuum_bg_gray.png)");
    }

    watcheraccess->setIconSize(QSize(180,170));
    watcheraccess->setIcon(":/button_access_highlight_bg.png",":/button_access_bg.png");
    ui->access_button->installEventFilter(watcheraccess);

    this->setStyleSheet( "#MainWindow { "
                 " border-image: url(:/gardina_main_bg.png) 0 0 0 0 stretch stretch;"
                 "}");
    ui->pushButton->setEnabled(lbExitEnable);
    ui->pushButton->setVisible(lbExitEnable);
    ui->poweroff_button->setEnabled(lbShutDownEnable);
    ui->poweroff_button->setVisible(lbShutDownEnable);
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
    FrameOzone *ozone = new FrameOzone();
    ozone->setSerialport(m_serialPort);
    ozone->showFullScreen();
}

void MainWindow::on_poweroff_button_clicked()
{
    QProcess process;
    process.execute("sudo shutdown -P now ");
}

void MainWindow::on_access_button_clicked()
{
    formAccess *formaccess = new formAccess();
    formaccess->showFullScreen();
}

void MainWindow::on_Oxygen_button_clicked()
{
    FormOxygen *formOxygen = new FormOxygen();
    formOxygen->setSerialport(m_serialPort);
    formOxygen->showFullScreen();
}

void MainWindow::on_vacuum_button_clicked()
{
    FormVaccum *formVaccum = new FormVaccum();
    formVaccum->setSerialport(m_serialPort);
    formVaccum->showFullScreen();
}
