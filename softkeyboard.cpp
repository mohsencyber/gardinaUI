#include "softkeyboard.h"

void SoftKeyBoard::showSpcKeys(QButtonGroup *keyButtons)
{
   int lens = keyButtons->buttons().length();
   for (int i=0 ; i< lens ; i++)
   {
       if ( i==6 && m_shiftKeyPressed )
           keyButtons->button(i)->setText("&&");
       else
           keyButtons->button(i)->setText(currentSpcKeys.data()[i]);
   }
}

void SoftKeyBoard::shiftPressed()
{
    if ( m_shiftKeyPressed ){
        currentKeys = currentKeys.toUpper();
        currentSpcKeys = m_upperSpcKey;
    }else
    {
        currentKeys = currentKeys.toLower();
        currentSpcKeys = m_lowerSpcKey;
    }
    showSpcKeys(SpckeyButtons);
    showCharKeys(charKeyButtons);
}

void SoftKeyBoard::setStringTypped(QString &str)
{
    stringTyped = str;
}

void SoftKeyBoard::showCharKeys(QButtonGroup *keyButtons)
{
   int lens = keyButtons->buttons().length();
   for (int i=0 ; i< lens ; i++)
   {
       keyButtons->button(i)->setText(currentKeys.data()[i]);
   }
}

