#ifndef SOFTKEYBOARD_H
#define SOFTKEYBOARD_H

#include <QFrame>
#include <QButtonGroup>
#include <QPushButton>
#include <QLineEdit>
#include <QCoreApplication>


class SoftKeyBoard : public QFrame
{
    Q_OBJECT
private:
    void showCharKeys(QButtonGroup *buttons);
    void showSpcKeys(QButtonGroup *buttons);
    void shiftPressed();


public:
    explicit SoftKeyBoard(QWidget *parent = nullptr);
    ~SoftKeyBoard() override;
    void setStringTypped(QString &str);

signals:
    void stringTypped(QString txt);
    void closed();
    void returnkeypress();


private slots:
    void on_pushButton_14_clicked();

    void on_pushButton_50_clicked();

    void on_pushButton_49_clicked();

    void on_pushButton_51_clicked();

    void on_pushButton_52_clicked();

private:
    QString    stringTyped="";
    QString    currentKeys;
    QString    currentSpcKeys;
    QList<QPushButton> keylist;
    QButtonGroup *SpckeyButtons;
    QButtonGroup *charKeyButtons;
    bool      m_shiftKeyPressed=false;
    QString   m_lowerSpcKey="1234567890`-=[];\'\\,./";
    QString   m_upperSpcKey="!@#$%^&*()~_+{}:\"|<>?";
    QString   m_CharKey="qwertyuiopasdfghjklzxcvbnm";

public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QLineEdit *lineEdit;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QPushButton *pushButton_16;
    QPushButton *pushButton_17;
    QPushButton *pushButton_18;
    QPushButton *pushButton_19;
    QPushButton *pushButton_20;
    QPushButton *pushButton_21;
    QPushButton *pushButton_22;
    QPushButton *pushButton_23;
    QPushButton *pushButton_24;
    QPushButton *pushButton_25;
    QPushButton *pushButton_26;
    QPushButton *pushButton_27;
    QPushButton *pushButton_28;
    QPushButton *pushButton_29;
    QPushButton *pushButton_30;
    QPushButton *pushButton_31;
    QPushButton *pushButton_32;
    QPushButton *pushButton_33;
    QPushButton *pushButton_34;
    QPushButton *pushButton_35;
    QPushButton *pushButton_36;
    QPushButton *pushButton_37;
    QPushButton *pushButton_38;
    QPushButton *pushButton_39;
    QPushButton *pushButton_40;
    QPushButton *pushButton_41;
    QPushButton *pushButton_42;
    QPushButton *pushButton_43;
    QPushButton *pushButton_44;
    QPushButton *pushButton_45;
    QPushButton *pushButton_46;
    QPushButton *pushButton_47;
    QPushButton *pushButton_48;
    QPushButton *pushButton_49;
    QPushButton *pushButton_50;
    QPushButton *pushButton_51;
    QPushButton *pushButton_52;

};

#endif // SOFTKEYBOARD_H
