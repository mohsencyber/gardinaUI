#include "frameabout.h"
#include "ui_frameabout.h"

FrameAbout::FrameAbout(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::FrameAbout)
{
    ui->setupUi(this);
    this->setStyleSheet(" #FrameAbout { border-image: url(:/gardina_main_bg.png) 0 0 0 0 stretch stretch; }");
    //ui->textBrowser->setAttribute(Qt::WA_TranslucentBackground);
}

FrameAbout::~FrameAbout()
{
    delete ui;
}

void FrameAbout::on_backButton_clicked()
{
    close();
}
