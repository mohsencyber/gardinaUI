#ifndef OZONEGENERALCONF_H
#define OZONEGENERALCONF_H

#include <QFrame>
#include <QButtonGroup>
#include <QJsonDocument>
#include <QJsonArray>

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

private slots:
    void on_mconfigButton_clicked();

    void on_pushButton_clicked();

    void on_hourSpin_valueChanged(int arg1);

    void on_minSpin_valueChanged(int arg1);

    void on_secSpin_valueChanged(int arg1);

    void on_setCurrentButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ozoneGeneralConf *ui;
    QButtonGroup *radioButtons;
    int hour,min,sec,ml;
    QJsonDocument  memoryDoc;
    QJsonArray     memoryArr;

};

#endif // OZONEGENERALCONF_H
