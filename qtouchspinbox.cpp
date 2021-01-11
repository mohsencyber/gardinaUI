#include "qtouchspinbox.h"
#include "QTouchEvent"
#include <QTextEdit>
#include <QPainter>
#include <cmath>


QTouchSpinBox::QTouchSpinBox(QWidget *parent) : QWidget(parent)
{
    setAttribute(Qt::WA_AcceptTouchEvents);
    QFont font;
    font.setBold(true);
    this->setFont(font);
}

void QTouchSpinBox::mousePressEvent(QMouseEvent *e)
{
    e->accept();
    prev = pstart = e->pos();
    mvalue = 0;
}

void QTouchSpinBox::mouseMoveEvent(QMouseEvent *e)
{
    e->accept();
    prev=e->pos();
    update();
}

void QTouchSpinBox::mouseReleaseEvent(QMouseEvent *e)
{
    e->accept();
    prev=e->pos();
}

void QTouchSpinBox::paintEvent(QPaintEvent *)
{
    QVector<int> mlist;
    int diff = ( m_level + 2)/2;
    for ( int i =0 ; i< m_level +2 ; i++ )
        mlist.append(m_current +(i-diff)*m_step);
    for ( int i =0 ,j=1; i< m_level +2 ; i++ )
    {
        if ( mlist[i]>m_max || mlist[i]< m_min )
        {
        if ( mlist[i]>m_max)
                j=-1;
        mlist[i] = mlist[i]+j*(m_max+m_step)-j*m_min;
        }
    }
        //mlist.append(m_current +(i-diff)*m_step);
    QFontMetrics metrics(font());
    int  dy;
    dy = prev.y() - pstart.y();
    int hg = this->geometry().height()/(m_level);
    int ystart = this->geometry().y()-pstart.y();
    if (ystart<0 ) ystart =0;
    int dyr = abs(dy) - mvalue*hg;
    if ( dy < 0 ) dyr =-1*dyr;
    int x = (width() - metrics.horizontalAdvance("1")) / 2 - 5;
    int y = (-hg ) / 4;
    QColor color;

//! [2]

//! [3]
    QPainter painter(this);//this);
//! [3] //! [4]
    for (int i = 0; i < m_level + 2; ++i) {
        //int index = (i) % 16;
        if ( mlist[i]==m_current )
        {
            color.setRgb(255, 255, 255);
            painter.setPen(color);
        }else
        {
            color.setRgb(150, 150, 150);
            painter.setPen(color);
        }
        painter.drawText(x, y + dyr ,QString(QString::number(mlist[i])));
        y += hg;
    }

    //if ( abs(dy+pstart.y())/hg > mvalue  )
    //if ( pstart.y()+dy > (m_level+1)*hg/2 )
    if (  (abs(dy)*2-mvalue*hg)/hg > mvalue )
    {

//        m_current = mlist[(mlist.size()/2)+1];
        if ( dy > 0 )
        {
            m_current -- ;
            emit MovedDown();
        }
        else
        {
            m_current ++ ;
            emit MovedUp();
        }

    if ( m_current < m_min )
        m_current= m_max;
    else if ( m_current > m_max )
        m_current = m_min;
        mvalue ++;
        //mvalue = abs(dy)/hg;
    }
}

void QTouchSpinBox::setValue(int i)
{
    mvalue = i;
}

void QTouchSpinBox::setMinMax(int min, int max)
{
    m_min = min;
    m_max = max;
}

void QTouchSpinBox::setStep(int step)
{
    m_step = step;
}

void QTouchSpinBox::setNumbersShow(int level)
{
    m_level = level;
}

void QTouchSpinBox::refresh()
{
    update();
}

void QTouchSpinBox::setCurrent(int current)
{
    m_current = current;
}
