#include "frametllogin.h"
#include "ui_frametllogin.h"
#include "frametimeleft.h"
#include "mylineedit.h"

FrameTLLogin::FrameTLLogin(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::FrameTLLogin)
{
    ui->setupUi(this);
    //qputenv("QT_IM_MODULE",QByteArray("qtvirtualkeyboard"));
    //qputenv("QT_VIRTUALKEYBOARD_STYLE", QByteArray("retro"));
    //setAttribute(Qt::WA_InputMethodEnabled);
    this->setStyleSheet(" #FrameTLLogin { border:none; border-image: url(:/gardina_main_bg.png) 0 0 0 0 stretch stretch; }");
    //ui->lineEdit->setAttribute(Qt::WA_InputMethodEnabled);
    mylineedit = new myLineEdit(this);
    mylineedit->setGeometry(400,100,300,28);
    mylineedit->setEchoMode(QLineEdit::Password);
    //this->setl
    //mylineedit->setAttribute(Qt::WA_InputMethodEnabled);
    connect(mylineedit,&myLineEdit::returnPressed,[this]{this->focusNextChild();});
    ui->lineEdit->setEnabled(false);
    ui->lineEdit->setVisible(false);

    m_passIsOk = false;

}

FrameTLLogin::~FrameTLLogin()
{
    delete mylineedit;
    delete ui;
}

bool FrameTLLogin::getPassResult()
{
    return m_passIsOk;
}


void FrameTLLogin::on_pushButton_clicked()
{

    QString textInput = mylineedit->text();
    if (  textInput == "nabandishan.co")
    {
        m_passIsOk = true;
    }
    emit this->Closed();
    close();
}
