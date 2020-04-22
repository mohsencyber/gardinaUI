#ifndef OZONECT_H
#define OZONECT_H

#include <QFrame>
#include <QButtonGroup>
#include <QTimer>
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

    void updateTimer();

    void on_Button_Enter_clicked();

    void on_Button_Delete_clicked();

    void on_Button_Reset_clicked();

private:
    void timeToSeconds();

    Ui::OzoneCT *ui;
    bool isPause;
    QString enter;
    QTimer         *timer;
    MySerialPort *m_serialport;
    QButtonGroup *radioButtons;
    int ConcenVal , DoseVal , MinVal , SecVal;
};

#endif // OZONECT_H
