#include "mybutton.h"
#include <QLayout>

MyButton::MyButton(QWidget *parent)
    : QPushButton(parent)
{
    m_ButtonLayout = new QBoxLayout(QBoxLayout::LeftToRight, this);
    reinterpret_cast<QLayout*>(m_ButtonLayout)->setAlignment(this,Qt::Alignment());
    reinterpret_cast<QLayout*>(m_ButtonLayout)->setContentsMargins( 0, 0, 0, 0);

    m_ButtonLayout->setSpacing(1);

    m_IconLabel = new QLabel(this);
    m_IconLabel->setAlignment(Qt::Alignment());
    m_ButtonLayout->addWidget(m_IconLabel);

    m_TextLabel = new QLabel(this);
    m_TextLabel->setAlignment( Qt::Alignment());
    m_ButtonLayout->addWidget(m_TextLabel);
    //m_TextLabel->hide();
}

MyButton* MyButton::createButton(QIcon icon, QWidget *parent)
{
    MyButton* pButton = new MyButton(parent);
    pButton->setIcon(icon);

    return pButton;
}

void MyButton::setText(QString text)
{
    m_TextLabel->setVisible(!text.isEmpty());
    m_TextLabel->setText(text);
    QPushButton::setText(text);
}

void MyButton::setIcon(QIcon icon)
{
    m_Icon = icon;
    m_IconLabel->setVisible(true);
}

void MyButton::setOrientation(Qt::Orientation orientation)
{
    if (orientation == Qt::Horizontal)
        m_ButtonLayout->setDirection(QBoxLayout::LeftToRight);
    else
        m_ButtonLayout->setDirection(QBoxLayout::TopToBottom);
}

MyButton::~MyButton(){
    delete m_IconLabel;
    delete m_ButtonLayout;
    delete m_TextLabel;
}
