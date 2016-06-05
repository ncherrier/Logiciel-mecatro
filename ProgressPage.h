// Page pour montrer l'avancement (photos prises/photos restantes)

#ifndef PROGRESSPAGE_H
#define PROGRESSPAGE_H

#include <QWizardPage>
#include <QLabel>
#include <QProgressBar>
#include <QGridLayout>
#include <QPushButton>

class ProgressPage :  public QWizardPage
{

    Q_OBJECT

private:
    QProgressBar * bar;
    QPushButton * stopButton;

public slots:
    void incNbPicturesTaken();
    //void onStopButtonClicked();

public:
    ProgressPage();
    QPushButton* getStopButton();

//signals:
    //stopButtonClicked();

};

#endif // PROGRESSPAGE_H
