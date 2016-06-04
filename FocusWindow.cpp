/*
#include <QtWidgets/QApplication>
#include <QGridLayout>
#include "FocusWindow.h"
#include "AsynchronousGrab.h"
#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>



// Slot
void FocusWindow::OnImageReceived(QImage* image) {
	Log("OnImageReceived called");
	label->setPixmap(QPixmap::fromImage(*image).scaled(label->size(), Qt::KeepAspectRatio));
	Log("Image actualisee !");
}

void FocusWindow::SaveImage(){
	Log("SaveImage called");
	sync->OnBnClickedButtonStartstop();
	QImage img = sync->m_Image;
	nb_photos++;
	Log("Saving image");
	QString imgpath = dirpath + "/photo" + QString::number(nb_photos) + ".PNG";
	//QString imgpath = "photo.png";
	Log(imgpath.toStdString());
	bool res = img.save(imgpath);
	if (res) {
		Log("Sauvegarde reussie");
	}
	else{
		Log("Sauvegarde echouee");
	}
	Log("Reprise du flux video");
	sync->OnBnClickedButtonStartstop();
}


// Default Constructor
FocusWindow::FocusWindow()
{
	setFixedSize(533,400);
	setWindowTitle("Apercu du capteur");
	label = new QLabel;
	sync = new AsynchronousGrab();
	Log("Sync object created");
	QObject::connect(sync, SIGNAL(ImageReceivedSignal(QImage*)), this, SLOT(OnImageReceived(QImage*)));

	label->setFixedHeight(400);
	label->setFixedWidth(533);
	label->setVisible(true);

	// Prepare for saving
	nb_photos = 0;

	sync->OnBnClickedButtonStartstop();
	dirpath = QFileDialog::getExistingDirectory(this, tr("Open Directory"), "C:/", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

	Log("SaveImage called");
	sync->OnBnClickedButtonStartstop();
	QImage img = sync->m_Image;
	nb_photos++;
	Log("Saving image");
	QString imgpath = dirpath + "/photo" + QString::number(nb_photos) + ".PNG";
	//QString imgpath = "photo.png";
	Log(imgpath.toStdString());
	bool res = img.save(imgpath);
	if (res) {
		Log("Sauvegarde reussie");
	}
	else{
		Log("Sauvegarde echouee");
	}
	Log("Reprise du flux video");
	sync->OnBnClickedButtonStartstop();
}

// Default destructor
FocusWindow::~FocusWindow() {
	sync->OnBnClickedButtonStartstop(); // close camera
}

void FocusWindow::Log(std::string strMsg)
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
