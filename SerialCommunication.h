// In main programm

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
    static bool read(); // reads an "a"

public:

	SerialCommunication();

	// Higher-level functions

    // Stop!
    static bool emergencyStop(); // "s"

    // Movement
    //static bool goUp();
    //static bool goDown();
    //static bool goLeft();
    //static bool goRight();
    static bool goTo(int,int); // move camera (e. g. to focus). Args = percentage
    // ex: "b 10 10"

    static bool startCycle(); // start the cycle to take a (global) picture
    // "a"
    // > utile ?

    // About pictures...
	static bool pictureTaken(); // signals that the picture has been taken, so that elec can move the camera
    // "o"

};

#endif // SERIALCOMMUNICATION_H
