#ifndef OZONECT_H
#define OZONECT_H

#include <QFrame>
#include "myserialport.h"

namespace Ui {
class OzoneCT;
}

class OzoneCT : public QFrame
{
    Q_OBJECT

public:
    explicit OzoneCT(QWidget *parent = nullptr);
    ~OzoneCT();
    void setSerialport(MySerialPort *serialport);
    void start();

    void stop();

    void end();

private slots:
    void on_pushButton_clicked();

    void on_startButton_clicked();

    void on_pauseButton_clicked();

    void on_stopButton_clicked();

private:
    Ui::OzoneCT *ui;
    bool isPause;
    MySerialPort *m_serialport;
};

#endif // OZONECT_H
