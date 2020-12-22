#include "framelang.h"
#include <QButtonGroup>
#include "ui_framelang.h"

FrameLang::FrameLang(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::FrameLang)
{
    ui->setupUi(this);
    this->setStyleSheet(" #FrameLang { border:none; border-image: url(:/gardina_main_bg.png) 0 0 0 0 stretch stretch; }");

    radioButtons = new QButtonGroup();
    radioButtons->addButton(ui->engButton ,0);
    ui->engButton->setChecked(true);
    radioButtons->addButton(ui->perButton,1);
    radioButtons->setExclusive(true);
}

FrameLang::~FrameLang()
{
    delete ui;
}

void FrameLang::on_backButton_clicked()
{
    close();
}
