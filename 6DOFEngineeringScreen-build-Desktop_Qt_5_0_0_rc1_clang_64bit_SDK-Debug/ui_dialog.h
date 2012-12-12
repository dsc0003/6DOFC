/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created: Tue Dec 11 22:40:48 2012
**      by: Qt User Interface Compiler version 5.0.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout;
    QGraphicsView *DataGraphicsView;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout;
    QLabel *R1Label;
    QLabel *R2Label;
    QLabel *R3Label;
    QLabel *R0Label;
    QLineEdit *R0LineEdit;
    QLineEdit *R1LineEdit;
    QLineEdit *R3LineEdit;
    QLineEdit *R2LineEdit;
    QGridLayout *gridLayout_2;
    QLabel *XLabel;
    QLabel *YLabel;
    QLabel *ZLabel;
    QLineEdit *XLineEdit;
    QLineEdit *ZLineEdit;
    QLineEdit *YLineEdit;
    QGridLayout *gridLayout_3;
    QLabel *YawLabel;
    QLabel *PitchLabel;
    QLabel *RollLabel;
    QLineEdit *YawLineEdit;
    QLineEdit *PitchLineEdit;
    QLineEdit *RollLineEdit;
    QGridLayout *gridLayout_4;
    QLabel *TimeLabel;
    QLineEdit *TimeLineEdit;
    QPushButton *pauseButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(649, 556);
        verticalLayout = new QVBoxLayout(Dialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        DataGraphicsView = new QGraphicsView(Dialog);
        DataGraphicsView->setObjectName(QStringLiteral("DataGraphicsView"));

        verticalLayout->addWidget(DataGraphicsView);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        R1Label = new QLabel(Dialog);
        R1Label->setObjectName(QStringLiteral("R1Label"));

        gridLayout->addWidget(R1Label, 1, 0, 1, 1);

        R2Label = new QLabel(Dialog);
        R2Label->setObjectName(QStringLiteral("R2Label"));

        gridLayout->addWidget(R2Label, 2, 0, 1, 1);

        R3Label = new QLabel(Dialog);
        R3Label->setObjectName(QStringLiteral("R3Label"));

        gridLayout->addWidget(R3Label, 3, 0, 1, 1);

        R0Label = new QLabel(Dialog);
        R0Label->setObjectName(QStringLiteral("R0Label"));

        gridLayout->addWidget(R0Label, 0, 0, 1, 1);

        R0LineEdit = new QLineEdit(Dialog);
        R0LineEdit->setObjectName(QStringLiteral("R0LineEdit"));

        gridLayout->addWidget(R0LineEdit, 0, 1, 1, 1);

        R1LineEdit = new QLineEdit(Dialog);
        R1LineEdit->setObjectName(QStringLiteral("R1LineEdit"));

        gridLayout->addWidget(R1LineEdit, 1, 1, 1, 1);

        R3LineEdit = new QLineEdit(Dialog);
        R3LineEdit->setObjectName(QStringLiteral("R3LineEdit"));

        gridLayout->addWidget(R3LineEdit, 3, 1, 1, 1);

        R2LineEdit = new QLineEdit(Dialog);
        R2LineEdit->setObjectName(QStringLiteral("R2LineEdit"));

        gridLayout->addWidget(R2LineEdit, 2, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        XLabel = new QLabel(Dialog);
        XLabel->setObjectName(QStringLiteral("XLabel"));

        gridLayout_2->addWidget(XLabel, 0, 0, 1, 1);

        YLabel = new QLabel(Dialog);
        YLabel->setObjectName(QStringLiteral("YLabel"));

        gridLayout_2->addWidget(YLabel, 1, 0, 1, 1);

        ZLabel = new QLabel(Dialog);
        ZLabel->setObjectName(QStringLiteral("ZLabel"));

        gridLayout_2->addWidget(ZLabel, 2, 0, 1, 1);

        XLineEdit = new QLineEdit(Dialog);
        XLineEdit->setObjectName(QStringLiteral("XLineEdit"));

        gridLayout_2->addWidget(XLineEdit, 0, 1, 1, 1);

        ZLineEdit = new QLineEdit(Dialog);
        ZLineEdit->setObjectName(QStringLiteral("ZLineEdit"));

        gridLayout_2->addWidget(ZLineEdit, 2, 1, 1, 1);

        YLineEdit = new QLineEdit(Dialog);
        YLineEdit->setObjectName(QStringLiteral("YLineEdit"));

        gridLayout_2->addWidget(YLineEdit, 1, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout_2, 0, 1, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        YawLabel = new QLabel(Dialog);
        YawLabel->setObjectName(QStringLiteral("YawLabel"));

        gridLayout_3->addWidget(YawLabel, 0, 0, 1, 1);

        PitchLabel = new QLabel(Dialog);
        PitchLabel->setObjectName(QStringLiteral("PitchLabel"));

        gridLayout_3->addWidget(PitchLabel, 1, 0, 1, 1);

        RollLabel = new QLabel(Dialog);
        RollLabel->setObjectName(QStringLiteral("RollLabel"));

        gridLayout_3->addWidget(RollLabel, 2, 0, 1, 1);

        YawLineEdit = new QLineEdit(Dialog);
        YawLineEdit->setObjectName(QStringLiteral("YawLineEdit"));

        gridLayout_3->addWidget(YawLineEdit, 0, 1, 1, 1);

        PitchLineEdit = new QLineEdit(Dialog);
        PitchLineEdit->setObjectName(QStringLiteral("PitchLineEdit"));

        gridLayout_3->addWidget(PitchLineEdit, 1, 1, 1, 1);

        RollLineEdit = new QLineEdit(Dialog);
        RollLineEdit->setObjectName(QStringLiteral("RollLineEdit"));

        gridLayout_3->addWidget(RollLineEdit, 2, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout_3, 0, 2, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        TimeLabel = new QLabel(Dialog);
        TimeLabel->setObjectName(QStringLiteral("TimeLabel"));

        gridLayout_4->addWidget(TimeLabel, 0, 0, 1, 1);

        TimeLineEdit = new QLineEdit(Dialog);
        TimeLineEdit->setObjectName(QStringLiteral("TimeLineEdit"));

        gridLayout_4->addWidget(TimeLineEdit, 0, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout_4, 1, 0, 1, 1);

        pauseButton = new QPushButton(Dialog);
        pauseButton->setObjectName(QStringLiteral("pauseButton"));

        gridLayout_5->addWidget(pauseButton, 1, 2, 1, 1);


        verticalLayout->addLayout(gridLayout_5);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0));
        R1Label->setText(QApplication::translate("Dialog", "R1", 0));
        R2Label->setText(QApplication::translate("Dialog", "R2", 0));
        R3Label->setText(QApplication::translate("Dialog", "R3", 0));
        R0Label->setText(QApplication::translate("Dialog", "R0", 0));
        XLabel->setText(QApplication::translate("Dialog", "X", 0));
        YLabel->setText(QApplication::translate("Dialog", "Y", 0));
        ZLabel->setText(QApplication::translate("Dialog", "Z", 0));
        YawLabel->setText(QApplication::translate("Dialog", "Yaw", 0));
        PitchLabel->setText(QApplication::translate("Dialog", "Pitch", 0));
        RollLabel->setText(QApplication::translate("Dialog", "Roll", 0));
        TimeLabel->setText(QApplication::translate("Dialog", "Time", 0));
        pauseButton->setText(QApplication::translate("Dialog", "Start", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
