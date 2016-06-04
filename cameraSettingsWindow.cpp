//TODO: uncomment .ccp and .h - and solve bug.
//(usefull only if it's possible to set exposure time on Mako)


/*
#include "cameraSettingsWindow.h"
#include <QGridLayout>
#include <iostream> // for tests only


// Slots

void CameraSettingsWindow::reset(){
	std::cout << "calling slot CameraSettingsWindow::reset()" << std::endl;
	// TODO (set to default values)
}

void CameraSettingsWindow::apply() {
	std::cout << "calling slot CameraSettingsWindow::apply()" << std::endl;
	// calculate value set by user
	double time = 1 / (exposureTimeBox->value());
	// TODO (store settings and communicate with camera !!)
}

void CameraSettingsWindow::validate() {
	std::cout << "calling slot CameraSettingsWindow::validate()" << std::endl;
	apply();
	close();
}

// Default constructor
//CameraSettingsWindow::CameraSettingsWindow(){}

// Constructor
CameraSettingsWindow::CameraSettingsWindow(QWidget *parent) :QDialog(parent) {

	setFixedSize(400, 500); // a regler
	setWindowTitle("Industrial camera settings");

	// Buttons and slots

	resetButton = new QPushButton("Reset");
	applyButton = new QPushButton("Apply");
	cancelButton = new QPushButton("Cancel");
	validateButton = new QPushButton("OK");

	exposureTimeBox = new QSpinBox();
	exposureTimeBox->setMinimum(1);
	exposureTimeBox->setMaximum(400);
	exposureTimeBox->setSingleStep(1);
	exposureTimeBox->setAccelerated(true);
	exposureTimeBox->setPrefix("1/");
	exposureTimeBox->setSuffix(" s");

	QObject::connect(resetButton, SIGNAL(clicked()), this, SLOT(reset()));
	QObject::connect(applyButton, SIGNAL(clicked()), this, SLOT(apply()));
	QObject::connect(cancelButton, SIGNAL(clicked()), this, SLOT(close())); // suffit ? a verifier
	QObject::connect(validateButton, SIGNAL(clicked()), this, SLOT(validate()));

	// Layout

	QGridLayout *layout = new QGridLayout;

	layout->addWidget(exposureTimeBox);
	layout->addWidget(resetButton);
	layout->addWidget(applyButton);
	layout->addWidget(cancelButton);
	layout->addWidget(validateButton);

	setLayout(layout);

	// TODO: set to previous settings ??
	// else set to default settings:
	reset();

}
*/
