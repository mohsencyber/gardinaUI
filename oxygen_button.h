#ifndef OXYGEN_BUTTON_H
#define OXYGEN_BUTTON_H
#include "QEvent"
#include "QWidget"

class oxygen_button :public QWidget
{
public:
    oxygen_button();
    virtual ~oxygen_button();
protected:
    virtual void enterEvent( QEvent* e);
public: Q_SIGNALS :
    void hovered();
};

#endif // OXYGEN_BUTTON_H
