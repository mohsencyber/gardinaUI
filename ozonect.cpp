#include "ozonect.h"
#include "ui_ozonect.h"

OzoneCT::OzoneCT(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::OzoneCT)
{
    ui->setupUi(this);
}

OzoneCT::~OzoneCT()
{
    delete ui;
}
