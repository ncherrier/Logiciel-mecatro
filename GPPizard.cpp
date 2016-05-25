#include "GPPWizard.h"
//#include <QPushButton>
#include <QtMultimedia>
#include <QtMultimediaWidgets>
#include <QVideoWidget>
#include "cameraSettingsWindow.h"
#include <iostream> // for tests
#include <Main_Prog.h>

QWizardPage * GPPWizard::createIntroPage()
{
    QWizardPage *page = new QWizardPage;
    page->setTitle("Bienvenue");

    return page;
}

QWizardPage * GPPWizard::createFramingPage()
{
    // Basics
    QWizardPage *page = new QWizardPage;
    page->setTitle("cadrage");
    QLabel *label = new QLabel("Verifiez que le cadrage vous convient, puis passez a l'etape suivante.");
    label->setWordWrap(true);

    // Webcam
    /*QCamera camera(getWebcamInfo());
    QWidget * videoContainer = new QWidget(page);
    QVideoWidget * videoWidget = new QVideoWidget(videoContainer);
    videoWidget->resize(200,120);
    camera.setViewfinder(videoWidget);
    camera.start();*/
    //cout << "Camera started" << endl;

    // Test
    //QPushButton * testButton = new QPushButton("Test");

    // Buttons


    // Layout
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(label, 1, 1);
    //layout->addWidget(videoContainer, 2, 1);
    //layout->addWidget(testButton, 3, 1);

    page->setLayout(layout);

    //videoContainer->show();
    //videoWidget->show();

    return page;
}

QWizardPage * GPPWizard::createSettingsPage()
{
    QWizardPage *page = new QWizardPage;
    page->setTitle("Mise au point et reglages");
    return page;
}

QWizardPage * GPPWizard::createInProcessPage()
{
    QWizardPage *page = new QWizardPage;
    page->setTitle("In process...");
    return page;
}

GPPWizard::GPPWizard() : QWizard()
{
    addPage(createIntroPage());

    // Framing page
    QWizardPage * framingPage = createFramingPage();

    // Add video
    QCamera webcam(getWebcamInfo());
    QWidget * videoContainer = new QWidget();
    QVideoWidget * videoWidget = new QVideoWidget(videoContainer);
    videoWidget->resize(200, 120);

    webcam.setViewfinder(videoWidget);
    webcam.start();

    framingPage->layout()->addWidget(videoContainer);

    addPage(framingPage);
    // End framing page

    addPage(createSettingsPage());
    addPage(createInProcessPage());

    setWindowTitle("GigaProxyPhoto");
    show();


}

