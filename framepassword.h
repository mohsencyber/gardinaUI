#ifndef FRAMEPASSWORD_H
#define FRAMEPASSWORD_H

#include <QFrame>
#include <QSettings>
#include <QCryptographicHash>
#include <mylineedit.h>

namespace Ui {
class FramePassword;
}

class FramePassword : public QFrame
{
    Q_OBJECT

public:
    explicit FramePassword(QWidget *parent = nullptr);
    ~FramePassword();

private slots:
    void on_backButton_clicked();

    void on_saveButton_clicked();

private:
    Ui::FramePassword *ui;
    QString m_username;
    QString m_password;
    myLineEdit *m_userName;
    myLineEdit *m_passWord;
};

#endif // FRAMEPASSWORD_H
