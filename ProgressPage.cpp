#include "ProgressPage.h"
// for tests
#include <iostream> 
#include <QFile>
#include <QTextStream>

using namespace std;

void ProgressPage::Log(std::string strMsg)
{
	QString filename = "Data.txt";
	QFile file(filename);
	if (file.open(QIODevice::ReadWrite | QIODevice::Append))
	{
		QTextStream stream(&file);
		stream << QString::fromUtf8(strMsg.c_str()) << endl;
	}
}

ProgressPage::ProgressPage()
    : QWizardPage()
{
    setTitle("In process...");

    bar = new QProgressBar();
    bar->setMinimum(0);
    bar->setMaximum(100); //TODO: bonne valeur ???
    bar->setValue(0);

	goButton = new QPushButton("Go!");
    stopButton = new QPushButton("Arret d'urgence");

    //connect(stopButton, SIGNAL(clicked()), bar, SLOT(reset()));
	connect(goButton, SIGNAL(clicked()), this, SLOT(handleGoButtonClicked()));
	connect(stopButton, SIGNAL(clicked()), this, SLOT(handleStopButtonClicked()));

    //layout
    QGridLayout * layout = new QGridLayout();
	layout->addWidget(goButton);
    layout->addWidget(bar);
    layout->addWidget(stopButton);
    setLayout(layout);

}

void ProgressPage::incNbPicturesTaken() {
    bar->setValue(bar->value()+1);
    std::cout << "in ProgressPage : nbPicturesTaken += 1" << std::endl;
}

void ProgressPage::handleStopButtonClicked() {
	Log("stopButton clicked");
	emit stopRequest();
	bar->reset();
}

void ProgressPage::handleGoButtonClicked() {
	Log("goButton clicked");
	emit goRequest();
}


QPushButton* ProgressPage::getStopButton() {
    return stopButton;
}

QPushButton * ProgressPage::getGoButton() {
	return goButton;
}