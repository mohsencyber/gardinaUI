#include "ozonegeneral.h"
#include "ui_ozonegeneral.h"
#include "ozonegeneralconf.h"
#include <QSpinBox>
#include <QLCDNumber>

OzoneGeneral::OzoneGeneral(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::OzoneGeneral)
{
    ui->setupUi(this);
    m_timeLeft = new TimeLeft();
    this->setStyleSheet( " #OzoneGeneral { "
                         " border:none;border-image: url(:/gardina_main_bg.png) 0 0 0 0 stretch stretch;"
                         "}");

    //connect( ui->secSpin,SIGNAL(valueChanged(int)),ui->secNumber,SLOT(display(int)));
    //connect( ui->minSpin,SIGNAL(valueChanged(int)),ui->minNumber,SLOT(display(int)));
    //connect( ui->hourSpin,SIGNAL(valueChanged(int)),ui->hourNumber,SLOT(display(int)));
    //connect( ui->mlSpin,SIGNAL(valueChanged(int)),ui->mlNumber,SLOT(display(int)));

    ui->hourSpin->setValue(0);
    ui->minSpin->setValue(0);
    ui->secSpin->setValue(0);
    ui->mlSpin->setValue(1);

    ui->minSpin->setVisible(false);

    connect(ui->mintextEdit, &QTouchSpinBox::MovedUp , ui->minSpin , &QSpinBox::stepUp );
    connect(ui->mintextEdit, &QTouchSpinBox::MovedDown , ui->minSpin , &QSpinBox::stepDown );

    ui->hourSpin->setVisible(false);

    connect(ui->hourtextEdit, &QTouchSpinBox::MovedUp , ui->hourSpin , &QSpinBox::stepUp );
    connect(ui->hourtextEdit, &QTouchSpinBox::MovedDown , ui->hourSpin , &QSpinBox::stepDown );

    ui->secSpin->setVisible(false);

    connect(ui->sectextEdit, &QTouchSpinBox::MovedUp , ui->secSpin , &QSpinBox::stepUp );
    connect(ui->sectextEdit, &QTouchSpinBox::MovedDown , ui->secSpin , &QSpinBox::stepDown );

    ui->mlSpin->setVisible(false);

    connect(ui->mltextEdit, &QTouchSpinBox::MovedUp , ui->mlSpin , &QSpinBox::stepUp );
    connect(ui->mltextEdit, &QTouchSpinBox::MovedDown , ui->mlSpin , &QSpinBox::stepDown );


    ui->hourtextEdit->setAttribute(Qt::WA_TranslucentBackground);
    ui->mintextEdit->setAttribute(Qt::WA_TranslucentBackground);
    ui->sectextEdit->setAttribute(Qt::WA_TranslucentBackground);
    ui->mltextEdit->setAttribute(Qt::WA_TranslucentBackground);

    ui->hourNumber->display(QString("%1").arg(0, 2, 10, QChar('0')));
    ui->minNumber->display(QString("%1").arg(0, 2, 10, QChar('0')));
    ui->secNumber->display(QString("%1").arg(0, 2, 10, QChar('0')));
    ui->mlNumber->display(QString("%1").arg(1, 2, 10, QChar('0')));

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTimer()));
    ui->startButton->setEnabled(false);
}

OzoneGeneral::~OzoneGeneral()
{
    delete ui;
}

void OzoneGeneral::on_pushButton_clicked()
{
    m_serialport->waitforwrite();
    m_serialport->close();
    timer->stop();
    this->cursor().setPos(5,5);
    close();
}

