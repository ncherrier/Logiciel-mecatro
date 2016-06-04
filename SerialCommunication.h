

#ifndef SERIALCOMMUNICATION_H
#define SERIALCOMMUNICATION_H

#include <QtSerialPort>

class SerialCommunication
{

	// All static functions below return true if everything went good

private:
	// Low-level communication
	static bool connectSerialPort();
	static bool sendMessage(QByteArray);
	static bool read();

public:
	SerialCommunication();

	// Higher-level functions
	// Stop!
	static bool emergencyStop();
	// Movement
	static bool goUp();
	static bool goDown();
	static bool goLeft();
	static bool goRight();
    static bool goTo(int, int);
	// static bool goTo(int,int); // move camera (e. g. to focus). Args = percentage // utile ??
	// About pictures...
	//static bool startCycle(); // start the cycle to take a (global) picture
	static bool pictureTaken(); // signals that the picture has been taken, so that elec can move the camera

};

#endif // SERIALCOMMUNICATION_H
