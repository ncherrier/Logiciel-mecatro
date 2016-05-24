
#include <QtWidgets/QApplication>
//#include <QPushButton>
#include <iostream>
#include "cameraSettingsWindow.h"
#include "SettingsWindow.h"
#include "FramingWindow.h"
#include "ProcessWindow.h"
#include "SerialCommunication.h"
#include "Main_Prog.h"
#include "TakePictureTest.h" // for tests only

using namespace std;


// Algorithm to take a global picture
// will be called by the User Interface
// take subpictures and communcate with Electronics to move the Industrial Camera
// returns true if the process was executed normally

bool MainProg::startCycle() {


	// TODO: change return so that one can know whether everything went good or not (or use exceptions ?)

	return true;
}

// main programm
int MainProg::mainFunction(){

	//*****************For tests only*****************
	cout << "hello! in MainProg::MainFunction" << endl;

	TakePictureTest *tak = new TakePictureTest();
	tak->show();
	//************************************************


	// First window showed: FramingWindow
	//FramingWindow *fra = new FramingWindow();
	//fra->show();
	//cout << "FramingWindow shown" << endl;


	return app->exec();
}

// Constructor (with arguments of main)
MainProg::MainProg(int argc, char **argv)
{

	app = new QApplication(argc, argv);
	mainFunction();

}


// Default constructor (no argument)
//MainProg::MainProg() {

//    char * argv = new char[1]();
//    app = new QApplication(0, *argv);
//    mainFunction();

//}
// TODO: uncomment, regler le bug pour avoir une belle syntaxe. inutile en soi

// Default destructor

MainProg::~MainProg(){

}



// TODO: Remove after tests (?)
int main(int argc, char *argv[])
{
	cout << "hello! in main" << endl;
	//QApplication const * MainProg::app = new QApplication(argc, argv);
	MainProg mainProg(argc, argv);

}
