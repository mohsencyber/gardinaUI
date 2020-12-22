#ifndef OZONEGENERALCONF_H
#define OZONEGENERALCONF_H

#include <QFrame>
#include <QButtonGroup>
#include <QJsonDocument>
#include <QJsonArray>
#include <QTimer>
#include "myserialport.h"
#include "timeleft.h"

namespace Ui {
class ozoneGeneralConf;
}

class ozoneGeneralConf : public QFrame
{
    Q_OBJECT

public:
    explicit ozoneGeneralConf(QWidget *parent = nullptr);
    ~ozoneGeneralConf();

    void setValues (int hour, int min, int sec, int ml);

    void setSerialport(MySerialPort *serialport);

    void start();

    void stop();

    void end();


private slots:
    void on_mconfigButton_clicked();

    void on_pushButton_clicked();

    void on_hourSpin_valueChanged(int arg1);

    void on_minSpin_valueChanged(int arg1);

    void on_secSpin_valueChanged(int arg1);

    void on_setCurrentButton_clicked();

    void on_pushButton_2_clicked();

    void on_startButton_clicked();

    void on_stopButton_clicked();

    void updateTimer();

private:
    Ui::ozoneGeneralConf *ui;
    QButtonGroup *radioButtons;
    int hour,min,sec,ml;
    int m_hour, m_min, m_sec;
    QJsonDocument  memoryDoc;
    QJsonArray     memoryArr;
    QTimer         *timer;
    TimeLeft       *m_timeLeft;
    MySerialPort *m_serialport;
};

#endif // OZONEGENERALCONF_H
