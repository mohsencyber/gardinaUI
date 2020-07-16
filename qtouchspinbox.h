#ifndef QTOUCHSPINBOX_H
#define QTOUCHSPINBOX_H

#include <QWidget>
#include <QTextEdit>
#include <QLabel>
#include <QTime>

class QTouchSpinBox : public QTextEdit
{
    Q_OBJECT
public:
    using QTextEdit::QTextEdit;
    explicit QTouchSpinBox(QWidget *parent = nullptr);
    void setValue(int i);
protected:
    void    mousePressEvent(QMouseEvent *event) override;
    //void    mouseMoveEvent(QMouseEvent *event) override;
    void    mouseReleaseEvent(QMouseEvent *e) override;
    QPoint prev;
    int mvalue=0;
    QTime mtime;

Q_SIGNALS:
    void MovedUp();
    void MovedDown();

};

#endif // QTOUCHSPINBOX_H
