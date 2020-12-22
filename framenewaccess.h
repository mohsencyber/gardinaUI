#ifndef FRAMENEWACCESS_H
#define FRAMENEWACCESS_H

#include <QFrame>

namespace Ui {
class FrameNewAccess;
}

class FrameNewAccess : public QFrame
{
    Q_OBJECT

public:
    explicit FrameNewAccess(QWidget *parent = nullptr);
    ~FrameNewAccess();

private:
    Ui::FrameNewAccess *ui;
};

#endif // FRAMENEWACCESS_H
