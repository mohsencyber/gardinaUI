#include "framenewaccess.h"
#include "ui_framenewaccess.h"

FrameNewAccess::FrameNewAccess(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::FrameNewAccess)
{
    ui->setupUi(this);
}

FrameNewAccess::~FrameNewAccess()
{
    delete ui;
}
