#include "infection.h"
#include "ui_infection.h"
#include "infectionconf.h"
#include <QMessageBox>

Infection::Infection(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Infection)
{
    ui->setupUi(this);
    m_timeLeft = new TimeLeft();
    this->setStyleSheet( " #Infection { "
                         " border-image: url(:/gardina_main_bg.png) 0 0 0 0 stretch stretch;"
                         "}");

    //connect( ui->mlSpin,SIGNAL(valueChanged(int)),ui->mlNumber,SLOT(setText(int)));
    ui->hourSpin->setValue(0);
    ui->minSpin->setValue(0);
    ui->secSpin->setValue(0);
    ui->mlSpin->setValue(1);

    ui->minSpin->setVisible(false);
    ui->startButton->setEnabled(false);

    m_minTouch = new QTouchSpinBox(ui->frame);
    m_minTouch->setStep(1);
    m_minTouch->setMinMax(0,59);
    m_minTouch->setCurrent(0);
    m_minTouch->setNumbersShow(3);
    m_minTouch->setGeometry(145,158,70,125);
    m_minTouch->setStyleSheet("background-color: rgb(0, 0, 255,20%);"
                              "font: 75 12pt \"Waree\";"
                              "qproperty-alignment: AlignCenter;");

    connect(m_minTouch, &QTouchSpinBox::MovedUp , ui->minSpin , &QSpinBox::stepUp );
    connect(m_minTouch, &QTouchSpinBox::MovedDown , ui->minSpin , &QSpinBox::stepDown );

    ui->hourSpin->setVisible(false);

    m_hourTouch = new QTouchSpinBox(ui->frame);
    m_hourTouch->setStep(1);
    m_hourTouch->setMinMax(0,12);
    m_hourTouch->setCurrent(0);
    m_hourTouch->setNumbersShow(3);
    m_hourTouch->setGeometry(30,158,70,125);
    m_hourTouch->setStyleSheet("background-color: rgb(0, 0, 255,20%);"
                              "font: 75 12pt \"Waree\";"
                              "qproperty-alignment: AlignCenter;");

    connect(m_hourTouch, &QTouchSpinBox::MovedUp , ui->hourSpin , &QSpinBox::stepUp );
    connect(m_hourTouch, &QTouchSpinBox::MovedDown , ui->hourSpin , &QSpinBox::stepDown );

    ui->secSpin->setVisible(false);

    m_secTouch = new QTouchSpinBox(ui->frame);
    m_secTouch->setStep(1);
    m_secTouch->setMinMax(0,59);
    m_secTouch->setCurrent(0);
    m_secTouch->setNumbersShow(3);
    m_secTouch->setGeometry(250,158,70,125);
    m_secTouch->setStyleSheet("background-color: rgb(0, 0, 255,20%);"
                              "font: 75 12pt \"Waree\";"
                              "qproperty-alignment: AlignCenter;");
    connect(m_secTouch, &QTouchSpinBox::MovedUp , ui->secSpin , &QSpinBox::stepUp );
    connect(m_secTouch, &QTouchSpinBox::MovedDown , ui->secSpin , &QSpinBox::stepDown );

    ui->mlSpin->setVisible(false);

    m_mlTouch = new QTouchSpinBox(ui->frame);
    m_mlTouch->setStep(1);
    m_mlTouch->setMinMax(1,80);
    m_mlTouch->setCurrent(1);
    m_mlTouch->setNumbersShow(3);
    m_mlTouch->setGeometry(390,158,70,125);
    m_mlTouch->setStyleSheet("background-color: rgb(0, 0, 255,20%);"
                              "font: 75 12pt \"Waree\";"
                              "qproperty-alignment: AlignCenter;");

    connect(m_mlTouch, &QTouchSpinBox::MovedUp , ui->mlSpin , &QSpinBox::stepUp );
    connect(m_mlTouch, &QTouchSpinBox::MovedDown , ui->mlSpin , &QSpinBox::stepDown );


    m_hourTouch->setAttribute(Qt::WA_TranslucentBackground);
    m_minTouch->setAttribute(Qt::WA_TranslucentBackground);
    m_secTouch->setAttribute(Qt::WA_TranslucentBackground);
    m_mlTouch->setAttribute(Qt::WA_TranslucentBackground);

    ui->mlNumber->setText(QString("%1").arg(1, 2, 10, QChar('0')));
    ui->secNumber->setText(QString("%1").arg(0, 2, 10, QChar('0')));
    ui->minNumber->setText(QString("%1").arg(0, 2, 10, QChar('0')));
    ui->hourNumber->setText(QString("%1").arg(0, 2, 10, QChar('0')));

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTimer()));
}

Infection::~Infection()
{
    delete m_timeLeft;
    delete m_minTouch ;
    delete m_hourTouch ;
    delete m_secTouch ;
    delete m_mlTouch;
    delete ui;
}

