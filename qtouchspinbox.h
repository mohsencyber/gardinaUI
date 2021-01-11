#ifndef QTOUCHSPINBOX_H
#define QTOUCHSPINBOX_H

#include <QWidget>
#include <QTextEdit>
#include <QLabel>
#include <QTime>

class QTouchSpinBox : public QWidget
{
    Q_OBJECT
public:
    //using QTextEdit::QTextEdit;
    explicit QTouchSpinBox(QWidget *parent = nullptr);
    void setValue(int i);
    void setMinMax(int min, int max);
    void setCurrent(int current);
    void setStep(int step);
    void setNumbersShow(int level);
    void refresh();
protected:
    void    mousePressEvent(QMouseEvent *event) override;
    void    mouseMoveEvent(QMouseEvent *e) override;
    void    mouseReleaseEvent(QMouseEvent *e) override;
    void    paintEvent(QPaintEvent *e) override;

    QPoint prev;
    QPoint pstart;
    int mvalue=0;
    int m_min,m_max,m_current;
    int m_step , m_level;

Q_SIGNALS:
    void MovedUp();
    void MovedDown();

};

#endif // QTOUCHSPINBOX_H
