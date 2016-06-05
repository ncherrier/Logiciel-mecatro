/*
#include <iostream> // TODO: remove after tests
#include <QtWidgets/QApplication>
#include <QPushButton>
#include <QGridLayout>
#include "TakePictureTest.h"
#include <QObject>
#include <QFile>
#include <QTextStream>


using namespace std;

// Slot
void TakePictureTest::takePicture() {
	
}

// Default Constructor
TakePictureTest::TakePictureTest()
{
	// Set size and title

	setFixedSize(800,400);
	setWindowTitle("Test : take picture");

	// Button

	goButton = new QPushButton("GO !!");
	focus = new FocusWindow();
	connect(goButton, SIGNAL(clicked()), focus, SLOT(SaveImage()));
	

	// Layout
	QGridLayout *layout = new QGridLayout;
	layout->addWidget(goButton, 1, 1);
	setLayout(layout);

}

// Default destructor
TakePictureTest::~TakePictureTest() {
// What TODO ?
}

void TakePictureTest::Log(std::string strMsg)
{
	QString filename = "C:/Data.txt";
	QFile file(filename);
	if (file.open(QIODevice::ReadWrite | QIODevice::Append))
	{
		QTextStream stream(&file);
		stream << QString::fromUtf8(strMsg.c_str()) << endl;
	}
}

*/
