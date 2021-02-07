#include "frameozone.h"
#include "ui_frameozone.h"
#include "ozonegeneral.h"
#include "infection.h"
#include "ozonect.h"

FrameOzone::FrameOzone(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::FrameOzone)
{
    ui->setupUi(this);
    this->setStyleSheet(" #FrameOzone {  border-image: url(:/gardina_main_bg.png) 0 0 0 0 stretch stretch; }");
}

FrameOzone::~FrameOzone()
{
    delete ui;
}

void FrameOzone::on_backButton_clicked()
{
    close();
}

void FrameOzone::on_general_button_clicked()
{
    OzoneGeneral *ozoneGeneral = new OzoneGeneral();
    ozoneGeneral->setSerialport(m_serialport);
    ozoneGeneral->showFullScreen();
}

void FrameOzone::on_infection_button_clicked()
{
    Infection *infection = new Infection();
    infection->setSerialport(m_serialport);
    infection->showFullScreen();
}

void FrameOzone::on_ct_button_clicked()
{
    OzoneCT *ozoneCT = new OzoneCT();
    ozoneCT->setSerialport(m_serialport);
    ozoneCT->showFullScreen();
}

void FrameOzone::setSerialport(MySerialPort *serialport)
{
    m_serialport = serialport;
}
