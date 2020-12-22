#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include <QLineEdit>
#include <softkeyboard.h>

class myLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    myLineEdit(QWidget *parent=nullptr);
    myLineEdit(const QString & txt, QWidget *parent=nullptr);
    ~myLineEdit() override;

    bool keyboardisVisible();

    //void focusInEvent(QFocusEvent *) override;
    void focusOutEvent(QFocusEvent *) override;

    void mousePressEvent(QMouseEvent *) override;
private:
    //FrameKeyboard *m_keyboard;
    SoftKeyBoard  *m_keyboard;
    bool   _keyboardshowed=false;
    EchoMode m_echomode;
};

#endif // MYLINEEDIT_H
