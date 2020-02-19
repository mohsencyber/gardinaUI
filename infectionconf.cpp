#include "infectionconf.h"
#include "ui_infectionconf.h"
#include <QFile>
#include <QJsonObject>
#include <QTimer>

InfectionConf::InfectionConf(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::InfectionConf)
{
    ui->setupUi(this);
    this->setStyleSheet( " #InfectionConf { "
                         " border:none;border-image: url(:/gardina_main_bg.png) 0 0 0 0 stretch stretch;"
                         "}");

    //connect( ui->secSpin,SIGNAL(valueChanged(int)),ui->secNumber,SLOT(display(int)));
    //connect( ui->minSpin,SIGNAL(valueChanged(int)),ui->minNumber,SLOT(display(int)));
    //connect( ui->hourSpin,SIGNAL(valueChanged(int)),ui->hourNumber,SLOT(display(int)));
    ui->secSpin->setDisabled(true);
    ui->minSpin->setDisabled(true);
    ui->hourSpin->setDisabled(true);
    ui->mlSpin->setDisabled(true);

    radioButtons = new QButtonGroup();
    radioButtons->addButton(ui->mg1Button,0);
    ui->mg1Button->setChecked(true);
    radioButtons->addButton(ui->mg2Button,1);
    radioButtons->addButton(ui->mg3Button,2);
    radioButtons->addButton(ui->mg4Button,3);
    radioButtons->addButton(ui->mg5Button,4);
    radioButtons->addButton(ui->mg6Button,5);
    radioButtons->addButton(ui->mg7Button,6);
    radioButtons->addButton(ui->mg8Button,7);
    radioButtons->addButton(ui->mg9Button,8);
    radioButtons->addButton(ui->mg10Button,9);
    radioButtons->setExclusive(true);

    QString valfile;
    QFile memoryFile("m2file.dat");
    memoryFile.open( QIODevice::ReadOnly | QIODevice::Text );
    valfile = memoryFile.readAll();
    memoryFile.close();
    memoryDoc = QJsonDocument::fromJson(valfile.toUtf8());
    QJsonObject memdocObj = memoryDoc.object();
    //QJsonValue values = memdocObj.value("memory");
    memoryArr = memdocObj["memory"].toArray();

    connect(radioButtons, QOverload<int>::of(&QButtonGroup::buttonClicked),
        [=](int id){ QJsonObject memValues = memoryArr[id].toObject();
            ui->hourNumber->display(memValues["hour"].toInt());
            ui->minNumber->display(memValues["min"].toInt());
            ui->secNumber->display(memValues["sec"].toInt());
            ui->mlNumber->display(memValues["ml"].toInt());
            m_hour = memValues["hour"].toInt();
            m_min = memValues["min"].toInt();
            m_sec = memValues["sec"].toInt();
        });
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTimer()));
}


InfectionConf::~InfectionConf()
{
    delete ui;
}

void InfectionConf::setValues(int hour, int min, int sec, int ml)
{
    this->hour=hour;
    this->min=min;
    this->sec=sec;
    this->ml=ml;
}

void InfectionConf::on_pushButton_clicked()
{
    timer->stop();
    close();
}

void InfectionConf::on_stopButton_clicked()
{
    ui->startButton->setDisabled(false);
    ui->pushButton->setDisabled(false);
    timer->stop();
}

void InfectionConf::on_setCurrentButton_clicked()
{
    ui->hourNumber->display(hour);
    ui->minNumber->display(min);
    ui->secNumber->display(sec);
    ui->mlNumber->display(ml);
    m_hour = hour ;
    m_min = min;
    m_sec = sec;
    int idButton = radioButtons->checkedId();
    QJsonObject  datas ;
    datas.insert("hour",hour);
    datas.insert("min",QJsonValue::fromVariant(min));
    datas.insert("sec",QJsonValue::fromVariant(sec));
    datas.insert("ml",QJsonValue::fromVariant(ml));

    memoryArr[idButton] = datas;
    QJsonObject JsonObject;
    JsonObject.insert("memory",memoryArr);
    memoryDoc.setObject(JsonObject);

    QFile memoryFile("m2file.dat");
    memoryFile.open( QIODevice::WriteOnly | QIODevice::Text);
    memoryFile.write( memoryDoc.toJson());

    memoryFile.close();
    //tr("Save paramter in memory " );//+QString::number(idButton));
}

void InfectionConf::on_startButton_clicked()
{
    ui->startButton->setDisabled(true);
    ui->pushButton->setDisabled(true);
    timer->setInterval(1000);
    timer->start();
}

void InfectionConf::updateTimer()
{
        m_sec --;
        if ( m_sec == -1 )
        {
            m_min --;
            m_sec = 0;
            if ( m_min == -1 )
            {
                m_hour--;
                m_min = 0;
                if ( m_hour == -1 )
                {
                    m_hour = 0;
                }else {
                    m_min = 59;
                    m_sec = 59;
                }
            }else {
                m_sec = 59;
            }
        }

        if ( m_hour == 0 &&
             m_sec == 0 &&
             m_min == 0 )
        {
            timer->stop();
            ui->startButton->setDisabled(false);
            ui->pushButton->setDisabled(false);
        }
        ui->hourNumber->display(m_hour);
        ui->minNumber->display(m_min);
        ui->secNumber->display(m_sec);
}
