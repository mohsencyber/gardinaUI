#include "frametimeleft.h"
#include "ui_frametimeleft.h"
#include "frametllogin.h"
#include "dialogtllogin.h"
#include <QJsonObject>
#include <QFile>
#include <QMessageBox>


//#include <QMessageBox>

FrameTimeLeft::FrameTimeLeft(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::FrameTimeLeft)
{

    ui->setupUi(this);
    m_timeLeft = new TimeLeft();
    m_passIsOk = false;
    this->setStyleSheet(" #FrameTimeLeft {  border-image: url(:/gardina_main_bg.png) 0 0 0 0 stretch stretch; }");
    //DialogTLLogin ttlogin(this);

    m_comment = new myLineEdit(this);
    m_comment->setGeometry(270,175,250,30);

    QString valfile;
    QFile memoryFile("/home/pi/myapp/tl.dat");
    memoryFile.open( QIODevice::ReadOnly | QIODevice::Text );
    valfile = memoryFile.readAll();
    memoryFile.close();
    memoryDoc = QJsonDocument::fromJson(valfile.toUtf8());
    QJsonObject memdocObj = memoryDoc.object();
    //QJsonValue values = memdocObj.value("memory");
    memoryArr = memdocObj["memory"].toArray();
    viewJsonArray();
    int l_hour=0,l_min=0,l_sec=0;
    m_timeLeft->getTimeLeft(l_hour,l_min,l_sec);
    ui->hours->setText(QString::number(l_hour).rightJustified(2,'0'));
    ui->min->setText(QString::number(l_min).rightJustified(2,'0'));
    ui->sec->setText(QString::number(l_sec).rightJustified(2,'0'));

    ui->lineEdit->setEnabled(false);
    ui->lineEdit->setVisible(false);
}

FrameTimeLeft::~FrameTimeLeft()
{
    delete m_timeLeft;
    delete m_comment;
    delete ui;
}

void FrameTimeLeft::PassIsOk()
{
    m_passIsOk = true;
}

void FrameTimeLeft::on_backButton_clicked()
{
    close();
}

void FrameTimeLeft::on_resetButton_clicked()
{
    QString comment = m_comment->text();//ui->lineEdit->text();
    if (!m_timeLeft->resetTL(comment)){
        QMessageBox::information(nullptr,"","Memory TimeLeft is Full.",QMessageBox::Ok);
        ui->resetallButton->setEnabled(true);
    }
    ui->hours->setText(QString::number(0).rightJustified(2,'0'));
    ui->min->setText(QString::number(0).rightJustified(2,'0'));
    ui->sec->setText(QString::number(0).rightJustified(2,'0'));
    m_comment->setText("");
    memoryArr = m_timeLeft->getMemory();
    viewJsonArray();

}

void FrameTimeLeft::viewJsonArray()
{
    int maxidx = memoryArr.size();

    for(int idx=0;idx < maxidx ; idx++ )
    {
        QJsonObject value = memoryArr[idx].toObject();
        //idx=value["idmem"].toInt();
        switch (idx) {
        case 1:{
            ui->tlmem->setText(QString::number(value["hour"].toInt()).rightJustified(2,'0')+":"+QString::number(value["min"].toInt()).rightJustified(2,'0')+":"+QString::number(value["sec"].toInt()).rightJustified(2,'0'));
            ui->cmmem->setText(value["comment"].toString());
            break;
        }
        case 2:{
            ui->tlmem_2->setText(QString::number(value["hour"].toInt()).rightJustified(2,'0')+":"+QString::number(value["min"].toInt()).rightJustified(2,'0')+":"+QString::number(value["sec"].toInt()).rightJustified(2,'0'));
            ui->cmmem_2->setText(value["comment"].toString());
            break;
        }
        case 3:{
            ui->tlmem_3->setText(QString::number(value["hour"].toInt()).rightJustified(2,'0')+":"+QString::number(value["min"].toInt()).rightJustified(2,'0')+":"+QString::number(value["sec"].toInt()).rightJustified(2,'0'));
            ui->cmmem_3->setText(value["comment"].toString());
            break;
        }

        case 4:{
            ui->tlmem_4->setText(QString::number(value["hour"].toInt()).rightJustified(2,'0')+":"+QString::number(value["min"].toInt()).rightJustified(2,'0')+":"+QString::number(value["sec"].toInt()).rightJustified(2,'0'));
            ui->cmmem_4->setText(value["comment"].toString());
            break;
        }
        case 5:{
            ui->tlmem_5->setText(QString::number(value["hour"].toInt()).rightJustified(2,'0')+":"+QString::number(value["min"].toInt()).rightJustified(2,'0')+":"+QString::number(value["sec"].toInt()).rightJustified(2,'0'));
            ui->cmmem_5->setText(value["comment"].toString());
            break;
        }
        case 6:{
            ui->tlmem_6->setText(QString::number(value["hour"].toInt()).rightJustified(2,'0')+":"+QString::number(value["min"].toInt()).rightJustified(2,'0')+":"+QString::number(value["sec"].toInt()).rightJustified(2,'0'));
            ui->cmmem_6->setText(value["comment"].toString());
            break;
        }
        case 7:{
            ui->tlmem_7->setText(QString::number(value["hour"].toInt()).rightJustified(2,'0')+":"+QString::number(value["min"].toInt()).rightJustified(2,'0')+":"+QString::number(value["sec"].toInt()).rightJustified(2,'0'));
            ui->cmmem_7->setText(value["comment"].toString());
            break;
        }
        case 8:{
            ui->tlmem_8->setText(QString::number(value["hour"].toInt()).rightJustified(2,'0')+":"+QString::number(value["min"].toInt()).rightJustified(2,'0')+":"+QString::number(value["sec"].toInt()).rightJustified(2,'0'));
            ui->cmmem_8->setText(value["comment"].toString());
            break;
        }
        case 9:{
            ui->tlmem_9->setText(QString::number(value["hour"].toInt()).rightJustified(2,'0')+":"+QString::number(value["min"].toInt()).rightJustified(2,'0')+":"+QString::number(value["sec"].toInt()).rightJustified(2,'0'));
            ui->cmmem_9->setText(value["comment"].toString());
            break;
        }
        case 10:{
            ui->tlmem_10->setText(QString::number(value["hour"].toInt()).rightJustified(2,'0')+":"+QString::number(value["min"].toInt()).rightJustified(2,'0')+":"+QString::number(value["sec"].toInt()).rightJustified(2,'0'));
            ui->cmmem_10->setText(value["comment"].toString());
            break;
        }

        }
    }
}

void FrameTimeLeft::on_resetallButton_clicked()
{
    if ( QMessageBox::information(nullptr,"","Are You sure ? ",QMessageBox::No|QMessageBox::Yes)== QMessageBox::Yes )
    {
        m_timeLeft->resetall();
        ui->hours->setText(QString::number(0).rightJustified(2,'0'));
        ui->min->setText(QString::number(0).rightJustified(2,'0'));
        ui->sec->setText(QString::number(0).rightJustified(2,'0'));
        m_comment->setText("");
    }else{
        ui->resetallButton->setEnabled(false);
    }
}

void FrameTimeLeft::setPassresult(bool result)
{
    m_passIsOk = result;
}
