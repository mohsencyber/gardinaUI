#include "frameabout.h"
#include "ui_frameabout.h"

FrameAbout::FrameAbout(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::FrameAbout)
{
    ui->setupUi(this);
    this->setStyleSheet(" #FrameAbout { border:none; border-image: url(:/about_page_bg.jpg) 0 0 0 0 stretch stretch; }");
}

FrameAbout::~FrameAbout()
{
    delete ui;
}

void FrameAbout::on_backButton_clicked()
{
    close();
}
