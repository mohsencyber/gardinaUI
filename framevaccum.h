#ifndef FRAMEVACCUM_H
#define FRAMEVACCUM_H

#include <QFrame>


namespace Ui {
class Framevaccum;
}

class Framevaccum : public QFrame
{
    Q_OBJECT

public:
    explicit Framevaccum(QWidget *parent = nullptr);
    ~Framevaccum();

private slots:
    void on_backbutton_clicked();

private:
    Ui::Framevaccum *ui;
};

#endif // FRAMEVACCUM_H
