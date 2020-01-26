#ifndef FRAMEABOUT_H
#define FRAMEABOUT_H

#include <QFrame>

namespace Ui {
class FrameAbout;
}

class FrameAbout : public QFrame
{
    Q_OBJECT

public:
    explicit FrameAbout(QWidget *parent = nullptr);
    ~FrameAbout();

private slots:
    void on_backButton_clicked();

private:
    Ui::FrameAbout *ui;
};

#endif // FRAMEABOUT_H
