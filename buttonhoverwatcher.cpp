#include "buttonhoverwatcher.h"

ButtonHoverWatcher::ButtonHoverWatcher(QObject * parent) :
    QObject(parent)
{}

void ButtonHoverWatcher::setIcon(QString iconStringEnter,QString iconStringLeave)
{
    qIconButtonEnter = new QIcon(iconStringEnter);
    qIconButtonLeave = new QIcon(iconStringLeave);
    qIconStringEnter = iconStringEnter;
    qIconStringLeave = iconStringLeave;
}

void ButtonHoverWatcher::setIconSize(QSize iconSize)
{
    qIconSize = iconSize;
}
bool ButtonHoverWatcher::eventFilter(QObject * watched, QEvent * event)
{
    QPushButton * button = qobject_cast<QPushButton*>(watched);
    if (!button) {
        return false;
    }

    if (event->type() == QEvent::Enter) {
        // The push button is hovered by mouse
        //button->setIcon(*qIconButtonEnter);
        //button->setGeometry(130,50,110,90);
        //button->setIconSize(qIconSize);
        button->setStyleSheet("border:none;image:url("+qIconStringEnter+");");
        return true;
    }

    if (event->type() == QEvent::Leave){
        // The push button is not hovered by mouse
        //button->setIcon(*qIconButtonLeave);
        //button->setIconSize(qIconSize);
        button->setStyleSheet("border:none;image:url("+qIconStringLeave+");");
        //button->setGeometry(130,50,110,90);
        return true;
    }

    /*if ( event->type() == QEvent::MouseButtonPress){
        button->setFlat(true);
        return true;
    }*/

    return false;
}

ButtonHoverWatcher::~ButtonHoverWatcher()
{

}
