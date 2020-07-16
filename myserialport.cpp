#include "myserialport.h"
#include <QSerialPort>
#include <QFile>
//#include <QtSerialPort>

MySerialPort::MySerialPort(QString& portName, int& baudRate)
{
    //m_timer.setSingleShot(true);

    m_serialPort.setPortName(portName);
    m_serialPort.setParity(QSerialPort::NoParity);
    m_serialPort.setBaudRate(baudRate);
    m_serialPort.setStopBits(QSerialPort::OneStop);
    m_serialPort.setDataBits(QSerialPort::Data8);

    //connect(&m_timer, &QTimer::timeout, this, &SerialPortWriter::handleTimeout);
}

bool MySerialPort::open()
{
    QFile memoryFile("myapp.log");

    if ( m_serialPort.isOpen() )
        return true;

    return m_serialPort.open(QIODevice::WriteOnly);
}

bool MySerialPort::isOpen()
{
    return m_serialPort.isOpen();
}

void MySerialPort::close()
{
    if ( m_serialPort.isOpen())
        m_serialPort.close();
}

void MySerialPort::write(const QByteArray &writeData,int &interval)
{
    m_writeData = writeData;

    const qint64 bytesWritten = m_serialPort.write(writeData);

    if (bytesWritten == -1) {
        m_serialPort.write(writeData);
    } else if (bytesWritten != m_writeData.size()) {
        //while(m_serialPort.waitForBytesWritten());
        m_writeData = writeData;
    }

    //m_timer.setInterval(interval);
    //m_timer.start();
}

bool MySerialPort::waitforwrite()
{
    return m_serialPort.waitForBytesWritten(5000);
}
