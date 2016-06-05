// In main programm

#ifndef SERIALCOMMUNICATION_H
#define SERIALCOMMUNICATION_H

#include <QtSerialPort>
#include <QWidget>

class SerialCommunication : public QWidget
{
	// Comment this when on release, uncomment when debug
    Q_OBJECT

private:
    QString         m_serialPortName; // utile ???
    QSerialPort     *m_serialPort;
    QByteArray      m_writeData;
    QByteArray      m_readData;
    QTextStream     m_standardOutput;
    qint64          m_bytesWritten;
    //QTimer          m_timer; // utile ???

    // Se connecter a un port (appele dans constructeur)
    // returns true if no problem (pas tres utile en vrai)
    bool connectSerialPort();

    // Ecriture - low-level
    void write(QByteArray);

public slots:

    // Ecriture - high-level
    void moveCameraToNextPosition(); // after picture has been taken: tell elec to move camera (over serial port)
    // "o"
    void moveCameraTo(int, int);
    // ex: "b 30 50"
    void emergencyStop();
    // "s"
    void startCycle(); // start the cycle to take a (global) picture
    // "a"

    // Lecture
    void handleReadyRead();

public:
    // Constructor and destructor
	SerialCommunication();
    virtual ~SerialCommunication();

signals:
    // Suite a la lecture
	void MvtFinished();
    void CycleFinished();

};

#endif // SERIALCOMMUNICATION_H
