//TODO: uncomment .ccp and .h - and solve bug.
//(usefull only if it's possible to set exposure time on Mako)

/*
#ifndef CAMERASETTINGSWINDOW_H
#define CAMERASETTINGSWINDOW_H



#include <QWidget>
#include <QApplication>
#include <QDialog>
#include <QPushButton>
#include <QSpinBox>

class CameraSettingsWindow : public QDialog
	// interet d'heriter de QDialog :
	// quand cette fenetre est affichee, l'autre devient inactive
	// (fenetre modale)
{

	Q_OBJECT

public:
	//CameraSettingsWindow();
	CameraSettingsWindow(QWidget*); // arg = parent widget

	public slots:
	void reset();
	void apply();
	//void cancel(); // utile ?
	void validate();

private:
	// Basics
	QPushButton* resetButton;
	QPushButton* applyButton;
	QPushButton* cancelButton;
	QPushButton* validateButton;

	// Settings
	// exposureTime
	QSpinBox* exposureTimeBox;

	// TODO:
	// pixelColorFilter // variables possibles : BayerRG BayerGB BayerGR BayerBG

};



#endif // CAMERASETTINGSWINDOW_H


*/
