/********************************************************************************
** Form generated from reading UI file 'OpenByID.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENBYID_H
#define UI_OPENBYID_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OpenByIDDialog
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *LineEdit_ID;
    QComboBox *ComboBox_Access;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *OpenByIDDialog)
    {
        if (OpenByIDDialog->objectName().isEmpty())
            OpenByIDDialog->setObjectName(QStringLiteral("OpenByIDDialog"));
        OpenByIDDialog->resize(300, 96);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(OpenByIDDialog->sizePolicy().hasHeightForWidth());
        OpenByIDDialog->setSizePolicy(sizePolicy);
        OpenByIDDialog->setMinimumSize(QSize(296, 87));
        OpenByIDDialog->setMaximumSize(QSize(300, 96));
        OpenByIDDialog->setContextMenuPolicy(Qt::NoContextMenu);
        QIcon icon;
        icon.addFile(QStringLiteral(":/VimbaViewer/Images/stripes_256.png"), QSize(), QIcon::Normal, QIcon::Off);
        OpenByIDDialog->setWindowIcon(icon);
        OpenByIDDialog->setModal(false);
        layoutWidget = new QWidget(OpenByIDDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 281, 82));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        LineEdit_ID = new QLineEdit(layoutWidget);
        LineEdit_ID->setObjectName(QStringLiteral("LineEdit_ID"));

        gridLayout->addWidget(LineEdit_ID, 1, 0, 1, 1);

        ComboBox_Access = new QComboBox(layoutWidget);
        ComboBox_Access->setObjectName(QStringLiteral("ComboBox_Access"));
        ComboBox_Access->setMinimumSize(QSize(72, 0));
        ComboBox_Access->setMaximumSize(QSize(99999, 16777215));

        gridLayout->addWidget(ComboBox_Access, 1, 1, 1, 1);

        buttonBox = new QDialogButtonBox(layoutWidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 2);


        retranslateUi(OpenByIDDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), OpenByIDDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), OpenByIDDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(OpenByIDDialog);
    } // setupUi

    void retranslateUi(QDialog *OpenByIDDialog)
    {
        OpenByIDDialog->setWindowTitle(QApplication::translate("OpenByIDDialog", "Open camera by IP", 0));
        label->setText(QApplication::translate("OpenByIDDialog", "IP address:", 0));
        label_2->setText(QApplication::translate("OpenByIDDialog", "Access:", 0));
#ifndef QT_NO_TOOLTIP
        LineEdit_ID->setToolTip(QApplication::translate("OpenByIDDialog", "Enter the ID of the camera as shown by Vimba, the IP or 12 digit MAC address", 0));
#endif // QT_NO_TOOLTIP
        ComboBox_Access->clear();
        ComboBox_Access->insertItems(0, QStringList()
         << QApplication::translate("OpenByIDDialog", "Open FULL ACCESS", 0)
         << QApplication::translate("OpenByIDDialog", "Open READ ONLY", 0)
         << QApplication::translate("OpenByIDDialog", "Open CONFIG", 0)
        );
#ifndef QT_NO_TOOLTIP
        ComboBox_Access->setToolTip(QApplication::translate("OpenByIDDialog", "Select the access mode the camera shall be opened in. Only GigE cameras can be opened in Config Mode.", 0));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class OpenByIDDialog: public Ui_OpenByIDDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENBYID_H
