#ifndef FRAMECONTACT_H
#define FRAMECONTACT_H

#include <QFrame>

namespace Ui {
class FrameContact;
}

class FrameContact : public QFrame
{
    Q_OBJECT

public:
    explicit FrameContact(QWidget *parent = nullptr);
    ~FrameContact();

private slots:
    void on_backButton_clicked();

private:
    Ui::FrameContact *ui;
};

#endif // FRAMECONTACT_H
