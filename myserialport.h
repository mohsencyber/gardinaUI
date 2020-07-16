#ifndef MYSERIALPORT_H
#define MYSERIALPORT_H

#include <QSerialPort>
#include <QTimer>
#include <iostream>

class MySerialPort
{
public:
    explicit MySerialPort(QString& portName, int& buadRate );

    bool open();
    bool isOpen();
    void close();
    void write(const QByteArray &writeData,int &interval);
    bool waitforwrite();

public :
    QString m_portName;
    QSerialPort m_serialPort;
    QByteArray m_writeData;
    qint64 m_bytesWritten = 0;
    QTimer m_timer;
};

#endif // MYSERIALPORT_H
