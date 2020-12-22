#ifndef FRAMELOGIN_H
#define FRAMELOGIN_H

#include <QFrame>
#include <mylineedit.h>

namespace Ui {
class FrameLogin;
}

class FrameLogin : public QFrame
{
    Q_OBJECT

public:
    explicit FrameLogin(QWidget *parent = nullptr);
    ~FrameLogin();

private slots:
    void on_login_clicked();

private:
    Ui::FrameLogin *ui;
    myLineEdit   *m_username;
    myLineEdit   *m_password;
};

#endif // FRAMELOGIN_H
