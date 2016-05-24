/********************************************************************************
** Form generated from reading UI file 'StartOption.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTOPTION_H
#define UI_STARTOPTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_StartOptionsDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QCheckBox *AutoAdjustPacketSize_CheckBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *StartOptionsDialog)
    {
        if (StartOptionsDialog->objectName().isEmpty())
            StartOptionsDialog->setObjectName(QStringLiteral("StartOptionsDialog"));
        StartOptionsDialog->resize(274, 117);
        StartOptionsDialog->setMinimumSize(QSize(250, 100));
        StartOptionsDialog->setMaximumSize(QSize(290, 128));
        verticalLayout_2 = new QVBoxLayout(StartOptionsDialog);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(StartOptionsDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        AutoAdjustPacketSize_CheckBox = new QCheckBox(groupBox);
        AutoAdjustPacketSize_CheckBox->setObjectName(QStringLiteral("AutoAdjustPacketSize_CheckBox"));
        AutoAdjustPacketSize_CheckBox->setGeometry(QRect(10, 30, 231, 21));

        verticalLayout->addWidget(groupBox);


        verticalLayout_2->addLayout(verticalLayout);

        buttonBox = new QDialogButtonBox(StartOptionsDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(StartOptionsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), StartOptionsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), StartOptionsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(StartOptionsDialog);
    } // setupUi

    void retranslateUi(QDialog *StartOptionsDialog)
    {
        StartOptionsDialog->setWindowTitle(QApplication::translate("StartOptionsDialog", "Start Options", 0));
        groupBox->setTitle(QApplication::translate("StartOptionsDialog", "GigE: ", 0));
        AutoAdjustPacketSize_CheckBox->setText(QApplication::translate("StartOptionsDialog", "Auto Adjust Packet Size", 0));
    } // retranslateUi

};

namespace Ui {
    class StartOptionsDialog: public Ui_StartOptionsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTOPTION_H