void Infection::on_startButton_clicked()
{
    ui->startButton->setDisabled(true);
    ui->pushButton->setDisabled(true);
    m_serialport->open();
    start();
    timer->setInterval(1000);
    timer->start();
    m_userMin = ui->minSpin->value();
    m_userSec = ui->secSpin->value();
    m_userHour= ui->hourSpin->value();
}

void Infection::on_stopButton_clicked()
{
    const QString title="",body="Ozone Stopped.";
    stop();
    if ( m_userMin+m_userSec+m_userHour )
        ui->startButton->setDisabled(false);
    ui->pushButton->setDisabled(false);
    timer->stop();
    ui->hourSpin->setValue(m_userHour);
    ui->minSpin->setValue(m_userMin);
    ui->secSpin->setValue(m_userSec);
    //QMessageBox::information(this,title,body,QMessageBox::Ok);
}

void Infection::on_pushButton_clicked()
{
    m_serialport->waitforwrite();
    m_serialport->close();
    timer->stop();
    this->cursor().setPos(5,5);
    close();
}


void Infection::on_mconfigButton_clicked()
{
    InfectionConf *infectionConf = new InfectionConf();
    infectionConf->setValues(ui->hourSpin->value(),ui->minSpin->value(),ui->secSpin->value(),ui->mlSpin->value());
    infectionConf->setSerialport(m_serialport);
    infectionConf->showFullScreen();
}

/*void Infection::on_mlSpin_valueChanged(int arg1)
{
    arg1;
}*/

void Infection::on_secSpin_valueChanged(int arg1)
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

    ui->secNumber->setText(QString("%1").arg(i, 2, 10, QChar('0')));
    if ( m_secTouch )
    {
        m_secTouch->setCurrent(i);
        m_secTouch->refresh();
    }

    if ( ui->hourNumber->text().toInt()+ui->minNumber->text().toInt()+ui->secNumber->text().toInt() > 0 && !(timer->isActive())  )
        ui->startButton->setEnabled(true);
    else
        ui->startButton->setEnabled(false);

}

void Infection::on_minSpin_valueChanged(int arg1)
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


    ui->minNumber->setText(QString("%1").arg(i, 2, 10, QChar('0')));
    if ( m_minTouch )
    {
        m_minTouch->setCurrent(i);
        m_minTouch->refresh();
    }

    if ( ui->hourNumber->text().toInt()+ui->minNumber->text().toInt()+ui->secNumber->text().toInt() > 0 && !(timer->isActive())  )
        ui->startButton->setEnabled(true);
    else
        ui->startButton->setEnabled(false);
}

void Infection::on_hourSpin_valueChanged(int arg1)
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


    ui->hourNumber->setText(QString("%1").arg(i, 2, 10, QChar('0')));
    if ( m_hourTouch )
    {
        m_hourTouch->setCurrent(i);
        m_hourTouch->refresh();
    }


    if ( ui->hourNumber->text().toInt()+ui->minNumber->text().toInt()+ui->secNumber->text().toInt() > 0 && !(timer->isActive()) )
        ui->startButton->setEnabled(true);
    else
        ui->startButton->setEnabled(false);
}

void Infection::updateTimer()
{
    if ( ui->hourSpin->value() == 0 &&
         ui->minSpin->value() == 0 &&
         ui->secSpin->value() == 0 )
    {
        end();
        timer->stop();
        ui->startButton->setDisabled(false);
        ui->pushButton->setDisabled(false);
        ui->hourSpin->setValue(m_userHour);
        ui->minSpin->setValue(m_userMin);
        ui->secSpin->setValue(m_userSec);
    }else{
        m_timeLeft->incTime();
        start();
        ui->secSpin->stepDown();
    }
}

void Infection::setSerialport(MySerialPort *serialport)
{
    m_serialport = serialport;
}

void Infection::start()
{
    QString strStart = QString::number(ui->mlNumber->text().toInt() )+"\n";
    int interval=0;
    m_serialport->open();
    if ( m_serialport->isOpen())
    {
        m_serialport->write(strStart.toUtf8(),interval);
    }
}

void Infection::stop()
{
    QString strStop = "0\n";
    int interval = 0;
    if ( m_serialport->isOpen())
    {
        m_serialport->write(strStop.toUtf8(),interval);
    }
}

void Infection::end()
{
    QString end = "500\n";
    int interval= 0;
    stop();
    if ( m_serialport->isOpen())
    {
        m_serialport->write(end.toUtf8(),interval);
    }

}

void Infection::on_mlSpin_valueChanged(int arg1)
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
    ui->mlNumber->setText(QString("%1").arg(i, 2, 10, QChar('0')));
    if ( m_mlTouch )
    {
        m_mlTouch->setCurrent(i);
        m_mlTouch->refresh();
    }
}
