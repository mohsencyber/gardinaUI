#ifndef FRAMEOZONE_H
#define FRAMEOZONE_H

#include <QFrame>

namespace Ui {
class FrameOzone;
}

class FrameOzone : public QFrame
{
    Q_OBJECT

public:
    explicit FrameOzone(QWidget *parent = nullptr);
    ~FrameOzone();

private slots:
    void on_backButton_clicked();

private:
    Ui::FrameOzone *ui;
};

#endif // FRAMEOZONE_H
