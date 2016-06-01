
#include <iostream> // TODO: remove after tests
#include <QtWidgets/QApplication>
#include <QPushButton>
#include <QGridLayout>
#include "TakePictureTest.h"
#include "AsynchronousGrab.h"
//#include <QObject>


using namespace std;

// Slot
void TakePictureTest::OnImageReceived(QImage image) {
	label->setPixmap(QPixmap::fromImage(image).scaled(label->size(), Qt::KeepAspectRatio));
}

// Default Constructor
TakePictureTest::TakePictureTest()
{
	// Set size and title

	setFixedSize(800,400);
	setWindowTitle("Test : take picture");

	// Button

	goButton = new QPushButton("GO !!");

	sync = new AsynchronousGrab();
	QImage *imagetest = new QImage();
	label = new QLabel;
	label->setFixedWidth(400);
	label->setFixedHeight(400);
	QObject::connect(goButton, SIGNAL(clicked()), sync, SLOT(OnBnClickedButtonStartstop()));
	QObject::connect(sync, SIGNAL(ImageReceivedSignal(imagetest)), this, SLOT(OnImageReceived(*imagetest)));
	label->setVisible(true);

	// Layout
	QGridLayout *layout = new QGridLayout;
	layout->addWidget(goButton, 1, 1);
	layout->addWidget(label,0,1);
	setLayout(layout);

}

// Default destructor
TakePictureTest::~TakePictureTest() {
// What TODO ?
}

