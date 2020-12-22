#ifndef FRAMETLLOGIN_H
#define FRAMETLLOGIN_H

#include <QFrame>
#include "frametimeleft.h"
#include "mylineedit.h"

namespace Ui {
class FrameTLLogin;
}

class FrameTLLogin : public QFrame
{
    Q_OBJECT

public:
    explicit FrameTLLogin(QWidget *parent = nullptr);
    ~FrameTLLogin();
    bool getPassResult();

private slots:
    void on_pushButton_clicked();

Q_SIGNALS:
    void Closed();

private:
    Ui::FrameTLLogin *ui;
    bool m_passIsOk;
    myLineEdit *mylineedit;
};

#endif // FRAMETLLOGIN_H
