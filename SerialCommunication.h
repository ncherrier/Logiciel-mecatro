// In main programm

#ifndef SERIALCOMMUNICATION_H
#define SERIALCOMMUNICATION_H

#include <QtSerialPort>

class SerialCommunication : QObject
{

    Q_OBJECT

	// All static functions below return true if everything went good

private:
    QString         m_serialPortName; // utile ???
    QSerialPort     *m_serialPort;
    QByteArray      m_writeData;
    QTextStream     m_standardOutput;
    qint64          m_bytesWritten;
    //QTimer          m_timer; // utile ???

	// Low-level communication
    bool connectSerialPort();
	static bool sendMessage(QByteArray);
    static bool read(); // reads an "a"

public slots:
    void moveCameraToNextPosition(); // after picture has been taken: tell elec to move camera (over serial port)
    // "o"
    void moveCameraTo(int, int);
    // ex: "b 30 50"
    void emergencyStop();
    // "s"
    void startCycle(); // start the cycle to take a (global) picture
    // "a"
    // > utile ?

public:

	SerialCommunication();

	// Higher-level functions

};

#endif // SERIALCOMMUNICATION_H
