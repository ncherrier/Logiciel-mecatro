
#include <QtWidgets/QApplication>
#include <QGridLayout>
#include "FocusWindow.h"
#include "AsynchronousGrab.h"
#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include "Bitmap.h"
#include <QBuffer>


// Slot
void FocusWindow::OnImageReceived(QImage* image) {
	Log("OnImageReceived called");
	label->setPixmap(QPixmap::fromImage(*image).scaled(label->size(), Qt::KeepAspectRatio));
	m_img = image;
	Log("Image actualisee !");
}

void FocusWindow::SaveImage(){
	Log("SaveImage called");
	if (sync->m_bIsStreaming){
		sync->OnBnClickedButtonStartstop();
		
		//AVTBitmap bitmap = sync->bitmap;
		nb_photos++;
		Log("Saving image");
		//QString format = "png";
		QString imgpath = dirpath + "/photo" + QString::number(nb_photos) + ".png";
		//QString imgpath = "test.png";
		Log(imgpath.toStdString());
		
		QPixmap pixmap = QPixmap::fromImage(*m_img);
		QSize bla = pixmap.size();
		Log(std::to_string(bla.height()));
		Log(std::to_string(bla.width()));
		//QByteArray bytes;
		//QBuffer buffer(&bytes);
		//buffer.open(QIODevice::WriteOnly);
		//bool res = pixmap.save(&buffer, "PNG");
		bool res = pixmap.save(imgpath, "PNG");
		//bool res = img.save(imgpath);
		//unsigned char res = AVTWriteBitmapToFile(&bitmap, imgpath.toStdString().c_str());
		if (res) {
			Log("Sauvegarde reussie");
			emit PictureTaken();
		}
		else{
			Log("Sauvegarde echouee");
		}
		Log("Reprise du flux video");
		sync->OnBnClickedButtonStartstop();
	}
}


// Default Constructor
FocusWindow::FocusWindow()
{
	setFixedSize(533,400);
	setWindowTitle("Apercu du capteur");
	label = new QLabel;
	m_img = new QImage;
	sync = new AsynchronousGrab();
	Log("Sync object created");
	QObject::connect(sync, SIGNAL(ImageReceivedSignal(QImage*)), this, SLOT(OnImageReceived(QImage*)));

	label->setFixedHeight(400);
	label->setFixedWidth(533);
	label->setVisible(true);

	// Prepare for saving
	nb_photos = 0;
	dirpath = QFileDialog::getExistingDirectory(this, tr("Open Directory"), "C:/", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

	sync->OnBnClickedButtonStartstop();

}

// Default destructor
FocusWindow::~FocusWindow() {
	if (sync->m_bIsStreaming){
		sync->OnBnClickedButtonStartstop(); // close camera
	}
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
