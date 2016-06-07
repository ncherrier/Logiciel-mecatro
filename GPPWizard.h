// Wizard to use the GigaProxyPhoto system

#ifndef GPPWIZARD_H
#define GPPWIZARD_H

#include <QWizard>

#include "SerialCommunication.h"

#include <QtMultimedia> // useful?

#include "SettingsPage.h"
#include "ProgressPage.h"
#include "FocusWindow.h"
#include "SerialCommunication.h"

class GPPWizard : public QWizard
{
   // Q_OBJECT

public:
    GPPWizard();
    QCameraInfo const getWebcamInfo(); // useful???
	void Log(std::string strMsg);

	QPushButton * goButton;
	QPushButton * stopButton;

    // functions to create the 4 pages of the wizard
    QWizardPage *createIntroPage();
    QWizardPage *createFramingPage();
    QWizardPage *createSettingsPage();
    ProgressPage *createProgressPage();

    QWizardPage *introPage;
    QWizardPage *framingPage;
    QWizardPage *settingsPage;
    ProgressPage *progressPage;

    FocusWindow * focuswindow;
	SerialCommunication * serialcomm;

    int getWishedXPos(); //utile ?
    int getWishedYPos(); //utile ?

    // camera position (instruction to be given to Arduino)
    // as a percentage
    //int wishedXPos;
    //int wishedYPos;

};

#endif // GPPWIZARD_H