SoftKeyBoard::SoftKeyBoard(QWidget *parent):QFrame(parent)
{
    //this->resize(680, 250);
    this->setStyleSheet(QString::fromUtf8("color: rgb(250, 250, 250);\n"
                                          "border: 2px solid ;\n"
                                          "border-radius: 12px;\n"
                                          "border-color: rgb(110, 150, 200);\n"
                                          "background-color: rgba(40,80,120,0.5);"));
    pushButton = new QPushButton(this);
    pushButton->setObjectName(QString::fromUtf8("pushButton"));
    pushButton->setGeometry(QRect(57, 17, 43, 38));
    pushButton_2 = new QPushButton(this);
    pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
    pushButton_2->setGeometry(QRect(107, 17, 43, 38));
    pushButton_3 = new QPushButton(this);
    pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
    pushButton_3->setGeometry(QRect(157, 17, 43, 38));
    pushButton_4 = new QPushButton(this);
    pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
    pushButton_4->setGeometry(QRect(207, 17, 44, 38));
    pushButton_5 = new QPushButton(this);
    pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
    pushButton_5->setGeometry(QRect(257, 17, 43, 38));
    pushButton_6 = new QPushButton(this);
    pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
    pushButton_6->setGeometry(QRect(307, 17, 43, 38));
    pushButton_7 = new QPushButton(this);
    pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
    pushButton_7->setGeometry(QRect(357, 17, 43, 38));
    pushButton_8 = new QPushButton(this);
    pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
    pushButton_8->setGeometry(QRect(407, 17, 43, 38));
    pushButton_9 = new QPushButton(this);
    pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
    pushButton_9->setGeometry(QRect(457, 17, 43, 38));
    pushButton_10 = new QPushButton(this);
    pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
    pushButton_10->setGeometry(QRect(507, 17, 43, 38));
    lineEdit = new QLineEdit(this);
    lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
    lineEdit->setGeometry(QRect(400, 200, 214, 32));
    pushButton_11 = new QPushButton(this);
    pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
    pushButton_11->setGeometry(QRect(10, 17, 43, 38));
    pushButton_12 = new QPushButton(this);
    pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
    pushButton_12->setGeometry(QRect(557, 17, 43, 38));
    pushButton_13 = new QPushButton(this);
    pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));
    pushButton_13->setGeometry(QRect(607, 17, 43, 38));
    pushButton_14 = new QPushButton(this);
    pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));
    pushButton_14->setGeometry(QRect(657, 17, 80, 38));
    pushButton_15 = new QPushButton(this);
    pushButton_15->setObjectName(QString::fromUtf8("pushButton_15"));
    pushButton_15->setGeometry(QRect(32, 59, 45, 40));
    pushButton_16 = new QPushButton(this);
    pushButton_16->setObjectName(QString::fromUtf8("pushButton_16"));
    pushButton_16->setGeometry(QRect(82, 59, 45, 40));
    pushButton_17 = new QPushButton(this);
    pushButton_17->setObjectName(QString::fromUtf8("pushButton_17"));
    pushButton_17->setGeometry(QRect(132, 59, 45, 40));
    pushButton_18 = new QPushButton(this);
    pushButton_18->setObjectName(QString::fromUtf8("pushButton_18"));
    pushButton_18->setGeometry(QRect(182, 59, 45, 40));
    pushButton_19 = new QPushButton(this);
    pushButton_19->setObjectName(QString::fromUtf8("pushButton_19"));
    pushButton_19->setGeometry(QRect(232, 59, 45, 40));
    pushButton_20 = new QPushButton(this);
    pushButton_20->setObjectName(QString::fromUtf8("pushButton_20"));
    pushButton_20->setGeometry(QRect(282, 59, 45, 40));
    pushButton_21 = new QPushButton(this);
    pushButton_21->setObjectName(QString::fromUtf8("pushButton_21"));
    pushButton_21->setGeometry(QRect(332, 59, 45, 40));
    pushButton_22 = new QPushButton(this);
    pushButton_22->setObjectName(QString::fromUtf8("pushButton_22"));
    pushButton_22->setGeometry(QRect(382, 59, 45, 40));
    pushButton_23 = new QPushButton(this);
    pushButton_23->setObjectName(QString::fromUtf8("pushButton_23"));
    pushButton_23->setGeometry(QRect(432, 59, 45, 40));
    pushButton_24 = new QPushButton(this);
    pushButton_24->setObjectName(QString::fromUtf8("pushButton_24"));
    pushButton_24->setGeometry(QRect(482, 59, 45, 40));
    pushButton_25 = new QPushButton(this);
    pushButton_25->setObjectName(QString::fromUtf8("pushButton_25"));
    pushButton_25->setGeometry(QRect(45, 103, 44, 39));
    pushButton_26 = new QPushButton(this);
    pushButton_26->setObjectName(QString::fromUtf8("pushButton_26"));
    pushButton_26->setGeometry(QRect(95, 103, 44, 39));
    pushButton_27 = new QPushButton(this);
    pushButton_27->setObjectName(QString::fromUtf8("pushButton_27"));
    pushButton_27->setGeometry(QRect(145, 103, 44, 39));
    pushButton_28 = new QPushButton(this);
    pushButton_28->setObjectName(QString::fromUtf8("pushButton_28"));
    pushButton_28->setGeometry(QRect(195, 103, 44, 39));
    pushButton_29 = new QPushButton(this);
    pushButton_29->setObjectName(QString::fromUtf8("pushButton_29"));
    pushButton_29->setGeometry(QRect(245, 103, 44, 39));
    pushButton_30 = new QPushButton(this);
    pushButton_30->setObjectName(QString::fromUtf8("pushButton_30"));
    pushButton_30->setGeometry(QRect(295, 103, 44, 39));
    pushButton_31 = new QPushButton(this);
    pushButton_31->setObjectName(QString::fromUtf8("pushButton_31"));
    pushButton_31->setGeometry(QRect(345, 103, 44, 39));
    pushButton_32 = new QPushButton(this);
    pushButton_32->setObjectName(QString::fromUtf8("pushButton_32"));
    pushButton_32->setGeometry(QRect(395, 103, 44, 39));
    pushButton_33 = new QPushButton(this);
    pushButton_33->setObjectName(QString::fromUtf8("pushButton_33"));
    pushButton_33->setGeometry(QRect(445, 103, 44, 39));
    pushButton_34 = new QPushButton(this);
    pushButton_34->setObjectName(QString::fromUtf8("pushButton_34"));
    pushButton_34->setGeometry(QRect(85, 147, 46, 40));
    pushButton_35 = new QPushButton(this);
    pushButton_35->setObjectName(QString::fromUtf8("pushButton_35"));
    pushButton_35->setGeometry(QRect(135, 147, 46, 40));
    pushButton_36 = new QPushButton(this);
    pushButton_36->setObjectName(QString::fromUtf8("pushButton_36"));
    pushButton_36->setGeometry(QRect(185, 147, 46, 40));
    pushButton_37 = new QPushButton(this);
    pushButton_37->setObjectName(QString::fromUtf8("pushButton_37"));
    pushButton_37->setGeometry(QRect(235, 147, 46, 40));
    pushButton_38 = new QPushButton(this);
    pushButton_38->setObjectName(QString::fromUtf8("pushButton_38"));
    pushButton_38->setGeometry(QRect(285, 147, 46, 40));
    pushButton_39 = new QPushButton(this);
    pushButton_39->setObjectName(QString::fromUtf8("pushButton_39"));
    pushButton_39->setGeometry(QRect(335, 147, 46, 40));
    pushButton_40 = new QPushButton(this);
    pushButton_40->setObjectName(QString::fromUtf8("pushButton_40"));
    pushButton_40->setGeometry(QRect(385, 147, 46, 40));
    pushButton_41 = new QPushButton(this);
    pushButton_41->setObjectName(QString::fromUtf8("pushButton_41"));
    pushButton_41->setGeometry(QRect(532, 59, 45, 40));
    pushButton_42 = new QPushButton(this);
    pushButton_42->setObjectName(QString::fromUtf8("pushButton_42"));
    pushButton_42->setGeometry(QRect(582, 59, 45, 40));
    pushButton_43 = new QPushButton(this);
    pushButton_43->setObjectName(QString::fromUtf8("pushButton_43"));
    pushButton_43->setGeometry(QRect(495, 103, 44, 39));
    pushButton_44 = new QPushButton(this);
    pushButton_44->setObjectName(QString::fromUtf8("pushButton_44"));
    pushButton_44->setGeometry(QRect(545, 103, 44, 39));
    pushButton_45 = new QPushButton(this);
    pushButton_45->setObjectName(QString::fromUtf8("pushButton_45"));
    pushButton_45->setGeometry(QRect(595, 103, 44, 39));
    pushButton_46 = new QPushButton(this);
    pushButton_46->setObjectName(QString::fromUtf8("pushButton_46"));
    pushButton_46->setGeometry(QRect(435, 147, 46, 40));
    pushButton_47 = new QPushButton(this);
    pushButton_47->setObjectName(QString::fromUtf8("pushButton_47"));
    pushButton_47->setGeometry(QRect(485, 147, 46, 40));
    pushButton_48 = new QPushButton(this);
    pushButton_48->setObjectName(QString::fromUtf8("pushButton_48"));
    pushButton_48->setGeometry(QRect(535, 147, 46, 40));
    pushButton_49 = new QPushButton(this);
    pushButton_49->setObjectName(QString::fromUtf8("pushButton_49"));
    pushButton_49->setGeometry(QRect(585, 147, 98, 40));
    pushButton_50 = new QPushButton(this);
    pushButton_50->setObjectName(QString::fromUtf8("pushButton_50"));
    pushButton_50->setGeometry(QRect(10, 147, 73, 40));
    pushButton_51 = new QPushButton(this);
    pushButton_51->setObjectName(QString::fromUtf8("pushButton_51"));
    pushButton_51->setGeometry(QRect(150, 198, 238, 39));
    pushButton_52 = new QPushButton(this);
    pushButton_52->setObjectName(QString::fromUtf8("pushButton_52"));
    pushButton_52->setGeometry(QRect(655, 59, 59, 84));

    pushButton->setText(QCoreApplication::translate("SoftKeyBoard", "1", nullptr));
    pushButton_2->setText(QCoreApplication::translate("SoftKeyBoard", "2", nullptr));
    pushButton_3->setText(QCoreApplication::translate("SoftKeyBoard", "3", nullptr));
    pushButton_4->setText(QCoreApplication::translate("SoftKeyBoard", "4", nullptr));
    pushButton_5->setText(QCoreApplication::translate("SoftKeyBoard", "5", nullptr));
    pushButton_6->setText(QCoreApplication::translate("SoftKeyBoard", "6", nullptr));
    pushButton_7->setText(QCoreApplication::translate("SoftKeyBoard", "7", nullptr));
    pushButton_8->setText(QCoreApplication::translate("SoftKeyBoard", "8", nullptr));
    pushButton_9->setText(QCoreApplication::translate("SoftKeyBoard", "9", nullptr));
    pushButton_10->setText(QCoreApplication::translate("SoftKeyBoard", "0", nullptr));
    pushButton_11->setText(QCoreApplication::translate("SoftKeyBoard", "`", nullptr));
    pushButton_12->setText(QCoreApplication::translate("SoftKeyBoard", "-", nullptr));
    pushButton_13->setText(QCoreApplication::translate("SoftKeyBoard", "=", nullptr));
    pushButton_14->setText(QCoreApplication::translate("SoftKeyBoard", "<-", nullptr));
    pushButton_15->setText(QCoreApplication::translate("SoftKeyBoard", "q", nullptr));
    pushButton_16->setText(QCoreApplication::translate("SoftKeyBoard", "w", nullptr));
    pushButton_17->setText(QCoreApplication::translate("SoftKeyBoard", "e", nullptr));
    pushButton_18->setText(QCoreApplication::translate("SoftKeyBoard", "r", nullptr));
    pushButton_19->setText(QCoreApplication::translate("SoftKeyBoard", "t", nullptr));
    pushButton_20->setText(QCoreApplication::translate("SoftKeyBoard", "y", nullptr));
    pushButton_21->setText(QCoreApplication::translate("SoftKeyBoard", "u", nullptr));
    pushButton_22->setText(QCoreApplication::translate("SoftKeyBoard", "i", nullptr));
    pushButton_23->setText(QCoreApplication::translate("SoftKeyBoard", "o", nullptr));
    pushButton_24->setText(QCoreApplication::translate("SoftKeyBoard", "p", nullptr));
    pushButton_25->setText(QCoreApplication::translate("SoftKeyBoard", "a", nullptr));
    pushButton_26->setText(QCoreApplication::translate("SoftKeyBoard", "s", nullptr));
    pushButton_27->setText(QCoreApplication::translate("SoftKeyBoard", "d", nullptr));
    pushButton_28->setText(QCoreApplication::translate("SoftKeyBoard", "f", nullptr));
    pushButton_29->setText(QCoreApplication::translate("SoftKeyBoard", "g", nullptr));
    pushButton_30->setText(QCoreApplication::translate("SoftKeyBoard", "h", nullptr));
    pushButton_31->setText(QCoreApplication::translate("SoftKeyBoard", "j", nullptr));
    pushButton_32->setText(QCoreApplication::translate("SoftKeyBoard", "k", nullptr));
    pushButton_33->setText(QCoreApplication::translate("SoftKeyBoard", "l", nullptr));
    pushButton_34->setText(QCoreApplication::translate("SoftKeyBoard", "z", nullptr));
    pushButton_35->setText(QCoreApplication::translate("SoftKeyBoard", "x", nullptr));
    pushButton_36->setText(QCoreApplication::translate("SoftKeyBoard", "c", nullptr));
    pushButton_37->setText(QCoreApplication::translate("SoftKeyBoard", "v", nullptr));
    pushButton_38->setText(QCoreApplication::translate("SoftKeyBoard", "b", nullptr));
    pushButton_39->setText(QCoreApplication::translate("SoftKeyBoard", "n", nullptr));
    pushButton_40->setText(QCoreApplication::translate("SoftKeyBoard", "m", nullptr));
    pushButton_41->setText(QCoreApplication::translate("SoftKeyBoard", "[", nullptr));
    pushButton_42->setText(QCoreApplication::translate("SoftKeyBoard", "]", nullptr));
    pushButton_43->setText(QCoreApplication::translate("SoftKeyBoard", ";", nullptr));
    pushButton_44->setText(QCoreApplication::translate("SoftKeyBoard", "'", nullptr));
    pushButton_45->setText(QCoreApplication::translate("SoftKeyBoard", "\\", nullptr));
    pushButton_46->setText(QCoreApplication::translate("SoftKeyBoard", ",", nullptr));
    pushButton_47->setText(QCoreApplication::translate("SoftKeyBoard", ".", nullptr));
    pushButton_48->setText(QCoreApplication::translate("SoftKeyBoard", "/", nullptr));
    pushButton_49->setText(QCoreApplication::translate("SoftKeyBoard", "Shift", nullptr));
    pushButton_50->setText(QCoreApplication::translate("SoftKeyBoard", "Shift", nullptr));
    pushButton_51->setText(QCoreApplication::translate("SoftKeyBoard", "Space", nullptr));
    pushButton_52->setText(QCoreApplication::translate("SoftKeyBoard", "Enter", nullptr));

    //setupUi(this);
    SpckeyButtons = new QButtonGroup;
    SpckeyButtons->addButton(pushButton,0);
    SpckeyButtons->addButton(pushButton_2,1);
    SpckeyButtons->addButton(pushButton_3,2);
    SpckeyButtons->addButton(pushButton_4,3);
    SpckeyButtons->addButton(pushButton_5,4);
    SpckeyButtons->addButton(pushButton_6,5);
    SpckeyButtons->addButton(pushButton_7,6);
    SpckeyButtons->addButton(pushButton_8,7);
    SpckeyButtons->addButton(pushButton_9,8);
    SpckeyButtons->addButton(pushButton_10,9);

    SpckeyButtons->addButton(pushButton_11,10);
    SpckeyButtons->addButton(pushButton_12,11);
    SpckeyButtons->addButton(pushButton_13,12);
    SpckeyButtons->addButton(pushButton_41,13);
    SpckeyButtons->addButton(pushButton_42,14);
    SpckeyButtons->addButton(pushButton_43,15);
    SpckeyButtons->addButton(pushButton_44,16);
    SpckeyButtons->addButton(pushButton_45,17);
    SpckeyButtons->addButton(pushButton_46,18);
    SpckeyButtons->addButton(pushButton_47,19);
    SpckeyButtons->addButton(pushButton_48,20);

    SpckeyButtons->setExclusive(true);

    if ( m_shiftKeyPressed )
        currentKeys = m_upperSpcKey;
    else
        currentKeys = m_lowerSpcKey;
    currentSpcKeys = currentKeys;
    showSpcKeys(SpckeyButtons);

    connect(SpckeyButtons, QOverload<int>::of(&QButtonGroup::buttonClicked),
        [=](int id){ stringTyped.append(currentSpcKeys.data()[id]);
           lineEdit->setText(stringTyped);
           m_shiftKeyPressed = false;
           shiftPressed();
           emit stringTypped(stringTyped);
        });

    charKeyButtons = new QButtonGroup;
    charKeyButtons->addButton(pushButton_15,0);
    charKeyButtons->addButton(pushButton_16,1);
    charKeyButtons->addButton(pushButton_17,2);
    charKeyButtons->addButton(pushButton_18,3);
    charKeyButtons->addButton(pushButton_19,4);
    charKeyButtons->addButton(pushButton_20,5);
    charKeyButtons->addButton(pushButton_21,6);
    charKeyButtons->addButton(pushButton_22,7);
    charKeyButtons->addButton(pushButton_23,8);
    charKeyButtons->addButton(pushButton_24,9);

    charKeyButtons->addButton(pushButton_25,10);
    charKeyButtons->addButton(pushButton_26,11);
    charKeyButtons->addButton(pushButton_27,12);
    charKeyButtons->addButton(pushButton_28,13);
    charKeyButtons->addButton(pushButton_29,14);
    charKeyButtons->addButton(pushButton_30,15);
    charKeyButtons->addButton(pushButton_31,16);
    charKeyButtons->addButton(pushButton_32,17);
    charKeyButtons->addButton(pushButton_33,18);

    charKeyButtons->addButton(pushButton_34,19);
    charKeyButtons->addButton(pushButton_35,20);
    charKeyButtons->addButton(pushButton_36,21);
    charKeyButtons->addButton(pushButton_37,22);
    charKeyButtons->addButton(pushButton_38,23);
    charKeyButtons->addButton(pushButton_39,24);
    charKeyButtons->addButton(pushButton_40,25);

    charKeyButtons->setExclusive(true);

    if ( m_shiftKeyPressed )
        currentKeys = m_CharKey.toUpper();
    else
        currentKeys = m_CharKey.toLower();

    showCharKeys(charKeyButtons);

    connect(charKeyButtons, QOverload<int>::of(&QButtonGroup::buttonClicked),
        [=](int id){ stringTyped.append(currentKeys.data()[id]);
           lineEdit->setText(stringTyped);
           m_shiftKeyPressed = false;
           shiftPressed();
           emit stringTypped(stringTyped);
        });

    lineEdit->setVisible(false);
    connect(pushButton_14,&QPushButton::clicked,this,&SoftKeyBoard::on_pushButton_14_clicked);
    connect(pushButton_50,&QPushButton::clicked,this,&SoftKeyBoard::on_pushButton_50_clicked);
    connect(pushButton_51,&QPushButton::clicked,this,&SoftKeyBoard::on_pushButton_51_clicked);
    connect(pushButton_49,&QPushButton::clicked,this,&SoftKeyBoard::on_pushButton_49_clicked);
    connect(pushButton_52,&QPushButton::clicked,this,&SoftKeyBoard::on_pushButton_52_clicked);
}

