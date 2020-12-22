#include "mylineedit.h"
#include <QFocusEvent>

myLineEdit::myLineEdit(QWidget *parent):QLineEdit(parent)
{
    //setAttribute(Qt::WA_InputMethodEnabled);
    m_keyboard = new SoftKeyBoard();

    connect(m_keyboard,&SoftKeyBoard::stringTypped,this,&QLineEdit::setText);
    //connect(m_keyboard,&FrameKeyboard::returnkeypress,this,&QLineEdit::returnPressed);
    connect(m_keyboard,&SoftKeyBoard::closed,[this]{_keyboardshowed=false;this->setEchoMode(m_echomode);emit returnPressed();});
}

myLineEdit::myLineEdit(const QString & txt, QWidget *parent):QLineEdit(txt,parent)
{
    //setAttribute(Qt::WA_InputMethodEnabled);
    m_keyboard = new SoftKeyBoard();

    connect(m_keyboard,&SoftKeyBoard::stringTypped,this,&QLineEdit::setText);
    //connect(m_keyboard,&FrameKeyboard::returnkeypress,this,&QLineEdit::returnPressed);
    connect(m_keyboard,&SoftKeyBoard::closed,[this]{_keyboardshowed=false;this->setEchoMode(m_echomode);emit returnPressed();});
}

myLineEdit::~myLineEdit()
{
    delete m_keyboard;
}

bool myLineEdit::keyboardisVisible()
{
    return  m_keyboard->isHidden();
}

void myLineEdit::mousePressEvent(QMouseEvent *e)
{
    QLineEdit::mousePressEvent(e);
    //if ( !_keyboardshowed )
    //{
        m_keyboard->setWindowFlag(Qt::Popup);
        m_keyboard->setGeometry(0,220,780,250);
        QString strTypped = this->text();
        m_keyboard->setStringTypped(strTypped);
        m_echomode = this->echoMode();
        this->setEchoMode(QLineEdit::Normal);
        m_keyboard->show();
        _keyboardshowed=true;
    //}

}

//void myLineEdit::focusInEvent(QFocusEvent *e)
//{
//    QLineEdit::focusInEvent(e);
//    if ( !_keyboardshowed )
//    {
//        m_keyboard->show();
//        _keyboardshowed=true;
//    }
//}

void myLineEdit::focusOutEvent(QFocusEvent *e)
{
    QLineEdit::focusOutEvent(e);
    if ( _keyboardshowed && m_keyboard->isHidden() )
    {
        //m_keyboard->close();
        _keyboardshowed=false;
    }
}

