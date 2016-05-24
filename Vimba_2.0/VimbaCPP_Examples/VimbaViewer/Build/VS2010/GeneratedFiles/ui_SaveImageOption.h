/********************************************************************************
** Form generated from reading UI file 'SaveImageOption.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVEIMAGEOPTION_H
#define UI_SAVEIMAGEOPTION_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SavingOptionsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QGroupBox *SaveImageFileNameGroup;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_2;
    QLabel *ImageName;
    QLineEdit *ImageName_Edit;
    QPushButton *ImageDestinationButton;
    QLineEdit *ImageDestination_Edit;
    QLabel *ImageFormat;
    QComboBox *ImageFormat_ComboBox;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout_3;
    QLabel *NumberOfImages;
    QSpinBox *NumberOfFrames_SpinBox;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SavingOptionsDialog)
    {
        if (SavingOptionsDialog->objectName().isEmpty())
            SavingOptionsDialog->setObjectName(QStringLiteral("SavingOptionsDialog"));
        SavingOptionsDialog->resize(600, 258);
        SavingOptionsDialog->setMinimumSize(QSize(600, 258));
        SavingOptionsDialog->setMaximumSize(QSize(600, 258));
        verticalLayout = new QVBoxLayout(SavingOptionsDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        SaveImageFileNameGroup = new QGroupBox(SavingOptionsDialog);
        SaveImageFileNameGroup->setObjectName(QStringLiteral("SaveImageFileNameGroup"));
        verticalLayout_2 = new QVBoxLayout(SaveImageFileNameGroup);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        ImageName = new QLabel(SaveImageFileNameGroup);
        ImageName->setObjectName(QStringLiteral("ImageName"));

        gridLayout_2->addWidget(ImageName, 1, 0, 1, 1);

        ImageName_Edit = new QLineEdit(SaveImageFileNameGroup);
        ImageName_Edit->setObjectName(QStringLiteral("ImageName_Edit"));

        gridLayout_2->addWidget(ImageName_Edit, 1, 2, 1, 1);

        ImageDestinationButton = new QPushButton(SaveImageFileNameGroup);
        ImageDestinationButton->setObjectName(QStringLiteral("ImageDestinationButton"));

        gridLayout_2->addWidget(ImageDestinationButton, 2, 0, 1, 1);

        ImageDestination_Edit = new QLineEdit(SaveImageFileNameGroup);
        ImageDestination_Edit->setObjectName(QStringLiteral("ImageDestination_Edit"));

        gridLayout_2->addWidget(ImageDestination_Edit, 2, 2, 1, 1);

        ImageFormat = new QLabel(SaveImageFileNameGroup);
        ImageFormat->setObjectName(QStringLiteral("ImageFormat"));

        gridLayout_2->addWidget(ImageFormat, 0, 0, 1, 1);

        ImageFormat_ComboBox = new QComboBox(SaveImageFileNameGroup);
        ImageFormat_ComboBox->setObjectName(QStringLiteral("ImageFormat_ComboBox"));

        gridLayout_2->addWidget(ImageFormat_ComboBox, 0, 2, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);


        gridLayout->addWidget(SaveImageFileNameGroup, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(SavingOptionsDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        NumberOfImages = new QLabel(groupBox_2);
        NumberOfImages->setObjectName(QStringLiteral("NumberOfImages"));

        gridLayout_3->addWidget(NumberOfImages, 0, 0, 1, 1);

        NumberOfFrames_SpinBox = new QSpinBox(groupBox_2);
        NumberOfFrames_SpinBox->setObjectName(QStringLiteral("NumberOfFrames_SpinBox"));
        NumberOfFrames_SpinBox->setMaximum(1000000);

        gridLayout_3->addWidget(NumberOfFrames_SpinBox, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 2, 1, 1);


        verticalLayout_3->addLayout(gridLayout_3);


        gridLayout->addWidget(groupBox_2, 1, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        buttonBox = new QDialogButtonBox(SavingOptionsDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setLocale(QLocale(QLocale::C, QLocale::AnyCountry));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(SavingOptionsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), SavingOptionsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SavingOptionsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SavingOptionsDialog);
    } // setupUi

    void retranslateUi(QDialog *SavingOptionsDialog)
    {
        SavingOptionsDialog->setWindowTitle(QApplication::translate("SavingOptionsDialog", "Saving Options", 0));
        SaveImageFileNameGroup->setTitle(QApplication::translate("SavingOptionsDialog", "File options:", 0));
        ImageName->setText(QApplication::translate("SavingOptionsDialog", "Name:", 0));
        ImageName_Edit->setText(QApplication::translate("SavingOptionsDialog", "VimbaImage", 0));
        ImageDestinationButton->setText(QApplication::translate("SavingOptionsDialog", "Destination Path...", 0));
        ImageDestination_Edit->setText(QString());
        ImageFormat->setText(QApplication::translate("SavingOptionsDialog", "Format:", 0));
        groupBox_2->setTitle(QApplication::translate("SavingOptionsDialog", "Processing options:", 0));
        NumberOfImages->setText(QApplication::translate("SavingOptionsDialog", "Number Of Images   ", 0));
    } // retranslateUi

};

namespace Ui {
    class SavingOptionsDialog: public Ui_SavingOptionsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVEIMAGEOPTION_H
