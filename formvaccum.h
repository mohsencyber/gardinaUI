#ifndef FORMVACCUM_H
#define FORMVACCUM_H

#include <QWidget>
#include <QTimer>
#include <myserialport.h>

namespace Ui {
class FormVaccum;
}

class FormVaccum : public QWidget
{
    Q_OBJECT

public:
    explicit FormVaccum(QWidget *parent = nullptr);
    ~FormVaccum();

    void paintEvent(QPaintEvent *event) ;

    void setSerialport(MySerialPort *serialport);

    void start();

    void stop();

    void end();

private slots:
    void on_pushButton_clicked();

    void on_minplus_clicked();

    void on_minminus_clicked();

    void on_minSpin_valueChanged(int arg1);

    void on_startButton_clicked();

    void on_stopButton_clicked();

    void updateTimer();

private:
    Ui::FormVaccum *ui;
    QTimer *timer;
    int m_Min,m_Sec , m_UserMin;
    MySerialPort *m_serialport;
};

#endif // FORMVACCUM_H