void OzoneGeneral::on_secSpin_valueChanged(int arg1)
{
    if ( arg1 == 60 ) {
        ui->secSpin->setValue(0);
        ui->minSpin->stepUp();
    }
    if ( arg1 == -1 ) {
        ui->secSpin->setValue(59);
        ui->minSpin->stepDown();
    }
    int i = ui->secSpin->value();
    int bi,ai;
    bi=i-1;ai=i+1;
    if (bi==-1) bi = 59;
    if (ai==60) ai = 1;
    QFont font(ui->sectextEdit->font());
    font.setBold(true);
    ui->sectextEdit->setTextColor(QColor::fromRgb(0,0,0,200));
    ui->sectextEdit->setText(QString::number(bi));
    ui->sectextEdit->setAlignment(Qt::AlignCenter);
    ui->sectextEdit->setTextColor(Qt::lightGray);
    ui->sectextEdit->append("------");
    ui->sectextEdit->setCurrentFont(font);
    ui->sectextEdit->setAlignment(Qt::AlignCenter);
    ui->sectextEdit->setTextColor(Qt::black);
    ui->sectextEdit->append(QString::number(i));
    font.setBold(false);
    ui->sectextEdit->setCurrentFont(font);
    ui->sectextEdit->setAlignment(Qt::AlignCenter);
    ui->sectextEdit->setTextColor(Qt::lightGray);
    ui->sectextEdit->append("------");
    ui->sectextEdit->setAlignment(Qt::AlignCenter);
    ui->sectextEdit->setTextColor(QColor::fromRgb(0,0,0,200));
    ui->sectextEdit->append(QString::number(ai));
    ui->sectextEdit->setAlignment(Qt::AlignCenter);
    ui->secNumber->display(QString("%1").arg(i, 2, 10, QChar('0')));


    if ( ui->hourNumber->intValue()+ui->minNumber->intValue()+ui->secNumber->intValue() > 0 && !(timer->isActive()) )
        ui->startButton->setEnabled(true);
    else
        ui->startButton->setEnabled(false);
}

void OzoneGeneral::on_mconfigButton_clicked()
{
    ozoneGeneralConf *generalConf = new ozoneGeneralConf();
    generalConf->setValues(ui->hourSpin->value(),ui->minSpin->value(),ui->secSpin->value(),ui->mlSpin->value());
    generalConf->setSerialport(m_serialport);
    generalConf->showFullScreen();
}

void OzoneGeneral::on_minSpin_valueChanged(int arg1)
{
    if ( arg1 == 60 ) {
        ui->minSpin->setValue(0);
        ui->hourSpin->stepUp();
    }
    if ( arg1 == -1 ){
        ui->minSpin->setValue(59);
        ui->hourSpin->stepDown();
    }
    int i = ui->minSpin->value();
    int bi,ai;
    bi=i-1;ai=i+1;
    if (bi==-1) bi = 59;
    if (ai==60) ai = 1;
    QFont font(ui->mintextEdit->font());
    font.setBold(true);
    ui->mintextEdit->setTextColor(QColor::fromRgb(0,0,0,200));
    ui->mintextEdit->setText(QString::number(bi));
    ui->mintextEdit->setAlignment(Qt::AlignCenter);
    ui->mintextEdit->setTextColor(Qt::lightGray);
    ui->mintextEdit->append("------");
    ui->mintextEdit->setCurrentFont(font);
    ui->mintextEdit->setAlignment(Qt::AlignCenter);
    ui->mintextEdit->setTextColor(Qt::black);
    ui->mintextEdit->append(QString::number(i));
    font.setBold(false);
    ui->mintextEdit->setCurrentFont(font);
    ui->mintextEdit->setAlignment(Qt::AlignCenter);
    ui->mintextEdit->setTextColor(Qt::lightGray);
    ui->mintextEdit->append("------");
    ui->mintextEdit->setAlignment(Qt::AlignCenter);
    ui->mintextEdit->setTextColor(QColor::fromRgb(0,0,0,200));
    ui->mintextEdit->append(QString::number(ai));
    ui->mintextEdit->setAlignment(Qt::AlignCenter);
    ui->minNumber->display(QString("%1").arg(i, 2, 10, QChar('0')));
    if ( ui->hourNumber->intValue()+ui->minNumber->intValue()+ui->secNumber->intValue() > 0 && !(timer->isActive())  )
        ui->startButton->setEnabled(true);
    else
        ui->startButton->setEnabled(false);

}

