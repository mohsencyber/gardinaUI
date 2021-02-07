#include "framecontact.h"
#include "ui_framecontact.h"

FrameContact::FrameContact(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::FrameContact)
{
    ui->setupUi(this);
    this->setStyleSheet(" #FrameContact { border-image: url(:/contact_bg.png) 0 0 0 0 stretch stretch; }");
}

FrameContact::~FrameContact()
{
    delete ui;
}

void FrameContact::on_backButton_clicked()
{
    close();
}
