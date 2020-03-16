#include "formOxygen.h"
#include "ui_formOxygen.h"
#include <QStyleOption>
#include <QPainter>
#include <QSerialPortInfo>

FormOxygen::FormOxygen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormOxygen)
{
    ui->setupUi(this);

    this->setStyleSheet( " #FormOxygen { border:none; border-image: url(:/gardina_main_bg.png) 0 0 0 0 stretch stretch;}");
    ui->minSpin->setValue(1);
    connect(ui->minminus,SIGNAL(clicked()),ui->minSpin,SLOT( stepDown() ));
    connect(ui->minplus,SIGNAL(clicked()),ui->minSpin,SLOT( stepUp() ));
    timer = new  QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTimer()));

    /*const auto portInfo = QSerialPortInfo::availablePorts();
    QString ports;
    for (const QSerialPortInfo &info : portInfo)
        ports += info.portName()+"-";
    ui->label_2->setText(ports);*/

}

FormOxygen::~FormOxygen()
{
    delete ui;
}

void FormOxygen::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void FormOxygen::on_pushButton_clicked()
{
    m_serialport->waitforwrite();
    m_serialport->close();
    timer->stop();
    close();
}

void FormOxygen::on_startButton_clicked()
{
    ui->startButton->setDisabled(true);
    ui->pushButton->setDisabled(true);
    start();
    timer->setInterval(1000);
    timer->start();
    m_Min = ui->minNumber->intValue();
    m_Sec = ui->secNumber->intValue();
}

void FormOxygen::on_stopButton_clicked()
{
    ui->startButton->setDisabled(false);
    ui->pushButton->setDisabled(false);
    stop();
    timer->stop();
}

void FormOxygen::on_minplus_clicked()
{

}

void FormOxygen::on_minminus_clicked()
{

}

void FormOxygen::on_minSpin_valueChanged(int arg1)
{
    if ( arg1 == 60 ) {
        ui->minSpin->setValue(0);
    }
    if ( arg1 == -1 ){
        ui->minSpin->setValue(59);
    }

    ui->minNumber->display(ui->minSpin->value());
}

void FormOxygen::updateTimer()
{
    m_Sec-- ;
    if ( m_Sec < 0 )
    {
        m_Min-- ;
        ui->minSpin->stepDown();
        m_Sec = 59 ;
    }
    if ( m_Min > -1 )
    {
        ui->secNumber->display(m_Sec);
    }else{
        ui->startButton->setEnabled(true);
        ui->pushButton->setEnabled(true);
        end();
        timer->stop();
    }
}

void FormOxygen::setSerialport(MySerialPort *serialport)
{
    m_serialport = serialport;
}
void FormOxygen::start()
{
    QString strStart="600\n";
    int interval=0;
    m_serialport->open();
    if ( m_serialport->isOpen())
    {
        m_serialport->write(strStart.toUtf8(),interval);
    }

}

void FormOxygen::stop()
{
    QString strStop = "700\n";
    int interval = 0;
    if ( m_serialport->isOpen())
    {
        m_serialport->write(strStop.toUtf8(),interval);
    }
}

void FormOxygen::end()
{
    QString end = "500\n";
    int interval= 0;
    stop();
    if ( m_serialport->isOpen())
    {
        m_serialport->write(end.toUtf8(),interval);
    }

}
