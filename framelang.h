#ifndef FRAMELANG_H
#define FRAMELANG_H

#include <QFrame>
#include <QButtonGroup>

namespace Ui {
class FrameLang;
}

class FrameLang : public QFrame
{
    Q_OBJECT

public:
    explicit FrameLang(QWidget *parent = nullptr);
    ~FrameLang();

private slots:
    void on_backButton_clicked();

private:
    Ui::FrameLang *ui;
    QButtonGroup *radioButtons;
};

#endif // FRAMELANG_H
