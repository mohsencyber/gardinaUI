#include "timeleft.h"
#include <QJsonObject>
#include <QFile>

TimeLeft::TimeLeft()
{

 CurrentTimeLeft = TempTimeLeft = 0;
 idMem=1;
 setting = new QSettings("/home/pi/myapp/ctl.dat",QSettings::IniFormat);
 CurrentTimeLeft = setting->value("ctl","0").toInt();
 idMem = setting->value("idmem","1").toInt();
 loadTL();
 ctl2time();
}

TimeLeft::~TimeLeft()
{
    setting->sync();
    delete setting;
}

bool TimeLeft::writeTL(QString& comment)
{

    QJsonObject  datas ;
    datas.insert("hour",QJsonValue::fromVariant(m_hour));
    datas.insert("min",QJsonValue::fromVariant(m_min));
    datas.insert("sec",QJsonValue::fromVariant(m_sec));
    datas.insert("comment",QJsonValue::fromVariant(comment));

    memoryArr.append(datas);
    QJsonObject JsonObject;
    JsonObject.insert("memory",memoryArr);
    memoryDoc.setObject(JsonObject);

    QFile memoryFile("/home/pi/myapp/tl.dat");
    memoryFile.open( QIODevice::WriteOnly | QIODevice::Text);
    memoryFile.write( memoryDoc.toJson());

    memoryFile.close();
    return true;
}

bool TimeLeft::resetTL(QString& comment)
{
    if ( idMem <= 10 ){
        writeTL(comment);
        m_hour=m_min=m_sec=0;
        idMem++;
        CurrentTimeLeft=0;
        setting->setValue("ctl",CurrentTimeLeft);
        setting->setValue("idmem",idMem);
        return true;
    }

    return false;
}

void TimeLeft::ctl2time()
{
    m_hour = (CurrentTimeLeft-CurrentTimeLeft%3600) /3600;
    min = CurrentTimeLeft-m_hour*3600;
    m_min=(min-min%60)/60;
    m_sec = CurrentTimeLeft - m_hour*3600 - m_min*60;

}

void TimeLeft::resetall()
{
    CurrentTimeLeft = 0;
    idMem = 1;
    setting->setValue("ctl",CurrentTimeLeft);
    setting->setValue("idmem",idMem);
}

void TimeLeft::getTimeLeft(int &hour, int &min, int &sec)
{
    hour=m_hour;
    min=m_min;
    sec=m_sec;
}

QJsonArray TimeLeft::getMemory()
{
    return memoryArr;
}

void TimeLeft::loadTL()
{
    QString valfile;
    QFile memoryFile("/home/pi/myapp/tl.dat");
    memoryFile.open(QIODevice::ReadOnly | QIODevice::Text);
    valfile = memoryFile.readAll();
    memoryFile.close();
    memoryDoc = QJsonDocument::fromJson(valfile.toUtf8());
    QJsonObject memdocObj = memoryDoc.object();
    //QJsonValue values = memdocObj.value("memory");
    memoryArr = memdocObj["memory"].toArray();
}

void TimeLeft::incTime()
{
    CurrentTimeLeft++;
    setting->setValue("ctl",CurrentTimeLeft);
}