void OzoneGeneral::on_hourSpin_valueChanged(int arg1)
{
    if ( arg1 == 13 ){
        ui->hourSpin->setValue(0);
    }
    if ( arg1 == -1){
        ui->hourSpin->setValue(12);
    }
    int i = ui->hourSpin->value();
    int bi,ai;
    bi=i-1;ai=i+1;
    if (bi==-1) bi = 12;
    if (ai==13) ai = 0;
    QFont font(ui->hourtextEdit->font());
    font.setBold(true);
    ui->hourtextEdit->setTextColor(QColor::fromRgb(0,0,0,200));
    ui->hourtextEdit->setText(QString::number(bi));
    ui->hourtextEdit->setAlignment(Qt::AlignCenter);
    ui->hourtextEdit->setTextColor(Qt::lightGray);
    ui->hourtextEdit->append("------");
    ui->hourtextEdit->setCurrentFont(font);
    ui->hourtextEdit->setAlignment(Qt::AlignCenter);
    ui->hourtextEdit->setTextColor(Qt::black);
    ui->hourtextEdit->append(QString::number(i));
    font.setBold(false);
    ui->hourtextEdit->setCurrentFont(font);
    ui->hourtextEdit->setAlignment(Qt::AlignCenter);
    ui->hourtextEdit->setTextColor(Qt::lightGray);
    ui->hourtextEdit->append("------");
    ui->hourtextEdit->setAlignment(Qt::AlignCenter);
    ui->hourtextEdit->setTextColor(QColor::fromRgb(0,0,0,200));
    ui->hourtextEdit->append(QString::number(ai));
    ui->hourtextEdit->setAlignment(Qt::AlignCenter);
    ui->hourNumber->display(QString("%1").arg(i, 2, 10, QChar('0')));
    if ( ui->hourNumber->intValue()+ui->minNumber->intValue()+ui->secNumber->intValue() > 0 && !(timer->isActive())  )
        ui->startButton->setEnabled(true);
    else
        ui->startButton->setEnabled(false);

}

void OzoneGeneral::on_hourminus_clicked()
{
    ui->hourSpin->stepDown();
}

void OzoneGeneral::on_startButton_clicked()
{
    ui->startButton->setDisabled(true);
    ui->pushButton->setDisabled(true);
    ui->touchButton->setDisabled(true);
    m_serialport->open();
    touch = false;
    timer->setInterval(1000);
    timer->start();
    m_userMin = ui->minSpin->value();
    m_userSec = ui->secSpin->value();
    m_userHour= ui->hourSpin->value();

}

void OzoneGeneral::on_stopButton_clicked()
{
    ui->startButton->setDisabled(false);
    ui->pushButton->setDisabled(false);
    ui->touchButton->setDisabled(false);
    stop();
    timer->stop();
    ui->hourSpin->setValue(m_userHour);
    ui->minSpin->setValue(m_userMin);
    ui->secSpin->setValue(m_userSec);
}

void OzoneGeneral::on_touchButton_clicked()
{
    return ;
}



void OzoneGeneral::updateTimer()
{
    if ( !touch ){
       if ( ui->hourSpin->value() == 0 &&
            ui->minSpin->value() == 0 &&
            ui->secSpin->value() == 0 )
       {
           end();
           timer->stop();
           ui->startButton->setDisabled(false);
           ui->pushButton->setDisabled(false);
           ui->touchButton->setDisabled(false);
           ui->hourSpin->setValue(m_userHour);
           ui->minSpin->setValue(m_userMin);
           ui->secSpin->setValue(m_userSec);
       }else{
           int sendTouch = 300+ui->mlNumber->intValue(),interval=0;
           QString strTouch = QString::number(sendTouch)+"\n";
           if ( m_serialport->isOpen())
               m_serialport->write(strTouch.toUtf8(),interval);
           ui->secSpin->stepDown();
           m_timeLeft->incTime();
       }
    }else{
        int sendTouch = 300+ui->mlNumber->intValue(),interval=0;
        QString strTouch = QString::number(sendTouch)+"\n";
        if ( m_serialport->isOpen())
            m_serialport->write(strTouch.toUtf8(),interval);
        ui->secSpin->stepUp();
        m_timeLeft->incTime();
    }
}

