// To focus and to open camera setting window (exposure time)

#ifndef SETTINGSPAGE_H
#define SETTINGSPAGE_H

#include <QWizardPage>
#include <QSpinBox>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include "SerialCommunication.h"

class SettingsPage : public QWizardPage
{

    Q_OBJECT

private:
    QLabel * label;
    QSpinBox * XPosBox;
    QSpinBox * YPosBox;
    QPushButton * moveButton;
    QPushButton * realButton;
    QPushButton * cameraSettingsButton;
    int realXPos;
    int realYPos;

public:
    SettingsPage();
    int getWishedXPos();
    int getWishedYPos();

public slots:
    void openCameraSettings();
    void moveCamera();
    void restoreToActualValues();

};

#endif // SETTINGSPAGE_H
