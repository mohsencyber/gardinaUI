#ifndef BUTTONHOVERWATCHER_H
#define BUTTONHOVERWATCHER_H

#include <QObject>
#include <QPushButton>
#include <QEvent>

class ButtonHoverWatcher : public QObject
{
    Q_OBJECT
    QIcon   *qIconButtonEnter;
    QIcon   *qIconButtonLeave;
    QSize   qIconSize;
public:
    explicit ButtonHoverWatcher(QObject * parent = Q_NULLPTR);
    ~ButtonHoverWatcher() Q_DECL_OVERRIDE ;
    virtual bool eventFilter(QObject * watched, QEvent * event) Q_DECL_OVERRIDE;
    void setIcon(QString iconStringEnter,QString iconStringLeave);
    void setIconSize(QSize iconSize);
};
#endif // BUTTONHOVERWATCHER_H
