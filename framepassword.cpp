#include "framepassword.h"
#include "ui_framepassword.h"

FramePassword::FramePassword(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::FramePassword)
{
    ui->setupUi(this);
    this->setStyleSheet(" #FramePassword {  border-image: url(:/gardina_main_bg.png) 0 0 0 0 stretch stretch; }");
    m_userName = new myLineEdit(this);
    m_userName->setGeometry(145,100,615,30);

    m_passWord = new myLineEdit(this);
    m_passWord->setGeometry(145,150,615,30);
    m_passWord->setEchoMode(QLineEdit::PasswordEchoOnEdit);

    QSettings setting("/home/pi/myapp/gardinapw.cfg",QSettings::IniFormat);
    QSettings settingtik("/home/pi/myapp/gardina.cfg",QSettings::IniFormat);
    QString l_username = setting.value("username").toString();
    QString l_password = setting.value("password").toString();
    if (settingtik.value("secure","no").toString().toUpper()=="YES" )
    {
        ui->authenticate->setCheckState(Qt::CheckState::Checked);
        m_userName->setText(l_username);
        m_passWord->setText("********");
    }

    m_username = l_username;
    m_password = l_password;

    ui->passWord->setEnabled(false);
    ui->passWord->setVisible(false);
    ui->userName->setEnabled(false);
    ui->userName->setVisible(false);

}

FramePassword::~FramePassword()
{
    delete m_passWord;
    delete m_userName;
    delete ui;
}

void FramePassword::on_backButton_clicked()
{
    close();
}

void FramePassword::on_saveButton_clicked()
{
    QSettings setting("/home/pi/myapp/gardina.cfg",QSettings::IniFormat);
    QSettings pwsetting("/home/pi/myapp/gardinapw.cfg",QSettings::IniFormat);

    if ( ui->authenticate->isChecked() ){
        m_password = m_passWord->text();// ui->passWord->text();
        QCryptographicHash hashPass(QCryptographicHash::Sha1);
        hashPass.addData(m_password.toUtf8());
        QString l_hashPass = hashPass.result().toHex();
        m_password = l_hashPass;
        m_username = m_userName->text(); //ui->userName->text();
        pwsetting.setValue("username",m_username);
        pwsetting.setValue("password",m_password);
        pwsetting.sync();
        setting.setValue("secure","yes");
        setting.sync();
        ui->message->setText(tr("password saved."));
    }else{
        setting.setValue("secure","no");
        setting.sync();
        ui->message->setText(tr("password removed."));
    }
}
