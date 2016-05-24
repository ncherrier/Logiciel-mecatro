/********************************************************************************
** Form generated from reading UI file 'DirectAccess.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIRECTACCESS_H
#define UI_DIRECTACCESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DirectAccessDialog
{
public:
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLabel *RegAccessError_Label;
    QGridLayout *gridLayout;
    QLabel *RegAdd_Label;
    QLabel *RegAddEditPrefix_Label;
    QLabel *RegData_Label;
    QLabel *RegDataEditPrefix_Label;
    QLineEdit *RegData_Edit;
    QLabel *RegDataDec_Label;
    QLabel *RegDataDecEditPrefix_Label;
    QLineEdit *RegDataDec_Edit;
    QCheckBox *CheckBoxEndianess;
    QLineEdit *RegAdd_Edit;
    QHBoxLayout *horizontalLayout;
    QPushButton *RegRead_Button;
    QPushButton *RegWrite_Button;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *DirectAccessDialog)
    {
        if (DirectAccessDialog->objectName().isEmpty())
            DirectAccessDialog->setObjectName(QStringLiteral("DirectAccessDialog"));
        DirectAccessDialog->resize(439, 160);
        DirectAccessDialog->setMinimumSize(QSize(400, 160));
        DirectAccessDialog->setMaximumSize(QSize(500, 160));
        layoutWidget = new QWidget(DirectAccessDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(9, 10, 421, 144));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setContentsMargins(0, 0, 0, 0);
        RegAccessError_Label = new QLabel(layoutWidget);
        RegAccessError_Label->setObjectName(QStringLiteral("RegAccessError_Label"));

        formLayout->setWidget(1, QFormLayout::SpanningRole, RegAccessError_Label);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        RegAdd_Label = new QLabel(layoutWidget);
        RegAdd_Label->setObjectName(QStringLiteral("RegAdd_Label"));

        gridLayout->addWidget(RegAdd_Label, 0, 1, 1, 1);

        RegAddEditPrefix_Label = new QLabel(layoutWidget);
        RegAddEditPrefix_Label->setObjectName(QStringLiteral("RegAddEditPrefix_Label"));
        RegAddEditPrefix_Label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(RegAddEditPrefix_Label, 0, 2, 1, 1);

        RegData_Label = new QLabel(layoutWidget);
        RegData_Label->setObjectName(QStringLiteral("RegData_Label"));
        RegData_Label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(RegData_Label, 1, 1, 1, 1);

        RegDataEditPrefix_Label = new QLabel(layoutWidget);
        RegDataEditPrefix_Label->setObjectName(QStringLiteral("RegDataEditPrefix_Label"));
        RegDataEditPrefix_Label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(RegDataEditPrefix_Label, 1, 2, 1, 1);

        RegData_Edit = new QLineEdit(layoutWidget);
        RegData_Edit->setObjectName(QStringLiteral("RegData_Edit"));

        gridLayout->addWidget(RegData_Edit, 1, 4, 1, 1);

        RegDataDec_Label = new QLabel(layoutWidget);
        RegDataDec_Label->setObjectName(QStringLiteral("RegDataDec_Label"));

        gridLayout->addWidget(RegDataDec_Label, 2, 1, 1, 1);

        RegDataDecEditPrefix_Label = new QLabel(layoutWidget);
        RegDataDecEditPrefix_Label->setObjectName(QStringLiteral("RegDataDecEditPrefix_Label"));
        RegDataDecEditPrefix_Label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(RegDataDecEditPrefix_Label, 2, 2, 1, 1);

        RegDataDec_Edit = new QLineEdit(layoutWidget);
        RegDataDec_Edit->setObjectName(QStringLiteral("RegDataDec_Edit"));

        gridLayout->addWidget(RegDataDec_Edit, 2, 4, 1, 1);

        CheckBoxEndianess = new QCheckBox(layoutWidget);
        CheckBoxEndianess->setObjectName(QStringLiteral("CheckBoxEndianess"));

        gridLayout->addWidget(CheckBoxEndianess, 2, 5, 1, 1);

        RegAdd_Edit = new QLineEdit(layoutWidget);
        RegAdd_Edit->setObjectName(QStringLiteral("RegAdd_Edit"));

        gridLayout->addWidget(RegAdd_Edit, 0, 4, 1, 1);


        formLayout->setLayout(0, QFormLayout::LabelRole, gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        RegRead_Button = new QPushButton(layoutWidget);
        RegRead_Button->setObjectName(QStringLiteral("RegRead_Button"));

        horizontalLayout->addWidget(RegRead_Button);

        RegWrite_Button = new QPushButton(layoutWidget);
        RegWrite_Button->setObjectName(QStringLiteral("RegWrite_Button"));

        horizontalLayout->addWidget(RegWrite_Button);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        formLayout->setLayout(2, QFormLayout::LabelRole, horizontalLayout);


        retranslateUi(DirectAccessDialog);

        QMetaObject::connectSlotsByName(DirectAccessDialog);
    } // setupUi

    void retranslateUi(QDialog *DirectAccessDialog)
    {
        DirectAccessDialog->setWindowTitle(QApplication::translate("DirectAccessDialog", "Direct Access", 0));
        RegAccessError_Label->setText(QString());
        RegAdd_Label->setText(QApplication::translate("DirectAccessDialog", "Register Address:", 0));
        RegAddEditPrefix_Label->setText(QApplication::translate("DirectAccessDialog", "0x", 0));
        RegData_Label->setText(QApplication::translate("DirectAccessDialog", "Data:", 0));
        RegDataEditPrefix_Label->setText(QApplication::translate("DirectAccessDialog", "0x", 0));
#ifndef QT_NO_TOOLTIP
        RegData_Edit->setToolTip(QApplication::translate("DirectAccessDialog", "The register content shown in endianess of the device", 0));
#endif // QT_NO_TOOLTIP
        RegDataDec_Label->setText(QApplication::translate("DirectAccessDialog", "Data:", 0));
        RegDataDecEditPrefix_Label->setText(QApplication::translate("DirectAccessDialog", "Dec", 0));
#ifndef QT_NO_TOOLTIP
        RegDataDec_Edit->setToolTip(QApplication::translate("DirectAccessDialog", "The decimal representation of the register content", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        CheckBoxEndianess->setToolTip(QApplication::translate("DirectAccessDialog", "Convert the decimal value to little endian", 0));
#endif // QT_NO_TOOLTIP
        CheckBoxEndianess->setText(QApplication::translate("DirectAccessDialog", "Little endian device", 0));
#ifndef QT_NO_TOOLTIP
        RegAdd_Edit->setToolTip(QApplication::translate("DirectAccessDialog", "The register address", 0));
#endif // QT_NO_TOOLTIP
        RegRead_Button->setText(QApplication::translate("DirectAccessDialog", "READ", 0));
        RegWrite_Button->setText(QApplication::translate("DirectAccessDialog", "WRITE", 0));
    } // retranslateUi

};

namespace Ui {
    class DirectAccessDialog: public Ui_DirectAccessDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIRECTACCESS_H
