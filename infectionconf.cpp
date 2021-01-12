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
    m_timeLeft = new TimeLeft();
    this->setStyleSheet( " #InfectionConf { "
                         " border:none;border-image: url(:/gardina_main_bg.png) 0 0 0 0 stretch stretch;"
                         "}");

    //connect( ui->secSpin,SIGNAL(valueChanged(int)),ui->secNumber,SLOT(setText(int)));
    //connect( ui->minSpin,SIGNAL(valueChanged(int)),ui->minNumber,SLOT(setText(int)));
    //connect( ui->hourSpin,SIGNAL(valueChanged(int)),ui->hourNumber,SLOT(setText(int)));
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
    QFile memoryFile("/home/pi/myapp/m2file.dat");
    memoryFile.open( QIODevice::ReadOnly | QIODevice::Text );
    valfile = memoryFile.readAll();
    memoryFile.close();
    memoryDoc = QJsonDocument::fromJson(valfile.toUtf8());
    QJsonObject memdocObj = memoryDoc.object();
    //QJsonValue values = memdocObj.value("memory");
    memoryArr = memdocObj["memory"].toArray();

    connect(radioButtons, QOverload<int>::of(&QButtonGroup::buttonClicked),
        [=](int id){ QJsonObject memValues = memoryArr[id].toObject();
            ui->hourNumber->setText(QString("%1").arg(memValues["hour"].toInt(), 2, 10, QChar('0')));
            ui->minNumber->setText(QString("%1").arg(memValues["min"].toInt(), 2, 10, QChar('0')));
            ui->secNumber->setText(QString("%1").arg(memValues["sec"].toInt(), 2, 10, QChar('0')));
            ui->mlNumber->setText(QString("%1").arg(memValues["ml"].toInt(), 2, 10, QChar('0')));
            m_hour = memValues["hour"].toInt();
            m_min = memValues["min"].toInt();
            m_sec = memValues["sec"].toInt();
        });
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTimer()));

    ui->hourNumber->setText(QString("%1").arg(0, 2, 10, QChar('0')));
    ui->minNumber->setText(QString("%1").arg(0, 2, 10, QChar('0')));
    ui->secNumber->setText(QString("%1").arg(0, 2, 10, QChar('0')));
    ui->mlNumber->setText(QString("%1").arg(0, 2, 10, QChar('0')));

}


InfectionConf::~InfectionConf()
{
    delete m_timeLeft;
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
    m_serialport->waitforwrite();
    m_serialport->close();
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
    ui->hourNumber->setText(QString("%1").arg(hour, 2, 10, QChar('0')));
    ui->minNumber->setText(QString("%1").arg(min, 2, 10, QChar('0')));
    ui->secNumber->setText(QString("%1").arg(sec, 2, 10, QChar('0')));
    ui->mlNumber->setText(QString("%1").arg(ml, 2, 10, QChar('0')));
    m_hour = hour ;
    m_min = min;
    m_sec = sec;
    int idButton = radioButtons->checkedId();
    QJsonObject  datas ;
    datas.insert("hour",QJsonValue::fromVariant(hour));
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
    m_serialport->open();
    ui->startButton->setDisabled(true);
    ui->pushButton->setDisabled(true);
    start();
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
            end();
            timer->stop();
            ui->startButton->setDisabled(false);
            ui->pushButton->setDisabled(false);
        }else{
            m_timeLeft->incTime();
            start();
        }
        ui->hourNumber->setText(QString("%1").arg(m_hour, 2, 10, QChar('0')));
        ui->minNumber->setText(QString("%1").arg(m_min, 2, 10, QChar('0')));
        ui->secNumber->setText(QString("%1").arg(m_sec, 2, 10, QChar('0')));
}

void InfectionConf::setSerialport(MySerialPort *serialport)
{
    m_serialport = serialport;
}

void InfectionConf::start()
{
    QString strStart = QString::number(ui->mlNumber->text().toInt() )+"\n";
    int interval=0;
    m_serialport->open();
    if ( m_serialport->isOpen())
    {
        m_serialport->write(strStart.toUtf8(),interval);
    }

}

void InfectionConf::stop()
{
    QString strStop = "0\n";
    int interval = 0;
    if ( m_serialport->isOpen())
    {
        m_serialport->write(strStop.toUtf8(),interval);
    }
}

void InfectionConf::end()
{
    QString end = "500\n";
    int interval= 0;
    stop();
    if ( m_serialport->isOpen())
    {
        m_serialport->write(end.toUtf8(),interval);
    }

}
