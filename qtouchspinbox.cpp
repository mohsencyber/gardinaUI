#include "qtouchspinbox.h"
#include "QTouchEvent"
#include <QTextEdit>
#include <cmath>

QTouchSpinBox::QTouchSpinBox(QWidget *parent) : QTextEdit(parent)
{
    setAttribute(Qt::WA_AcceptTouchEvents);
}

void QTouchSpinBox::mousePressEvent(QMouseEvent *e)
{
    e->accept();
    mtime.restart();
    prev = e->pos();
}

void QTouchSpinBox::mouseReleaseEvent(QMouseEvent *e)
{
    e->accept();

    int dy = e->pos().y() - prev.y();
    int dt = int(trunc(abs(dy)*10/mtime.elapsed()));
    if (dt==0) dt = 1;
    if (dy < 0 )
        for ( int i =1; i <= dt ; i++)
            emit this->MovedUp();
    if(dy > 0)
        for ( int i =1; i <= dt ; i++)
            emit this->MovedDown();

    prev=e->pos();
}

void QTouchSpinBox::setValue(int i)
{
  mvalue = i;
}
