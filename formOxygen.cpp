#include "formOxygen.h"
#include "ui_formOxygen.h"
#include <QStyleOption>
#include <QPainter>

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
    timer->stop();
    close();
}

void FormOxygen::on_startButton_clicked()
{
    ui->startButton->setDisabled(true);
    ui->pushButton->setDisabled(true);
    timer->setInterval(1000);
    timer->start();
    m_Min = ui->minNumber->intValue();
    m_Sec = ui->secNumber->intValue();
}

void FormOxygen::on_stopButton_clicked()
{
    ui->startButton->setDisabled(false);
    ui->pushButton->setDisabled(false);
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
        timer->stop();
    }
}
