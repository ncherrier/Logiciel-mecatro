// In main programm

#include "SerialCommunication.h"

#include <iostream> // TODO: remove after tests

#include <QtSerialPort>

#include <QTextStream>
#include <QCoreApplication>
#include <QFile>
#include <QStringList>

using namespace std;

bool SerialCommunication::connectSerialPort(){

    cout << "calling SerialCommunication::connectSerialPort()" << endl;

    int portCount = QSerialPortInfo::availablePorts().count();

    if (portCount == 0) {
        m_standardOutput << "No serial port found" << endl;
        return false;
    }

    else {

        m_serialPort->setPort(QSerialPortInfo::availablePorts()[0]);
        m_serialPort->setBaudRate(QSerialPort::Baud9600);

    }

    return true;

}

// Default constructor, inherits QWidget()
SerialCommunication::SerialCommunication()
    : QWidget()
    , m_standardOutput(stdout)
    , m_bytesWritten(0)
{
   cout << "SerialCommunication constructor called" << endl;

   m_serialPortName = "Arduino";

   m_serialPort = new QSerialPort(this);

   connectSerialPort();

   // pour la lecture
   QObject::connect(m_serialPort, &QSerialPort::readyRead, this, &SerialCommunication::handleReadyRead);

}

// Default destructor
SerialCommunication::~SerialCommunication() {
    //m_serialPort->close(); // utile ???
}


// Ecriture - low-level
void SerialCommunication::write(QByteArray c){

    cout << "calling SerialCommunication::write" << endl;

    // TODO: ouvrir le port ?
    //if (!m_serialPort->open(QIODevice::ReadWrite)) {
    //    m_standardOutput << QObject::tr("Failed to open port %1, error: %2").arg(m_serialPortName).arg(m_serialPort->errorString()) << endl;
    //    return;
    //}

    m_writeData = c;

    m_bytesWritten = m_serialPort->write(m_writeData); // ecriture proprement dite

    // verification : message correctement transmis ?

    // verifier les problemes possibles
    if (m_bytesWritten == -1) {
        //standardOutput << QObject::tr("Failed to write the data to port %1, error: %2").arg(m_serialPortName).arg(m_serialPort->errorString()) << endl;
        return;
	}
    else if (m_bytesWritten != m_writeData.size()) {
        //standardOutput << QObject::tr("Failed to write all the data to port %1, error: %2").arg(m_serialPortName).arg(m_serialPort->errorString()) << endl;
        return;
	}
    else if (!m_serialPort->waitForBytesWritten(5000)) {
        //standardOutput << QObject::tr("Operation timed out or an error occurred for port %1, error: %2").arg(serialPortName).arg(serialPort->errorString()) << endl;
        return;
	}

    // si on arrive ici, c'est que tout s'est bien passe
    m_standardOutput << QObject::tr("Data successfully sent to port %1").arg(m_serialPortName) << endl;

    // TODO: fermer le port ???
    //m_serialPort->close();
    // choix a faire :
    // a chaque fois, ouvrir le port/ecrire/fermer, ou bien
    // ouvrir une fois pour toutes, ecrire les differents messages, fermer le port a la fin seulement
    // (question des performances ? i.e. du temps)

}

// ci-dessous version fonctionnelle de secours (pas tres propre; "statique" ; tout code a la volee)
/*
bool SerialCommunication::write(QByteArray c){

    cout << "calling SerialCommunication::write" << endl;

    QTextStream standardOutput(stdout);

    int portCount = QSerialPortInfo::availablePorts().count();

    if (portCount == 0) {
        standardOutput << "No serial port found" << endl;
        return false;
    }

    QSerialPort serialPort;
    QString serialPortName = "Arduino";
    serialPort.setPort(QSerialPortInfo::availablePorts()[0]);

    serialPort.setBaudRate(QSerialPort::Baud9600);

    if (!serialPort.open(QIODevice::ReadWrite)) {
        standardOutput << QObject::tr("Failed to open port %1, error: %2").arg(serialPortName).arg(serialPort.errorString()) << endl;
        return false;
    }
    QByteArray writeData = c; //Caractere a choisir

    qint64 bytesWritten = serialPort.write(writeData);

    if (bytesWritten == -1) {
        //standardOutput << QObject::tr("Failed to write the data to port %1, error: %2").arg(serialPortName).arg(serialPort.errorString()) << endl;
        return false;
    }
    else if (bytesWritten != writeData.size()) {
        //standardOutput << QObject::tr("Failed to write all the data to port %1, error: %2").arg(serialPortName).arg(serialPort.errorString()) << endl;
        return false;
    }
    else if (!serialPort.waitForBytesWritten(5000)) {
        //standardOutput << QObject::tr("Operation timed out or an error occurred for port %1, error: %2").arg(serialPortName).arg(serialPort.errorString()) << endl;
        return false;
    }

    standardOutput << QObject::tr("Data successfully sent to port %1").arg(serialPortName) << endl;
    serialPort.close();

    return true;

}*/


// Ecriture - higher-level functions

void SerialCommunication::emergencyStop() {
	cout << "calling SerialCommunication::emergencyStop()" << endl;
    write("s");
}

void SerialCommunication::moveCameraTo(int x, int y){

    cout << "calling SerialCommunication::goTo(" << x << "," << y << ")" << endl;

    //TODO: fabriquer la bonne chaine de caracteres (pas sure de ce code-ci)
    const char* x_char = (char *) x; // WARNING "integer of different size"
    const char* y_char = (char *) y;

    write("b");
    write(x_char);
    write(y_char);

    // TODO: verifier protocole de communication avec elec

}

void SerialCommunication::startCycle() {
    cout << "calling SerialCommunication::startCycle()" << endl;
    write("a");
}

void SerialCommunication::moveCameraToNextPosition() {
    cout << "calling SerialCommunication::moveCameraToNextPosition()" << endl;
    write("o"); // "OK"
}

// Lecture

void SerialCommunication::handleReadyRead() {

    m_readData = m_serialPort->readAll();
    m_standardOutput << "Nouveau message recu : " << m_readData << endl;

    if (m_readData == "a") {
        emit MvtFinished();
    } else if (m_readData == "c") {// TODO: check character with elec!!
        emit CycleFinished();
    }

    // on peut rajouter d'autres signaux...

}
