#include "ProgressPage.h"
#include <iostream> // for tests

ProgressPage::ProgressPage()
    : QWizardPage()
{
    setTitle("In process...");

    bar = new QProgressBar();
    bar->setMinimum(0);
    bar->setMaximum(100); //TODO: bonne valeur ???
    bar->setValue(0);

    stopButton = new QPushButton("Arret d'urgence");

    connect(stopButton, SIGNAL(clicked()), bar, SLOT(reset()));

    //layout
    QGridLayout * layout = new QGridLayout();
    layout->addWidget(bar);
    layout->addWidget(stopButton);
    setLayout(layout);

}

void ProgressPage::incNbPicturesTaken() {
    bar->setValue(bar->value()+1);
    std::cout << "in ProgressPage : nbPicturesTaken += 1" << std::endl;
}

//void ProgressPage::onStopButtonClicked() {

//}

QPushButton* ProgressPage::getStopButton() {
    return stopButton;
}
