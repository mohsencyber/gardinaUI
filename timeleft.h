#ifndef TIMELEFT_H
#define TIMELEFT_H
#include <QJsonDocument>
#include <QJsonArray>
#include <QSettings>
//#include <QTimer>


class TimeLeft
{
public:
    TimeLeft();
    ~TimeLeft();
    void incTime();
    void loadTL();
    bool writeTL(QString& comment);
    bool resetTL(QString& comment);
    void ctl2time();
    void resetall();
    void getTimeLeft(int& hour , int& min , int& sec);
    QJsonArray getMemory();
private:
    int CurrentTimeLeft,TempTimeLeft;
    int hour,min,sec,idMem;
    int m_hour, m_min, m_sec;
    QJsonDocument  memoryDoc;
    QJsonArray     memoryArr;
    QSettings      *setting;
    //QTimer         *timer;
};

#endif // TIMELEFT_H
