#ifndef FRAMETIMELEFT_H
#define FRAMETIMELEFT_H

#include <QFrame>
#include <QJsonArray>
#include <QJsonDocument>
#include "mylineedit.h"
#include "timeleft.h"


namespace Ui {
class FrameTimeLeft;
}

class FrameTimeLeft : public QFrame
{
    Q_OBJECT

public:
    explicit FrameTimeLeft(QWidget *parent = nullptr);
    ~FrameTimeLeft();

private slots:
    void PassIsOk();

    void on_backButton_clicked();

    void on_resetButton_clicked();

    void on_resetallButton_clicked();

    void setPassresult(bool result);

private:
    void viewJsonArray();
    Ui::FrameTimeLeft *ui;
    bool m_passIsOk;
    QJsonDocument  memoryDoc;
    QJsonArray     memoryArr;
    TimeLeft      *m_timeLeft;
    myLineEdit    *m_comment ;
};

#endif // FRAMETIMELEFT_H
