#include "SerialCommunication.h"

#include <iostream> // TODO: remove after tests

#include <QtSerialPort>

#include <QTextStream>
#include <QCoreApplication>
#include <QFile>
#include <QStringList>

using namespace std;


bool SerialCommunication::connectSerialPort(){

	int portCount = QSerialPortInfo::availablePorts().count();

	if (portCount == 0) {
		return false;
	}

	QSerialPort serialPort;
	QString serialPortName = "Arduino";
	serialPort.setPort(QSerialPortInfo::availablePorts()[0]);
	serialPort.setBaudRate(QSerialPort::Baud9600);

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
	QByteArray writeData = c; //Caractère à choisir

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
			standardOutput << "Message bien reçu" << endl;
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

bool SerialCommunication::emergencyStop() {
	cout << "calling SerialCommunication::emergencyStop()" << endl;
	return sendMessage("s");
}

// Move camera

bool SerialCommunication::goUp(){
	cout << "calling SerialCommunication::goUp()" << endl;
	return sendMessage("u"); // voir avec l'elec
}

bool SerialCommunication::goDown(){
	cout << "calling SerialCommunication::goDown()" << endl;
	return sendMessage("d"); // voir avec l"elec
}

bool SerialCommunication::goLeft(){
	cout << "calling SerialCommunication::goLeft()" << endl;
	return sendMessage("l"); // voir avec l'elec
}

bool SerialCommunication::goRight(){
	cout << "calling SerialCommunication::goRight()" << endl;
	return sendMessage("r"); // voir avec l'elec
}

/*bool SerialCommunication::goTo(int x, int y){
cout << "calling SerialCommunication::goTo(" << x << "," << y << ")" << endl;
return (sendMessage("c") && sendMessage(x) && sendMessage(y));
// TODO: verifier protocole de communication avec elec
}*/

bool SerialCommunication::pictureTaken() {
	cout << "calling SerialCommunication::pictureTaken()" << endl;
	return sendMessage("o"); // "OK"
}



