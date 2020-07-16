#include "formOxygen.h"
#include "ui_formOxygen.h"
#include <QStyleOption>
#include <QPainter>
#include <QSerialPortInfo>
#include "qtouchspinbox.h"

FormOxygen::FormOxygen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormOxygen)
{
    ui->setupUi(this);

    this->setStyleSheet( " #FormOxygen { border:none; border-image: url(:/gardina_main_bg.png) 0 0 0 0 stretch stretch;}");
    ui->minSpin->setValue(1);
    ui->minSpin->setVisible(false);

    connect(ui->textEdit, &QTouchSpinBox::MovedUp , ui->minSpin , &QSpinBox::stepUp );
    connect(ui->textEdit, &QTouchSpinBox::MovedDown , ui->minSpin , &QSpinBox::stepDown );

    timer = new  QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTimer()));
    ui->minSpin->setAttribute(Qt::WA_AcceptTouchEvents);
    ui->textEdit->setAttribute(Qt::WA_TranslucentBackground);

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
    m_userMin = ui->minSpin->value();

}

void FormOxygen::on_stopButton_clicked()
{
    ui->startButton->setDisabled(false);
    ui->pushButton->setDisabled(false);
    stop();
    timer->stop();
    ui->minNumber->display(m_userMin);
    ui->secNumber->display(0);
    ui->minSpin->setValue(m_userMin);
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
        ui->minSpin->setValue(1);
    }
    if ( arg1 == 0 ){
        ui->minSpin->setValue(59);
    }
    int i = ui->minSpin->value();
    int bi,ai;
    bi=i-1;ai=i+1;
    if (bi==0) bi = 59;
    if (ai==60) ai = 1;
    QString ViewStr = QString::number(bi);
    ui->textEdit->setTextColor(QColor::fromRgb(0,0,0,150));
    ui->textEdit->setText(ViewStr);
    ui->textEdit->setAlignment(Qt::AlignCenter);
    ui->textEdit->setTextColor(Qt::lightGray);
    ui->textEdit->append("------");
    ui->textEdit->setAlignment(Qt::AlignCenter);
    ui->textEdit->setTextColor(Qt::black);
    ui->textEdit->append(QString::number(i));
    ui->textEdit->setAlignment(Qt::AlignCenter);
    ui->textEdit->setTextColor(Qt::lightGray);
    ui->textEdit->append("------");
    ui->textEdit->setAlignment(Qt::AlignCenter);
    ui->textEdit->setTextColor(QColor::fromRgb(0,0,0,150));
    ui->textEdit->append(QString::number(ai));
    ui->textEdit->setAlignment(Qt::AlignCenter);
    ui->minNumber->display(i);
}

void FormOxygen::updateTimer()
{
    m_Sec-- ;
    if ( m_Sec < 0 )
    {
        m_Min-- ;
        //ui->minSpin->stepDown();
        m_Sec = 59 ;
    }
    if ( m_Min > -1 )
    {
        ui->secNumber->display(m_Sec);
        ui->minNumber->display(m_Min);
    }else{
        ui->startButton->setEnabled(true);
        ui->pushButton->setEnabled(true);
        end();
        timer->stop();
        ui->minSpin->setValue(m_userMin);
        ui->minNumber->display(m_userMin);
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
