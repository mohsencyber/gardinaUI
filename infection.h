#ifndef INFECTION_H
#define INFECTION_H

#include <QFrame>
#include <QTimer>
#include "myserialport.h"
#include "timeleft.h"
#include "qtouchspinbox.h"

namespace Ui {
class Infection;
}

class Infection : public QFrame
{
    Q_OBJECT

public:
    explicit Infection(QWidget *parent = nullptr);
    ~Infection();
    void setSerialport(MySerialPort *serialport);

    void start();

    void stop();

    void end();

private slots:
    void on_startButton_clicked();

    void on_stopButton_clicked();

    void on_pushButton_clicked();

    void on_mconfigButton_clicked();

    //void on_mlSpin_valueChanged(int arg1);

    void on_secSpin_valueChanged(int arg1);

    void on_minSpin_valueChanged(int arg1);

    void on_hourSpin_valueChanged(int arg1);

    void updateTimer();

    void on_mlSpin_valueChanged(int arg1);

private:
    TimeLeft *m_timeLeft;
    Ui::Infection *ui;
    QTimer  *timer;
    MySerialPort *m_serialport;
    int m_userMin=0,m_userSec=0,m_userHour=0;
    QTouchSpinBox *m_minTouch=nullptr , *m_hourTouch=nullptr , *m_secTouch=nullptr , *m_mlTouch=nullptr;
};

#endif // INFECTION_H
