#ifndef OZONECT_H
#define OZONECT_H

#include <QFrame>

namespace Ui {
class OzoneCT;
}

class OzoneCT : public QFrame
{
    Q_OBJECT

public:
    explicit OzoneCT(QWidget *parent = nullptr);
    ~OzoneCT();

private:
    Ui::OzoneCT *ui;
};

#endif // OZONECT_H
