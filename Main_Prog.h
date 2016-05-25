/*

#ifndef MAINPROG_H
#define MAINPROG_H

#include <QtWidgets/QApplication>
#include "cameraSettingsWindow.h"
#include "FramingWindow.h"
#include "SettingsWindow.h"
#include "ProcessWindow.h"

class MainProg : public QObject
{

public:
QApplication *app;

// Constructors and destructor
//MainProg(); // Default constructor, not to be used in normal conditions
MainProg(int, char**); // "Right" constructor, with args of main
virtual ~MainProg(); // Default destructor

// To take a global picture
//static bool startCycle();
// will be called by the User Interface
// returns true if the process was executed normally

private:
int mainFunction();

};

#endif // MAINPROG_H

*/
