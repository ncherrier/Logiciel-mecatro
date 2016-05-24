/********************************************************************************
** Form generated from reading UI file 'SavingProgress.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVINGPROGRESS_H
#define UI_SAVINGPROGRESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QProgressBar>

QT_BEGIN_NAMESPACE

class Ui_SaveImagesProgressDialog
{
public:
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QProgressBar *saveImagesProgress;

    void setupUi(QDialog *SaveImagesProgressDialog)
    {
        if (SaveImagesProgressDialog->objectName().isEmpty())
            SaveImagesProgressDialog->setObjectName(QStringLiteral("SaveImagesProgressDialog"));
        SaveImagesProgressDialog->setWindowModality(Qt::ApplicationModal);
        SaveImagesProgressDialog->resize(420, 45);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SaveImagesProgressDialog->sizePolicy().hasHeightForWidth());
        SaveImagesProgressDialog->setSizePolicy(sizePolicy);
        SaveImagesProgressDialog->setMinimumSize(QSize(420, 41));
        SaveImagesProgressDialog->setMaximumSize(QSize(420, 48));
        SaveImagesProgressDialog->setModal(true);
        horizontalLayout_2 = new QHBoxLayout(SaveImagesProgressDialog);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        saveImagesProgress = new QProgressBar(SaveImagesProgressDialog);
        saveImagesProgress->setObjectName(QStringLiteral("saveImagesProgress"));
        saveImagesProgress->setValue(24);

        horizontalLayout->addWidget(saveImagesProgress);


        horizontalLayout_2->addLayout(horizontalLayout);


        retranslateUi(SaveImagesProgressDialog);

        QMetaObject::connectSlotsByName(SaveImagesProgressDialog);
    } // setupUi

    void retranslateUi(QDialog *SaveImagesProgressDialog)
    {
        SaveImagesProgressDialog->setWindowTitle(QApplication::translate("SaveImagesProgressDialog", "Saving Progress", 0));
    } // retranslateUi

};

namespace Ui {
    class SaveImagesProgressDialog: public Ui_SaveImagesProgressDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVINGPROGRESS_H