SoftKeyBoard::~SoftKeyBoard()
{

    delete SpckeyButtons;
    delete charKeyButtons;
    delete pushButton;
    delete pushButton_2;
    delete pushButton_3;
    delete pushButton_4;
    delete pushButton_5;
    delete pushButton_6;
    delete pushButton_7;
    delete pushButton_8;
    delete pushButton_9;
    delete pushButton_10;
    delete lineEdit;
    delete pushButton_11;
    delete pushButton_12;
    delete pushButton_13;
    delete pushButton_14;
    delete pushButton_15;
    delete pushButton_16;
    delete pushButton_17;
    delete pushButton_18;
    delete pushButton_19;
    delete pushButton_20;
    delete pushButton_21;
    delete pushButton_22;
    delete pushButton_23;
    delete pushButton_24;
    delete pushButton_25;
    delete pushButton_26;
    delete pushButton_27;
    delete pushButton_28;
    delete pushButton_29;
    delete pushButton_30;
    delete pushButton_31;
    delete pushButton_32;
    delete pushButton_33;
    delete pushButton_34;
    delete pushButton_35;
    delete pushButton_36;
    delete pushButton_37;
    delete pushButton_38;
    delete pushButton_39;
    delete pushButton_40;
    delete pushButton_41;
    delete pushButton_42;
    delete pushButton_43;
    delete pushButton_44;
    delete pushButton_45;
    delete pushButton_46;
    delete pushButton_47;
    delete pushButton_48;
    delete pushButton_49;
    delete pushButton_50;
    delete pushButton_51;
    delete pushButton_52;
}



void SoftKeyBoard::on_pushButton_14_clicked()
{
    stringTyped.chop(1);
    lineEdit->setText(stringTyped);
    emit stringTypped(stringTyped);
}

void SoftKeyBoard::on_pushButton_50_clicked()
{
    m_shiftKeyPressed = !m_shiftKeyPressed;
    shiftPressed();
}

void SoftKeyBoard::on_pushButton_49_clicked()
{
    m_shiftKeyPressed=!m_shiftKeyPressed;
    shiftPressed();
}

void SoftKeyBoard::on_pushButton_51_clicked()
{
    stringTyped.append(" ");
    lineEdit->setText(stringTyped);
    emit stringTypped(stringTyped);
}

void SoftKeyBoard::on_pushButton_52_clicked()
{
    setHidden(true);
    //emit returnkeypress();
}
