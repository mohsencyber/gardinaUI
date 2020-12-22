#ifndef DIALOGTLLOGIN_H
#define DIALOGTLLOGIN_H

#include <QDialog>
#include "frametimeleft.h"

namespace Ui {
class DialogTLLogin;
}

class DialogTLLogin : public QDialog
{
    Q_OBJECT

public:
    explicit DialogTLLogin(QWidget *parent = nullptr);
    ~DialogTLLogin();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DialogTLLogin *ui;
    bool m_passIsOk;
};

#endif // DIALOGTLLOGIN_H
