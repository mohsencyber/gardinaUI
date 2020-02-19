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

    this->setStyleSheet( " #OzoneGeneral { "
                         " border:none;border-image: url(:/gardina_main_bg.png) 0 0 0 0 stretch stretch;"
                         "}");

    //connect( ui->secSpin,SIGNAL(valueChanged(int)),ui->secNumber,SLOT(display(int)));
    //connect( ui->minSpin,SIGNAL(valueChanged(int)),ui->minNumber,SLOT(display(int)));
    //connect( ui->hourSpin,SIGNAL(valueChanged(int)),ui->hourNumber,SLOT(display(int)));
    connect( ui->mlSpin,SIGNAL(valueChanged(int)),ui->mlNumber,SLOT(display(int)));

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

OzoneGeneral::~OzoneGeneral()
{
    delete ui;
}

void OzoneGeneral::on_pushButton_clicked()
{
    timer->stop();
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

    ui->secNumber->display(ui->secSpin->value());
}

void OzoneGeneral::on_mconfigButton_clicked()
{
    ozoneGeneralConf *generalConf = new ozoneGeneralConf();
    generalConf->setValues(ui->hourSpin->value(),ui->minSpin->value(),ui->secSpin->value(),ui->mlSpin->value());
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

    ui->minNumber->display(ui->minSpin->value());
}

void OzoneGeneral::on_hourSpin_valueChanged(int arg1)
{
    if ( arg1 == 24 ){
        ui->hourSpin->setValue(0);
    }
    if ( arg1 == -1){
        ui->hourSpin->setValue(23);
    }

    ui->hourNumber->display(ui->hourSpin->value());
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
    timer->setInterval(1000);
    timer->start();
}

void OzoneGeneral::on_stopButton_clicked()
{
    ui->startButton->setDisabled(false);
    ui->pushButton->setDisabled(false);
    ui->touchButton->setDisabled(false);
    timer->stop();
}

void OzoneGeneral::on_touchButton_clicked()
{
    ui->hourSpin->setValue(0);
    ui->minSpin->setValue(0);
    ui->secSpin->setValue(0);
    ui->mlSpin->setValue(1);
    timer->stop();
}

void OzoneGeneral::updateTimer()
{
    if ( ui->hourSpin->value() == 0 &&
         ui->minSpin->value() == 0 &&
         ui->secSpin->value() == 0 )
    {
        timer->stop();
        ui->startButton->setDisabled(false);
        ui->pushButton->setDisabled(false);
        ui->touchButton->setDisabled(false);

    }else
        ui->secSpin->stepDown();
}
