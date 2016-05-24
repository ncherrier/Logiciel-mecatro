/* Fenetre pour les reglages :
* Choix de l'emplacement de la mise au point,
* Retour video (camera indus.) pour la mise au point,
* Retour video (webcam) (pour situer l'endroit de la mise au point)
* Acces aux reglages de la camera indus. (et de la webcam ?),
* Acces au choix de dossier de destination.
* */

#include <QApplication>
#include <QPushButton>
#include <iostream>
#include <QGridLayout>
#include "FramingWindow.h" // TODO: remove after tests
#include "SettingsWindow.h"
#include "ProcessWindow.h"
#include "Main_Prog.h"
#include "SerialCommunication.h"
#include "cameraSettingsWindow.h"

using namespace std;

// Slots and functions
void SettingsWindow::goToProcessWindow() {
	ProcessWindow *pro = new ProcessWindow;
	pro->show();
	this->close();
}

void SettingsWindow::goToFramingWindow() {
	FramingWindow *fra = new FramingWindow;
	fra->show();
	this->close();
}

void SettingsWindow::openCameraSettings() {
	CameraSettingsWindow *cam = new CameraSettingsWindow(this);
	cam->exec();
}

void SettingsWindow::startCycle() {
	// TODO !!
	goToProcessWindow();
	startCycle();
}

// give instructions to move camera

bool SettingsWindow::goUp() {
	return SerialCommunication::goUp();
}

bool SettingsWindow::goDown() {
	return SerialCommunication::goDown();
}

bool SettingsWindow::goLeft() {
	return SerialCommunication::goLeft();
}

bool SettingsWindow::goRight() {
	return SerialCommunication::goRight();
}


// Constructors and destructors

// Default Constructor
SettingsWindow::SettingsWindow() {

	// provisory
	cout << "TODO: inclure flux video webcam et camera" << endl;

	// Set size

	setFixedSize(800, 400);
	setWindowTitle("Mise au point et reglages");

	// Buttons

	upButton = new QPushButton("Up ^");
	leftButton = new QPushButton("< Left");
	downButton = new QPushButton("Down v");
	rightButton = new QPushButton("Right >");

	finishButton = new QPushButton("Finish >");
	previousButton = new QPushButton("< Previous");

	cameraSettingsButton = new QPushButton("Indus. camera settings");

	//QPushButton RegisterSettingsButton("Register settings"); // To open a window to choose the repository to save photos. Useful ??


	// Add signals and slots (interactions with user)
	QObject::connect(finishButton, SIGNAL(clicked()), this, SLOT(startCycle()));
	QObject::connect(previousButton, SIGNAL(clicked()), this, SLOT(goToFramingWindow()));
	QObject::connect(cameraSettingsButton, SIGNAL(clicked()), this, SLOT(openCameraSettings()));
	QObject::connect(upButton, SIGNAL(clicked()), this, SLOT(goUp()));
	QObject::connect(downButton, SIGNAL(clicked()), this, SLOT(goDown()));
	QObject::connect(leftButton, SIGNAL(clicked()), this, SLOT(goLeft()));
	QObject::connect(rightButton, SIGNAL(clicked()), this, SLOT(goRight()));


	// Layout

	QGridLayout *layout = new QGridLayout;

	layout->addWidget(upButton);
	layout->addWidget(leftButton);
	layout->addWidget(downButton);
	layout->addWidget(rightButton);
	layout->addWidget(finishButton);
	layout->addWidget(previousButton);
	layout->addWidget(cameraSettingsButton);

	setLayout(layout);

}




