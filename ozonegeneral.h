#ifndef OZONEGENERAL_H
#define OZONEGENERAL_H

#include <QFrame>
#include <QTimer>

namespace Ui {
class OzoneGeneral;
}

class OzoneGeneral : public QFrame
{
    Q_OBJECT

public:
    explicit OzoneGeneral(QWidget *parent = nullptr);
    ~OzoneGeneral();

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

private:
    Ui::OzoneGeneral *ui;
    QTimer *timer;

};

#endif // OZONEGENERAL_H
