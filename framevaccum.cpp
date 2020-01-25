#include "framevaccum.h"
#include "ui_framevaccum.h"

Framevaccum::Framevaccum(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Framevaccum)
{
    ui->setupUi(this);
    //ui->backbutton
    this->setStyleSheet( "#Framevaccum { "
                         " border-image: url(:/images/gardina_main_bg.png) 0 0 0 0 stretch stretch;"
                         "}");
}

Framevaccum::~Framevaccum()
{
    delete ui;
}

void Framevaccum::on_backbutton_clicked()
{
    close();
}
