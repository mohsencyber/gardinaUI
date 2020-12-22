#include "framelogin.h"
#include "ui_framelogin.h"
#include <QSettings>
#include <QCryptographicHash>


FrameLogin::FrameLogin(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::FrameLogin)
{
    ui->setupUi(this);
    this->setStyleSheet(" #FrameLogin { border:none; border-image: url(:/gardina_main_bg.png) 0 0 0 0 stretch stretch; }");
    //ui->password->setEchoMode(QLineEdit::Password);
    ui->message->setVisible(false);
    m_username = new myLineEdit(this);
    m_username->setGeometry(260,85,300,30);

    m_password = new myLineEdit(this);
    m_password->setGeometry(260,125,300,30);
    m_password->setEchoMode(QLineEdit::Password);

    ui->password->setDisabled(true);
    ui->password->setVisible(false);
    ui->username->setEnabled(false);
    ui->username->setVisible(false);
}

FrameLogin::~FrameLogin()
{
    delete m_username;
    delete m_password;
    delete ui;
}

void FrameLogin::on_login_clicked()
{
    QSettings pwsetting("/home/pi/myapp/gardinapw.cfg",QSettings::IniFormat);
    QString username = pwsetting.value("username").toString();
    QString hashPass = pwsetting.value("password").toString();
    QString loginuser , loginpass , loginhashpass;
    QCryptographicHash lhashPass(QCryptographicHash::Sha1);

    //loginuser = ui->username->text();
    //loginpass = ui->password->text();
    loginuser = m_username->text();
    loginpass = m_password->text();

    lhashPass.addData(loginpass.toUtf8());
    loginhashpass = lhashPass.result().toHex();
    if ( loginuser == username &&
         hashPass == loginhashpass )
        close();
    ui->message->setVisible(true);
}
