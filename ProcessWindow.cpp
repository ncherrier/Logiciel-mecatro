

#include "ProcessWindow.h"
#include "SettingsWindow.h"
#include "SerialCommunication.h"
#include <QGridLayout>
#include <iostream> // TODO: remove after tests

using namespace std;

// Slots

void ProcessWindow::emergencyStop() {

std::cout << "calling ProcessWindow::emergencyStop();" << std::endl;

//SerialCommunication::emergencyStop();

// retour aux reglages (SettingsWindow)
// (ou a une autre fenetre ? a reflechir)
SettingsWindow* set = new SettingsWindow;
set->show();

this->close();
}

// Default constructor
ProcessWindow::ProcessWindow()
{
setWindowTitle("In process...");
setFixedSize(800,400);
stopButton = new QPushButton("Stop");

QObject::connect(stopButton, SIGNAL(clicked()), this, SLOT(emergencyStop()));

// Layout

QGridLayout *layout = new QGridLayout;
layout->addWidget(stopButton);
setLayout(layout);
}

