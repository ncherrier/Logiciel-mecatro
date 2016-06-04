
#include <iostream> // TODO: remove after tests
#include <QtWidgets/QApplication>
#include <QPushButton>
#include <QGridLayout>
#include "TakePictureTest.h"
#include "AsynchronousGrab.h"
#include <QObject>
#include <QFile>
#include <QTextStream>


using namespace std;

// Slot
void TakePictureTest::OnImageReceived(QImage* image) {
	Log("OnImageReceived called");
	label->setPixmap(QPixmap::fromImage(*image).scaled(label->size(), Qt::KeepAspectRatio));
	Log("Image actualisée !");
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
	Log("Sync object created");
	QObject::connect(sync, SIGNAL(ImageReceivedSignal(QImage*)), this, SLOT(OnImageReceived(QImage*)));
	QImage *imagetest = new QImage();
	label = new QLabel;
	label->setFixedWidth(400);
	label->setFixedHeight(400);
	Log("Label created");
	QObject::connect(goButton, SIGNAL(clicked()), sync, SLOT(OnBnClickedButtonStartstop()));
	Log("Button connected");
	sync->OnBnClickedButtonStartstop();
	Log("Sync connected with label");
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
