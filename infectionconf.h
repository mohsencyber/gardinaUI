#ifndef INFECTIONCONF_H
#define INFECTIONCONF_H

#include <QFrame>
#include <QButtonGroup>
#include <QJsonArray>
#include <QJsonDocument>
#include <QTimer>

namespace Ui {
class InfectionConf;
}

class InfectionConf : public QFrame
{
    Q_OBJECT

public:
    explicit InfectionConf(QWidget *parent = nullptr);
    ~InfectionConf();

    void setValues (int hour, int min, int sec, int ml);
private slots:
    void on_pushButton_clicked();

    void on_stopButton_clicked();

    void on_setCurrentButton_clicked();

    void on_startButton_clicked();

    void updateTimer();

private:
    Ui::InfectionConf *ui;
    QButtonGroup *radioButtons;
    int hour,min,sec,ml;
    int m_hour,m_min,m_sec;
    QJsonDocument  memoryDoc;
    QJsonArray     memoryArr;
    QTimer        *timer;
};

#endif // INFECTIONCONF_H