void OzoneGeneral::setSerialport(MySerialPort *serialport)
{
    m_serialport = serialport;
}

void OzoneGeneral::start()
{
    QString strStart="100\n";
    int interval=0;
    m_serialport->open();
    if ( m_serialport->isOpen())
    {
        m_serialport->write(strStart.toUtf8(),interval);
    }

}

void OzoneGeneral::stop()
{
    QString strStop = "300\n";
    int interval = 0;
    if ( m_serialport->isOpen())
    {
        m_serialport->write(strStop.toUtf8(),interval);
    }
}

void OzoneGeneral::end()
{
    QString end = "500\n";
    int interval= 0;
    stop();
    if ( m_serialport->isOpen())
    {
        m_serialport->write(end.toUtf8(),interval);
    }

}

void OzoneGeneral::on_touchButton_pressed()
{
    int sendTouch=300,interval=0;
    if ( !touch ){
        m_serialport->open();
        m_userMin = ui->minSpin->value();
        m_userSec = ui->secSpin->value();
        m_userHour= ui->hourSpin->value();
        ui->hourSpin->setValue(0);
        ui->minSpin->setValue(0);
        ui->secSpin->setValue(0);
        sendTouch = 300+ui->mlNumber->intValue();
        QString strTouch = QString::number(sendTouch)+"\n";
        if ( m_serialport->isOpen())
            m_serialport->write(strTouch.toUtf8(),interval);
        timer->setInterval(1000);
        timer->start();
    }
    touch=true;
}

void OzoneGeneral::on_touchButton_released()
{

    if ( touch ){
        ui->hourSpin->setValue(m_userHour);
        ui->minSpin->setValue(m_userMin);
        ui->secSpin->setValue(m_userSec);
        stop();
        timer->stop();
    }
    touch = false;
}

void OzoneGeneral::on_mlSpin_valueChanged(int arg1)
{
    if ( arg1 == 81 ){
        ui->mlSpin->setValue(1);
    }
    if ( arg1 == 0){
        ui->mlSpin->setValue(80);
    }
    int i = ui->mlSpin->value();
    int bi,ai;
    bi=i-1;ai=i+1;
    if (bi==0) bi = 80;
    if (ai==81) ai = 1;
    QFont font(ui->mltextEdit->font());
    font.setBold(true);
    ui->mltextEdit->setTextColor(QColor::fromRgb(0,0,0,150));
    ui->mltextEdit->setText(QString::number(bi));
    ui->mltextEdit->setAlignment(Qt::AlignCenter);
    ui->mltextEdit->setTextColor(Qt::lightGray);
    ui->mltextEdit->append("------");
    ui->mltextEdit->setCurrentFont(font);
    ui->mltextEdit->setAlignment(Qt::AlignCenter);
    ui->mltextEdit->setTextColor(Qt::black);
    ui->mltextEdit->append(QString::number(i));
    font.setBold(false);
    ui->mltextEdit->setCurrentFont(font);
    ui->mltextEdit->setAlignment(Qt::AlignCenter);
    ui->mltextEdit->setTextColor(Qt::lightGray);
    ui->mltextEdit->append("------");
    ui->mltextEdit->setAlignment(Qt::AlignCenter);
    ui->mltextEdit->setTextColor(QColor::fromRgb(0,0,0,150));
    ui->mltextEdit->append(QString::number(ai));
    ui->mltextEdit->setAlignment(Qt::AlignCenter);
    ui->mlNumber->display(QString("%1").arg(i, 2, 10, QChar('0')));
}
