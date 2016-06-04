// Wizard to use the GigaProxyPhoto system

#ifndef GPPWIZARD_H
#define GPPWIZARD_H

#include <QWidget>
#include <QWizard>

#include "SerialCommunication.h"

#include <QtMultimedia>

#include "SettingsPage.h"
#include "FocusWindow.h"

class GPPWizard : public QWizard
{
    Q_OBJECT

public:
    GPPWizard();
	QCameraInfo const getWebcamInfo();

public slots:
    //bool goUp();
    //bool goDown();
    //bool goLeft();
    //bool goRight();
    void openCameraSettings();

private:
    // functions to create the 4 pages of the wizard
    QWizardPage *createIntroPage();
    QWizardPage *createFramingPage();
    QWizardPage *createSettingsPage();
    QWizardPage *createInProcessPage();

    QWizardPage *introPage;
    QWizardPage *framingPage;
    QWizardPage *settingsPage;
    QWizardPage *inProcessPage;

	FocusWindow * focuswindow;

    int getWishedXPos();
    int getWishedYPos();

    // camera position (instruction to be given to Arduino)
    // as a percentage
    //int wishedXPos;
    //int wishedYPos;

};

#endif // GPPWIZARD_H
