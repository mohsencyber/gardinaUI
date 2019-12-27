#include "oxygen_button.h"
#include "QWidget"

oxygen_button::oxygen_button()
{

}

void oxygen_button::enterEvent(QEvent *e)
{
    Q_EMIT hovered();
    QWidget::enterEvent(e);
}
