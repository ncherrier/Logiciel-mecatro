/********************************************************************************
** Form generated from reading UI file 'ViewerOption.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWEROPTION_H
#define UI_VIEWEROPTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DisplayOptionsDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_Display;
    QCheckBox *DisplayInterval_CheckBox;
    QLabel *Note_Label;
    QLabel *label_FramesCount;
    QLineEdit *lineEdit_FramesCount;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DisplayOptionsDialog)
    {
        if (DisplayOptionsDialog->objectName().isEmpty())
            DisplayOptionsDialog->setObjectName(QStringLiteral("DisplayOptionsDialog"));
        DisplayOptionsDialog->resize(490, 193);
        DisplayOptionsDialog->setMinimumSize(QSize(430, 145));
        DisplayOptionsDialog->setMaximumSize(QSize(490, 400));
        verticalLayout_2 = new QVBoxLayout(DisplayOptionsDialog);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox_Display = new QGroupBox(DisplayOptionsDialog);
        groupBox_Display->setObjectName(QStringLiteral("groupBox_Display"));
        DisplayInterval_CheckBox = new QCheckBox(groupBox_Display);
        DisplayInterval_CheckBox->setObjectName(QStringLiteral("DisplayInterval_CheckBox"));
        DisplayInterval_CheckBox->setGeometry(QRect(10, 30, 451, 20));
        Note_Label = new QLabel(groupBox_Display);
        Note_Label->setObjectName(QStringLiteral("Note_Label"));
        Note_Label->setEnabled(false);
        Note_Label->setGeometry(QRect(30, 60, 431, 20));
        label_FramesCount = new QLabel(groupBox_Display);
        label_FramesCount->setObjectName(QStringLiteral("label_FramesCount"));
        label_FramesCount->setGeometry(QRect(10, 100, 181, 20));
        lineEdit_FramesCount = new QLineEdit(groupBox_Display);
        lineEdit_FramesCount->setObjectName(QStringLiteral("lineEdit_FramesCount"));
        lineEdit_FramesCount->setGeometry(QRect(190, 100, 91, 22));

        verticalLayout->addWidget(groupBox_Display);


        verticalLayout_2->addLayout(verticalLayout);

        buttonBox = new QDialogButtonBox(DisplayOptionsDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(DisplayOptionsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), DisplayOptionsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DisplayOptionsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(DisplayOptionsDialog);
    } // setupUi

    void retranslateUi(QDialog *DisplayOptionsDialog)
    {
        DisplayOptionsDialog->setWindowTitle(QApplication::translate("DisplayOptionsDialog", "Viewer Options", 0));
        groupBox_Display->setTitle(QApplication::translate("DisplayOptionsDialog", "Performance Settings: ", 0));
        DisplayInterval_CheckBox->setText(QApplication::translate("DisplayOptionsDialog", "Display every completed frame received by the application", 0));
        Note_Label->setText(QApplication::translate("DisplayOptionsDialog", "NOTE: Enabling will increase the CPU consumption of your system!", 0));
        label_FramesCount->setText(QApplication::translate("DisplayOptionsDialog", "Number of used frame buffers", 0));
    } // retranslateUi

};

namespace Ui {
    class DisplayOptionsDialog: public Ui_DisplayOptionsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWEROPTION_H
