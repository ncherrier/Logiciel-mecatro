// In main programm

#include "SerialCommunication.h"

#include <iostream> // TODO: remove after tests

#include <QtSerialPort>

#include <QTextStream>
#include <QCoreApplication>
#include <QFile>
#include <QStringList>

using namespace std;

// Default constructor, inherits QObject()
SerialCommunication::SerialCommunication()
    : QObject()
    , m_standardOutput(stdout)
    , m_bytesWritten(0)
{
    cout << "SerialCommunication constructor called" << endl;

     m_serialPortName = "Arduino";

    m_serialPort = new QSerialPort(this);

    // TODO?
}

bool SerialCommunication::connectSerialPort(){

    cout << "calling SerialCommunication::connectSerialPort()" << endl;

	int portCount = QSerialPortInfo::availablePorts().count();

	if (portCount == 0) {
        m_standardOutput << "No serial port found" << endl;
        return false;
	}

    m_serialPort->setPort(QSerialPortInfo::availablePorts()[0]);
    m_serialPort->setBaudRate(QSerialPort::Baud9600);

	return true;

}



// Low-level communication (read and write - TODO)

bool SerialCommunication::sendMessage(QByteArray c){

	cout << "calling SerialCommunication::sendMessage" << endl;

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

}

// Permet de lire un "a"
// lecture synchrone (blocking)
// preferer lecture asynchrone ?
bool SerialCommunication::read(){
	QTextStream standardOutput(stdout);

	int portCount = QSerialPortInfo::availablePorts().count();

	if (portCount == 0) {
		standardOutput << "No serial port found" << endl;
		return 1;
	}

	QSerialPort serialPort;
	QString serialPortName = "Arduino";
	serialPort.setPort(QSerialPortInfo::availablePorts()[0]);

	serialPort.setBaudRate(QSerialPort::Baud9600);

	if (!serialPort.open(QIODevice::ReadWrite)) {
		standardOutput << QObject::tr("Failed to open port %1, error: %2").arg(serialPortName).arg(serialPort.errorString()) << endl;
		return 1;
	}

	//Lecture

	//QByteArray readData = serialPort.readAll();

	bool isReading = false;

	while (serialPort.waitForReadyRead(-1) & !isReading)
		if (serialPort.readAll() == "a") {
			standardOutput << "Message bien recu" << endl;
			isReading = true;
		}
	standardOutput << serialPort.readAll() << endl;


	/* //Message d'erreur
	if (serialPort.error() == QSerialPort::ReadError) {
	standardOutput << QObject::tr("Failed to read from port %1, error: %2").arg(serialPortName).arg(serialPort.errorString()) << endl;
	return 1;
	} else if (serialPort.error() == QSerialPort::TimeoutError && readData.isEmpty()) {
	standardOutput << QObject::tr("No data was currently available for reading from port %1").arg(serialPortName) << endl;
	return 0;
	}
	*/

	standardOutput << QObject::tr("Data successfully received from port %1").arg(serialPortName) << endl;
}


// Higher-level functions
// Try several times ? a reflechir

void SerialCommunication::emergencyStop() {
	cout << "calling SerialCommunication::emergencyStop()" << endl;
    sendMessage("s");
}

// Move camera

//bool SerialCommunication::goUp(){
    //cout << "calling SerialCommunication::goUp()" << endl;
    //return sendMessage("u"); // voir avec l'elec
//}

//bool SerialCommunication::goDown(){
    //cout << "calling SerialCommunication::goDown()" << endl;
    //return sendMessage("d"); // voir avec l"elec
//}

//bool SerialCommunication::goLeft(){
//	cout << "calling SerialCommunication::goLeft()" << endl;
//	return sendMessage("l"); // voir avec l'elec
//}

//bool SerialCommunication::goRight(){
//	cout << "calling SerialCommunication::goRight()" << endl;
//	return sendMessage("r"); // voir avec l'elec
//}

void SerialCommunication::moveCameraTo(int x, int y){

    cout << "calling SerialCommunication::goTo(" << x << "," << y << ")" << endl;

    const char* x_char = (char *) x; // WARNING "integer of different size"
    const char* y_char = (char *) y;

    (sendMessage("b") && sendMessage(x_char) && sendMessage(y_char));
    // TODO: verifier protocole de communication avec elec
}

void SerialCommunication::startCycle() {
    cout << "calling SerialCommunication::startCycle()" << endl;
    sendMessage("a");
}

void SerialCommunication::moveCameraToNextPosition() {
    cout << "calling SerialCommunication::moveCameraToNextPosition()" << endl;
    sendMessage("o"); // "OK"
}


