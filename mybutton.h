#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <qabstractbutton.h>
#include <QBoxLayout>
#include <QLabel>
#include <QIcon>
#include <QTabWidget>
#include <QPushButton>

class MyButton: public QPushButton
{
    Q_OBJECT

public:
    static MyButton* createButton(QIcon icon, QWidget *parent);
    ~MyButton();

    void setText(QString);
    void setIcon(QIcon);
    void setOrientation(Qt::Orientation);

protected :
    MyButton(QWidget *parent);

    // here, you can reimplement event like mousePressEvent or paintEvent

private :
    QBoxLayout*  m_ButtonLayout;
    QLabel*      m_IconLabel;
    QIcon        m_Icon;
    QLabel*      m_TextLabel;
};

#endif // MYBUTTON_H
