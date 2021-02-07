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

    this->setStyleSheet( " #FormOxygen {  border-image: url(:/gardina_main_bg.png) 0 0 0 0 stretch stretch;}");
    ui->minSpin->setValue(0);
    ui->minSpin->setVisible(false);
    //ui->textEdit->setVisible(false);

    m_minTouch = new QTouchSpinBox(ui->frame);
    m_minTouch->setStep(1);
    m_minTouch->setMinMax(0,59);
    m_minTouch->setCurrent(0);
    m_minTouch->setNumbersShow(3);
    m_minTouch->setGeometry(110,180,70,125);
    m_minTouch->setStyleSheet("background-color: rgb(0, 0, 255,30%);"
                              "font: 75 12pt \"Waree\";"
                              "qproperty-alignment: AlignCenter;");
    connect(m_minTouch, &QTouchSpinBox::MovedUp , ui->minSpin , &QSpinBox::stepUp );
    connect(m_minTouch, &QTouchSpinBox::MovedDown , ui->minSpin , &QSpinBox::stepDown );

    timer = new  QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTimer()));
    ui->minSpin->setAttribute(Qt::WA_AcceptTouchEvents);
    m_minTouch->setAttribute(Qt::WA_TranslucentBackground);

    ui->secNumber->setText(QString("%1").arg(0, 2, 10, QChar('0')));
    ui->minNumber->setText(QString::number(0).rightJustified(2,'0'));
    ui->startButton->setEnabled(false);

    /*const auto portInfo = QSerialPortInfo::availablePorts();
    QString ports;
    for (const QSerialPortInfo &info : portInfo)
        ports += info.portName()+"-";
    ui->label_2->setText(ports);*/

}

FormOxygen::~FormOxygen()
{
    delete m_minTouch;
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
    this->cursor().setPos(5,5);
    close();
}

void FormOxygen::on_startButton_clicked()
{
    ui->startButton->setDisabled(true);
    ui->pushButton->setDisabled(true);
    start();
    timer->setInterval(1000);
    timer->start();
    m_Min = ui->minNumber->text().toInt();
    m_Sec = ui->secNumber->text().toInt();
    m_userMin = ui->minSpin->value();

}

void FormOxygen::on_stopButton_clicked()
{
    if ( m_userMin )
        ui->startButton->setDisabled(false);
    ui->pushButton->setDisabled(false);
    stop();
    timer->stop();
    ui->minNumber->setText(QString::number(m_userMin).rightJustified(2,'0'));
    m_minTouch->setCurrent(m_userMin);
    m_minTouch->refresh();
    ui->secNumber->setText(QString("%1").arg(0, 2, 10, QChar('0')));
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
        ui->minSpin->setValue(0);
    }
    if ( arg1 == -1 ){
        ui->minSpin->setValue(59);
    }

    int i = ui->minSpin->value();
    int bi,ai;
    bi=i-1;ai=i+1;
    if (bi==-1) bi = 59;
    if (ai==60) ai = 0;
//    QFont font(ui->textEdit->font());
//    font.setBold(true);

//    QString ViewStr = QString::number(bi);
//    ui->textEdit->setTextColor(QColor::fromRgb(0,0,0,200));
//    ui->textEdit->setText(ViewStr);
//    ui->textEdit->setAlignment(Qt::AlignCenter);
//    ui->textEdit->setTextColor(Qt::lightGray);
//    ui->textEdit->append("------");
//    ui->textEdit->setAlignment(Qt::AlignCenter);
//    ui->textEdit->setTextColor(Qt::black);
//    ui->textEdit->setCurrentFont(font);
//    //ui->textEdit->setfont(font.setBold(true));
//    ui->textEdit->append(QString::number(i));
//    ui->textEdit->setAlignment(Qt::AlignCenter);
//    ui->textEdit->setTextColor(Qt::lightGray);
//    font.setBold(false);
//    ui->textEdit->setCurrentFont(font);
//    //ui->textEdit->setfont(font.setBold(false));
//    ui->textEdit->append("------");
//    ui->textEdit->setAlignment(Qt::AlignCenter);
//    ui->textEdit->setTextColor(QColor::fromRgb(0,0,0,200));
//    ui->textEdit->append(QString::number(ai));
//    ui->textEdit->setAlignment(Qt::AlignCenter);

    ui->minNumber->setText(QString::number(i).rightJustified(2,'0'));

    if ( ui->minNumber->text().toInt() +ui->secNumber->text().toInt() > 0  )
        ui->startButton->setEnabled(true);
    else
        ui->startButton->setEnabled(false);
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
        ui->secNumber->setText(QString("%1").arg(m_Sec, 2, 10, QChar('0')));
        ui->minNumber->setText(QString::number(m_Min).rightJustified(2,'0'));
        m_minTouch->setCurrent(m_Min);
        m_minTouch->refresh();
    }else{
        //ui->startButton->setEnabled(true);
        ui->pushButton->setEnabled(true);
        end();
        timer->stop();
        ui->minSpin->setValue(m_userMin);
        ui->minNumber->setText(QString::number(m_userMin).rightJustified(2,'0'));
        ui->startButton->setEnabled(true);
        m_minTouch->setCurrent(m_userMin);
        m_minTouch->refresh();
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
