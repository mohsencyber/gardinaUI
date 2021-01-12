#include "formvaccum.h"
#include "ui_formvaccum.h"
#include <QStyleOption>
#include <QPainter>
#include <QTimer>
#include <QTouchEvent>

FormVaccum::FormVaccum(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormVaccum)
{
    ui->setupUi(this);
    this->setStyleSheet(" #FormVaccum { border:none; border-image: url(:/gardina_main_bg.png) 0 0 0 0 stretch stretch; }");

    ui->minSpin->setValue(0);
    ui->minSpin->setVisible(false);

    m_minTouch = new QTouchSpinBox(ui->frame);
    m_minTouch->setStep(1);
    m_minTouch->setMinMax(0,60);
    m_minTouch->setCurrent(0);
    m_minTouch->setNumbersShow(3);
    m_minTouch->setGeometry(107,172,70,125);
    m_minTouch->setStyleSheet("background-color: rgb(0, 0, 255,20%);"
                              "font: 75 12pt \"Waree\";"
                              "qproperty-alignment: AlignCenter;");
    connect(m_minTouch, &QTouchSpinBox::MovedUp , ui->minSpin , &QSpinBox::stepUp );
    connect(m_minTouch, &QTouchSpinBox::MovedDown , ui->minSpin , &QSpinBox::stepDown );


    ui->minSpin->setAcceptDrops(true);

    ui->minSpin->setAttribute(Qt::WA_AcceptTouchEvents);
    m_minTouch->setAttribute(Qt::WA_TranslucentBackground);
    ui->minNumber->setText(QString("%1").arg(0, 2, 10, QChar('0')));
    ui->secNumber->setText(QString("%1").arg(0, 2, 10, QChar('0')));
    timer = new  QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTimer()));
    ui->startButton->setEnabled(false);

}

FormVaccum::~FormVaccum()
{
    delete m_minTouch;
    delete ui;
}

void FormVaccum::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void FormVaccum::setSerialport(MySerialPort *serialport)
{
    m_serialport = serialport;
}

void FormVaccum::on_pushButton_clicked()
{
   m_serialport->waitforwrite();
   m_serialport->close();
   timer->stop();
   this->cursor().setPos(5,5);
   close();
}

void FormVaccum::on_minplus_clicked()
{

}

void FormVaccum::on_minminus_clicked()
{

}

void FormVaccum::on_minSpin_valueChanged(int arg1)
{
    if ( arg1 == 61 ) {
        ui->minSpin->setValue(0);
    }
    if ( arg1 == -1 ){
        ui->minSpin->setValue(60);
    }

    int i = ui->minSpin->value();
    int bi,ai;
    bi=i-1;ai=i+1;
    if (bi==-1) bi = 60;
    if (ai==61) ai = 0;
    ui->minNumber->setText(QString("%1").arg(i, 2, 10, QChar('0')));

    if ( ui->minNumber->text().toInt()+ui->secNumber->text().toInt() > 0  )
        ui->startButton->setEnabled(true);
    else
        ui->startButton->setEnabled(false);


}

void FormVaccum::on_startButton_clicked()
{
    ui->startButton->setEnabled(false);
    ui->pushButton->setEnabled(false);
    start();
    timer->setInterval(1000);
    timer->start();
    m_Min = ui->minNumber->text().toInt();
    m_Sec = ui->secNumber->text().toInt();
    m_UserMin = ui->minSpin->value();
}

void FormVaccum::on_stopButton_clicked()
{
    if ( m_UserMin )
        ui->startButton->setEnabled(true);
    ui->pushButton->setEnabled(true);
    stop();
    timer->stop();
    ui->minNumber->setText(QString("%1").arg(m_UserMin, 2, 10, QChar('0')));
    m_minTouch->setCurrent(m_UserMin);
    m_minTouch->refresh();
    ui->secNumber->setText(QString("%1").arg(0, 2, 10, QChar('0')));
    ui->minSpin->setValue(m_UserMin);
}

void FormVaccum::updateTimer()
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
        ui->secNumber->setText(QString("%1").arg(m_Sec, 2, 10, QChar('0')));
        ui->minNumber->setText(QString("%1").arg(m_Min, 2, 10, QChar('0')));
        m_minTouch->setCurrent(m_Min);
        m_minTouch->refresh();
    }else{
        //ui->startButton->setEnabled(true);
        ui->pushButton->setEnabled(true);
        end();
        timer->stop();
        ui->minSpin->setValue(m_UserMin);
        ui->minNumber->setText(QString("%1").arg(m_UserMin, 2, 10, QChar('0')));
        m_minTouch->setCurrent(m_UserMin);
        m_minTouch->refresh();
    }
}


void FormVaccum::start()
{
    QString strStart="100\n";
    int interval=0;
    m_serialport->open();
    if ( m_serialport->isOpen())
    {
        m_serialport->write(strStart.toUtf8(),interval);
    }

}

void FormVaccum::stop()
{
    QString strStop = "200\n";
    int interval = 0;
    if ( m_serialport->isOpen())
    {
        m_serialport->write(strStop.toUtf8(),interval);
    }
}

void FormVaccum::end()
{
    QString end = "500\n";
    int interval= 0;
    stop();
    if ( m_serialport->isOpen())
    {
        m_serialport->write(end.toUtf8(),interval);
    }

}
