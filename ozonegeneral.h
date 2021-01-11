#ifndef OZONEGENERAL_H
#define OZONEGENERAL_H

#include <QFrame>
#include <QTimer>
#include "myserialport.h"
#include "timeleft.h"
#include "qtouchspinbox.h"

namespace Ui {
class OzoneGeneral;
}

class OzoneGeneral : public QFrame
{
    Q_OBJECT

public:
    explicit OzoneGeneral(QWidget *parent = nullptr);
    ~OzoneGeneral();
    void setSerialport(MySerialPort *serialport);
    void start();

    void stop();

    void end();

private slots:
    void on_pushButton_clicked();

    void on_secSpin_valueChanged(int arg1);

    void on_mconfigButton_clicked();

    void on_minSpin_valueChanged(int arg1);

    void on_hourSpin_valueChanged(int arg1);

    void on_hourminus_clicked();

    void on_startButton_clicked();

    void on_stopButton_clicked();

    void on_touchButton_clicked();

    void updateTimer();

    void on_touchButton_pressed();

    void on_touchButton_released();

    void on_mlSpin_valueChanged(int arg1);

private:
    Ui::OzoneGeneral *ui;
    TimeLeft *m_timeLeft;
    QTimer *timer;
    MySerialPort *m_serialport;
    bool touch=false;
    int m_userMin=0,m_userSec=0,m_userHour=0;
    QTouchSpinBox *m_minTouch=nullptr , *m_hourTouch=nullptr , *m_secTouch=nullptr , *m_mlTouch=nullptr;
};

#endif // OZONEGENERAL_H
