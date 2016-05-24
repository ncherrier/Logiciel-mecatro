/* Fenetre pour les reglages :
* Choix de l'emplacement de la mise au point,
* Retour video (camera indus.) pour la mise au point,
* Retour video (webcam) (pour situer l'endroit de la mise au point)
* Acces aux reglages de la camera indus. (et de la webcam ?),
* Acces au choix de dossier de destination.
* */

#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <vector>
#include <QPushButton>
#include <QWidget>

class SettingsWindow : public QWidget
{
	Q_OBJECT

public:
	SettingsWindow(); // default constructor
	//virtual ~SettingsWindow(); // default destructor - useless

	public slots:
	void goToFramingWindow();
	void openCameraSettings(); // open CameraSettingsWindow (settings for the industrial camera)

	void startCycle(); // to take the global picture

	// give instructions to move camera

	bool goUp();
	bool goDown();
	bool goLeft();
	bool goRight();

private:
	QPushButton *upButton;
	QPushButton *leftButton;
	QPushButton *downButton;
	QPushButton *rightButton;
	QPushButton *finishButton;
	QPushButton *previousButton;
	QPushButton *cameraSettingsButton;

	void goToProcessWindow();

};

#endif // SETTINGSWINDOW_H
