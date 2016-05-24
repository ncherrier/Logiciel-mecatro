/********************************************************************************
** Form generated from reading UI file 'OptionDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONDIALOG_H
#define UI_OPTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
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

class Ui_OptionDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *gbFlags;
    QGridLayout *gridLayout_2;
    QCheckBox *cbReadOnly;
    QCheckBox *cbHighlighting;
    QCheckBox *cbOverwriteMode;
    QCheckBox *cbAddressArea;
    QCheckBox *cbAsciiArea;
    QGroupBox *gbColors;
    QGridLayout *gridLayout;
    QPushButton *pbHighlightingColor;
    QLabel *lbHighlightingColor;
    QPushButton *pbAddressAreaColor;
    QLabel *lbAddressAreaColor;
    QLabel *lbSelectionColor;
    QPushButton *pbSelectionColor;
    QPushButton *pbWidgetFont;
    QLineEdit *leWidgetFont;
    QGroupBox *gbAddressAreaWidth;
    QGridLayout *gridLayout_3;
    QLabel *lbAddressAreaWidth;
    QSpinBox *sbAddressAreaWidth;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *OptionDialog)
    {
        if (OptionDialog->objectName().isEmpty())
            OptionDialog->setObjectName(QStringLiteral("OptionDialog"));
        OptionDialog->resize(395, 427);
        verticalLayout = new QVBoxLayout(OptionDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gbFlags = new QGroupBox(OptionDialog);
        gbFlags->setObjectName(QStringLiteral("gbFlags"));
        gridLayout_2 = new QGridLayout(gbFlags);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        cbReadOnly = new QCheckBox(gbFlags);
        cbReadOnly->setObjectName(QStringLiteral("cbReadOnly"));

        gridLayout_2->addWidget(cbReadOnly, 3, 0, 1, 1);

        cbHighlighting = new QCheckBox(gbFlags);
        cbHighlighting->setObjectName(QStringLiteral("cbHighlighting"));

        gridLayout_2->addWidget(cbHighlighting, 2, 0, 1, 1);

        cbOverwriteMode = new QCheckBox(gbFlags);
        cbOverwriteMode->setObjectName(QStringLiteral("cbOverwriteMode"));

        gridLayout_2->addWidget(cbOverwriteMode, 1, 0, 1, 1);

        cbAddressArea = new QCheckBox(gbFlags);
        cbAddressArea->setObjectName(QStringLiteral("cbAddressArea"));

        gridLayout_2->addWidget(cbAddressArea, 1, 1, 1, 1);

        cbAsciiArea = new QCheckBox(gbFlags);
        cbAsciiArea->setObjectName(QStringLiteral("cbAsciiArea"));

        gridLayout_2->addWidget(cbAsciiArea, 2, 1, 1, 1);


        verticalLayout->addWidget(gbFlags);

        gbColors = new QGroupBox(OptionDialog);
        gbColors->setObjectName(QStringLiteral("gbColors"));
        gridLayout = new QGridLayout(gbColors);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pbHighlightingColor = new QPushButton(gbColors);
        pbHighlightingColor->setObjectName(QStringLiteral("pbHighlightingColor"));

        gridLayout->addWidget(pbHighlightingColor, 0, 0, 1, 1);

        lbHighlightingColor = new QLabel(gbColors);
        lbHighlightingColor->setObjectName(QStringLiteral("lbHighlightingColor"));
        lbHighlightingColor->setMinimumSize(QSize(100, 0));
        lbHighlightingColor->setMaximumSize(QSize(16777215, 16777215));
        lbHighlightingColor->setFrameShape(QFrame::Panel);
        lbHighlightingColor->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(lbHighlightingColor, 0, 1, 1, 1);

        pbAddressAreaColor = new QPushButton(gbColors);
        pbAddressAreaColor->setObjectName(QStringLiteral("pbAddressAreaColor"));

        gridLayout->addWidget(pbAddressAreaColor, 1, 0, 2, 1);

        lbAddressAreaColor = new QLabel(gbColors);
        lbAddressAreaColor->setObjectName(QStringLiteral("lbAddressAreaColor"));
        lbAddressAreaColor->setMinimumSize(QSize(100, 0));
        lbAddressAreaColor->setMaximumSize(QSize(16777215, 16777215));
        lbAddressAreaColor->setFrameShape(QFrame::Panel);
        lbAddressAreaColor->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(lbAddressAreaColor, 1, 1, 2, 1);

        lbSelectionColor = new QLabel(gbColors);
        lbSelectionColor->setObjectName(QStringLiteral("lbSelectionColor"));
        lbSelectionColor->setMinimumSize(QSize(100, 0));
        lbSelectionColor->setMaximumSize(QSize(16777215, 16777215));
        lbSelectionColor->setFrameShape(QFrame::Panel);
        lbSelectionColor->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(lbSelectionColor, 3, 1, 1, 1);

        pbSelectionColor = new QPushButton(gbColors);
        pbSelectionColor->setObjectName(QStringLiteral("pbSelectionColor"));

        gridLayout->addWidget(pbSelectionColor, 3, 0, 1, 1);

        pbWidgetFont = new QPushButton(gbColors);
        pbWidgetFont->setObjectName(QStringLiteral("pbWidgetFont"));

        gridLayout->addWidget(pbWidgetFont, 4, 0, 1, 1);

        leWidgetFont = new QLineEdit(gbColors);
        leWidgetFont->setObjectName(QStringLiteral("leWidgetFont"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(leWidgetFont->sizePolicy().hasHeightForWidth());
        leWidgetFont->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QStringLiteral("Courier New"));
        font.setPointSize(10);
        leWidgetFont->setFont(font);

        gridLayout->addWidget(leWidgetFont, 4, 1, 1, 1);


        verticalLayout->addWidget(gbColors);

        gbAddressAreaWidth = new QGroupBox(OptionDialog);
        gbAddressAreaWidth->setObjectName(QStringLiteral("gbAddressAreaWidth"));
        gridLayout_3 = new QGridLayout(gbAddressAreaWidth);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        lbAddressAreaWidth = new QLabel(gbAddressAreaWidth);
        lbAddressAreaWidth->setObjectName(QStringLiteral("lbAddressAreaWidth"));

        gridLayout_3->addWidget(lbAddressAreaWidth, 0, 0, 1, 1);

        sbAddressAreaWidth = new QSpinBox(gbAddressAreaWidth);
        sbAddressAreaWidth->setObjectName(QStringLiteral("sbAddressAreaWidth"));
        sbAddressAreaWidth->setMinimum(1);
        sbAddressAreaWidth->setMaximum(4);
        sbAddressAreaWidth->setValue(4);

        gridLayout_3->addWidget(sbAddressAreaWidth, 0, 1, 1, 1);


        verticalLayout->addWidget(gbAddressAreaWidth);

        verticalSpacer = new QSpacerItem(20, 28, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(OptionDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

        QWidget::setTabOrder(pbHighlightingColor, pbAddressAreaColor);
        QWidget::setTabOrder(pbAddressAreaColor, buttonBox);

        retranslateUi(OptionDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), OptionDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), OptionDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(OptionDialog);
    } // setupUi

    void retranslateUi(QDialog *OptionDialog)
    {
        OptionDialog->setWindowTitle(QApplication::translate("OptionDialog", "Settings", 0));
        gbFlags->setTitle(QApplication::translate("OptionDialog", "Flags", 0));
        cbReadOnly->setText(QApplication::translate("OptionDialog", "ReadOnly", 0));
        cbHighlighting->setText(QApplication::translate("OptionDialog", "Highlighting", 0));
        cbOverwriteMode->setText(QApplication::translate("OptionDialog", "Overwrite Mode", 0));
        cbAddressArea->setText(QApplication::translate("OptionDialog", "Address Area", 0));
        cbAsciiArea->setText(QApplication::translate("OptionDialog", "Ascii Area", 0));
        gbColors->setTitle(QApplication::translate("OptionDialog", "Colors and Fonts", 0));
        pbHighlightingColor->setText(QApplication::translate("OptionDialog", "Highlighting Color", 0));
        lbHighlightingColor->setText(QString());
        pbAddressAreaColor->setText(QApplication::translate("OptionDialog", "Address Area Color", 0));
        lbAddressAreaColor->setText(QString());
        lbSelectionColor->setText(QString());
        pbSelectionColor->setText(QApplication::translate("OptionDialog", "Selection Color", 0));
        pbWidgetFont->setText(QApplication::translate("OptionDialog", "Widget Font", 0));
        leWidgetFont->setText(QApplication::translate("OptionDialog", "01 23 45 67 89 ab cd ef", 0));
        gbAddressAreaWidth->setTitle(QApplication::translate("OptionDialog", "Address Area", 0));
        lbAddressAreaWidth->setText(QApplication::translate("OptionDialog", "Address Area Width", 0));
    } // retranslateUi

};

namespace Ui {
    class OptionDialog: public Ui_OptionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONDIALOG_H
