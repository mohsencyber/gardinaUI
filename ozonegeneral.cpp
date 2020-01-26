#include "ozonegeneral.h"
#include "ui_ozonegeneral.h"
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

    connect( ui->secSpin,SIGNAL(valueChanged(int)),ui->secNumber,SLOT(display(int)));
    connect( ui->minSpin,SIGNAL(valueChanged(int)),ui->minNumber,SLOT(display(int)));
    connect( ui->hourSpin,SIGNAL(valueChanged(int)),ui->hourNumber,SLOT(display(int)));
}

OzoneGeneral::~OzoneGeneral()
{
    delete ui;
}

void OzoneGeneral::on_pushButton_clicked()
{
    close();
}

void OzoneGeneral::on_secSpin_valueChanged(int arg1)
{
    //ui->secNumber->display(arg1);
}
