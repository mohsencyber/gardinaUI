#include "dialogtllogin.h"
#include "ui_dialogtllogin.h"

DialogTLLogin::DialogTLLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogTLLogin)
{
    ui->setupUi(this);
    this->setStyleSheet(" #DialogTLLogin { border:none; border-image: url(:/gardina_main_bg.png) 0 0 0 0 stretch stretch; }");
    m_passIsOk = false;
}

DialogTLLogin::~DialogTLLogin()
{
    delete ui;
}

void DialogTLLogin::on_pushButton_clicked()
{
    if ( ui->lineEdit->text() == "nabandishan.co")
    {
        m_passIsOk = true;
    }
    close();
}
