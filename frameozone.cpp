#include "frameozone.h"
#include "ui_frameozone.h"
#include "ozonegeneral.h"

FrameOzone::FrameOzone(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::FrameOzone)
{
    ui->setupUi(this);
    this->setStyleSheet(" #FrameOzone { border:none; border-image: url(:/gardina_main_bg.png) 0 0 0 0 stretch stretch; }");
}

FrameOzone::~FrameOzone()
{
    delete ui;
}

void FrameOzone::on_backButton_clicked()
{
    close();
}

void FrameOzone::on_general_button_clicked()
{
    OzoneGeneral *ozoneGeneral = new OzoneGeneral();
    ozoneGeneral->showFullScreen();
}
