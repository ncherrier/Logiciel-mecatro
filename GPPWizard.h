// Wizard to use the GigaProxyPhoto system

#ifndef GPPWIZARD_H
#define GPPWIZARD_H

#include <QWidget>
#include <QWizard>

class GPPWizard : public QWizard
{
public:
    GPPWizard();

private:
    // functions to create the 4 pages of the wizard
    QWizardPage *createIntroPage();
    QWizardPage *createFramingPage();
    QWizardPage *createSettingsPage();
    QWizardPage *createInProcessPage();
};

#endif // GPPWIZARD_H
