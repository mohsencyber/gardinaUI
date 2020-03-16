#ifndef INFECTION_H
#define INFECTION_H

#include <QFrame>
#include <QTimer>
#include "myserialport.h"

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

private:
    Ui::Infection *ui;
    QTimer  *timer;
    MySerialPort *m_serialport;
};

#endif // INFECTION_H
