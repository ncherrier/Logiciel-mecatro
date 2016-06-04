#include "SettingsPage.h"
#include <iostream> // for tests

int SettingsPage::getWishedXPos(){
    return XPosBox->value();
}

int SettingsPage::getWishedYPos(){
    return YPosBox->value();
}

// slots
void SettingsPage::openCameraSettings() {
    std::cout << "TODO: open cameraSettingsWindow" << std::endl;
    //CameraSettingsWindow *cam = new CameraSettingsWindow(this);
    //cam->exec();
    // TODO: uncomment - & solve bug
}

void SettingsPage::moveCamera(){
    // "internal memory" of this page
    realXPos = getWishedXPos();
    realYPos = getWishedYPos();
    // actual movement: communicate with Arduino
    // TODO
}

void SettingsPage::restoreToActualValues() {
    XPosBox->setValue(realXPos);
    YPosBox->setValue(realYPos);
}

SettingsPage::SettingsPage() : QWizardPage()
{

    setTitle("Mise au point et reglages");

    label = new QLabel("Faites la mise au point (a l'aide du bouton poussoir) et au besoin reglez la caméra industrielle. \nVous pouvez deplacer la camera : precisez la position voulue sous forme de pourcentage. Le coin superieur gauche correspond à 0 0, le coin inferieur droit à 100 100.");
    label->setWordWrap(true);

    // Camera position settings
    XPosBox = new QSpinBox();
    XPosBox->setMinimum(0); // TODO: check values with elec
    XPosBox->setMaximum(100);
    XPosBox->setSingleStep(1);
    XPosBox->setAccelerated(true);
    XPosBox->setSuffix("%");

    YPosBox = new QSpinBox();
    YPosBox->setMinimum(0); // TODO: check values with elec
    YPosBox->setMaximum(100);
    YPosBox->setSingleStep(1);
    YPosBox->setAccelerated(true);
    YPosBox->setSuffix("%");

    moveButton = new QPushButton("Move camera");
    realButton = new QPushButton("Show actual values");

    cameraSettingsButton = new QPushButton("Indus. camera settings");

    QObject::connect(moveButton, SIGNAL(clicked()), this, SLOT(moveCamera()));
    QObject::connect(realButton, SIGNAL(clicked()), this, SLOT(restoreToActualValues()));
    QObject::connect(cameraSettingsButton, SIGNAL(clicked()), this, SLOT(openCameraSettings()));

    QGridLayout * layout = new QGridLayout(this);

    //TODO: uncomment follwing line - bug to solve in cameraSettingsWindow.h & .cpp
    //(usefull only if it's possible to set exposure time on Mako)
    //QObject::connect(cameraSettingsButton, SIGNAL(clicked()), this, SLOT(openCameraSettings()));

    layout->addWidget(label);
    layout->addWidget(XPosBox);
    layout->addWidget(YPosBox);
    layout->addWidget(realButton);
    layout->addWidget(moveButton);
    layout->addWidget(cameraSettingsButton);

    setLayout(layout);
}


