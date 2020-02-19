#ifndef FORM2_H
#define FORM2_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class FormOxygen;
}

class FormOxygen : public QWidget
{
    Q_OBJECT

public:
    explicit FormOxygen(QWidget *parent = nullptr);
    ~FormOxygen();

    void paintEvent(QPaintEvent *event) ;
private slots:
    void on_pushButton_clicked();

    void on_startButton_clicked();

    void on_stopButton_clicked();

    void on_minplus_clicked();

    void on_minminus_clicked();

    void on_minSpin_valueChanged(int arg1);

    void updateTimer();

private:
    Ui::FormOxygen *ui;
    QTimer *timer;
    int m_Min,m_Sec;
};

#endif // FORM2_H
