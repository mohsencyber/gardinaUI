#include "infection.h"
#include "ui_infection.h"
#include "infectionconf.h"
#include <QMessageBox>

Infection::Infection(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Infection)
{
    ui->setupUi(this);
    this->setStyleSheet( " #Infection { "
                         " border:none;border-image: url(:/gardina_main_bg.png) 0 0 0 0 stretch stretch;"
                         "}");

    connect( ui->mlSpin,SIGNAL(valueChanged(int)),ui->mlNumber,SLOT(display(int)));

    connect(ui->hourminus,SIGNAL(clicked()),ui->hourSpin,SLOT( stepDown() ));
    connect(ui->hourplus,SIGNAL(clicked()),ui->hourSpin,SLOT( stepUp() ));

    connect(ui->minminus,SIGNAL(clicked()),ui->minSpin,SLOT( stepDown() ));
    connect(ui->minplus,SIGNAL(clicked()),ui->minSpin,SLOT( stepUp() ));

    connect(ui->secminus,SIGNAL(clicked()),ui->secSpin,SLOT( stepDown() ));
    connect(ui->secplus,SIGNAL(clicked()),ui->secSpin,SLOT( stepUp() ));

    connect(ui->mlminus,SIGNAL(clicked()),ui->mlSpin,SLOT( stepDown() ));
    connect(ui->mlplus,SIGNAL(clicked()),ui->mlSpin,SLOT( stepUp() ));

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTimer()));
}

Infection::~Infection()
{
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
}

void Infection::on_stopButton_clicked()
{
    const QString title="",body="Ozone Stopped.";
    stop();
    ui->startButton->setDisabled(false);
    ui->pushButton->setDisabled(false);
    timer->stop();
    QMessageBox::information(this,title,body,QMessageBox::Ok);
}

void Infection::on_pushButton_clicked()
{
    m_serialport->waitforwrite();
    m_serialport->close();
    timer->stop();
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

    ui->secNumber->display(ui->secSpin->value());
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

    ui->minNumber->display(ui->minSpin->value());
}

void Infection::on_hourSpin_valueChanged(int arg1)
{
    if ( arg1 == 24 ){
        ui->hourSpin->setValue(0);
    }
    if ( arg1 == -1){
        ui->hourSpin->setValue(23);
    }

    ui->hourNumber->display(ui->hourSpin->value());
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
    }else{
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
    QString strStart = QString::number(ui->mlNumber->intValue() )+"\n";
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
