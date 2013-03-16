/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "mainwidget.h"

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout;
    MainWidget *mainwidget;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout;
    QLabel *R3Label;
    QLabel *R1Label;
    QLabel *R2Label;
    QLineEdit *R2LineEdit;
    QLabel *R0Label;
    QLineEdit *R0LineEdit;
    QLineEdit *R1LineEdit;
    QLineEdit *R3LineEdit;
    QGridLayout *gridLayout_4;
    QLabel *TimeLabel;
    QLineEdit *TimeLineEdit;
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
    QPushButton *pauseButton;
    QWidget *tab_2;
    QGridLayout *gridLayout_9;
    QFrame *line_2;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_7;
    QLabel *label_6;
    QLabel *label_5;
    QLineEdit *le_radioPort;
    QLineEdit *le_usbPort;
    QGridLayout *gridLayout_10;
    QLineEdit *le_destNode;
    QLabel *label_9;
    QFrame *line_3;
    QFrame *line_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_6;
    QLabel *label;
    QLineEdit *le_ref1;
    QLabel *label_2;
    QLineEdit *le_ref2;
    QLabel *label_4;
    QLineEdit *le_ref3;
    QLabel *label_3;
    QLineEdit *le_ref4;
    QFrame *line;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_4;
    QRadioButton *rb_geom2d;
    QRadioButton *rb_nlls2d;
    QRadioButton *rb_nlls3d;
    QRadioButton *rb_kf2d;
    QRadioButton *rb_kf3d;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_8;
    QLabel *label_7;
    QLineEdit *le_numOfIter;
    QLabel *label_8;
    QLineEdit *le_E;
    QPushButton *pb_set;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(734, 531);
        verticalLayout_2 = new QVBoxLayout(Dialog);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        tabWidget = new QTabWidget(Dialog);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout = new QVBoxLayout(tab);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        mainwidget = new MainWidget(tab);
        mainwidget->setObjectName(QStringLiteral("mainwidget"));

        verticalLayout->addWidget(mainwidget);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        R3Label = new QLabel(tab);
        R3Label->setObjectName(QStringLiteral("R3Label"));

        gridLayout->addWidget(R3Label, 3, 0, 1, 1);

        R1Label = new QLabel(tab);
        R1Label->setObjectName(QStringLiteral("R1Label"));

        gridLayout->addWidget(R1Label, 1, 0, 1, 1);

        R2Label = new QLabel(tab);
        R2Label->setObjectName(QStringLiteral("R2Label"));

        gridLayout->addWidget(R2Label, 2, 0, 1, 1);

        R2LineEdit = new QLineEdit(tab);
        R2LineEdit->setObjectName(QStringLiteral("R2LineEdit"));

        gridLayout->addWidget(R2LineEdit, 2, 1, 1, 1);

        R0Label = new QLabel(tab);
        R0Label->setObjectName(QStringLiteral("R0Label"));

        gridLayout->addWidget(R0Label, 0, 0, 1, 1);

        R0LineEdit = new QLineEdit(tab);
        R0LineEdit->setObjectName(QStringLiteral("R0LineEdit"));

        gridLayout->addWidget(R0LineEdit, 0, 1, 1, 1);

        R1LineEdit = new QLineEdit(tab);
        R1LineEdit->setObjectName(QStringLiteral("R1LineEdit"));

        gridLayout->addWidget(R1LineEdit, 1, 1, 1, 1);

        R3LineEdit = new QLineEdit(tab);
        R3LineEdit->setObjectName(QStringLiteral("R3LineEdit"));

        gridLayout->addWidget(R3LineEdit, 3, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout, 0, 2, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        TimeLabel = new QLabel(tab);
        TimeLabel->setObjectName(QStringLiteral("TimeLabel"));

        gridLayout_4->addWidget(TimeLabel, 0, 0, 1, 1);

        TimeLineEdit = new QLineEdit(tab);
        TimeLineEdit->setObjectName(QStringLiteral("TimeLineEdit"));

        gridLayout_4->addWidget(TimeLineEdit, 0, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout_4, 1, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        XLabel = new QLabel(tab);
        XLabel->setObjectName(QStringLiteral("XLabel"));

        gridLayout_2->addWidget(XLabel, 0, 0, 1, 1);

        YLabel = new QLabel(tab);
        YLabel->setObjectName(QStringLiteral("YLabel"));

        gridLayout_2->addWidget(YLabel, 1, 0, 1, 1);

        ZLabel = new QLabel(tab);
        ZLabel->setObjectName(QStringLiteral("ZLabel"));

        gridLayout_2->addWidget(ZLabel, 2, 0, 1, 1);

        XLineEdit = new QLineEdit(tab);
        XLineEdit->setObjectName(QStringLiteral("XLineEdit"));

        gridLayout_2->addWidget(XLineEdit, 0, 1, 1, 1);

        ZLineEdit = new QLineEdit(tab);
        ZLineEdit->setObjectName(QStringLiteral("ZLineEdit"));

        gridLayout_2->addWidget(ZLineEdit, 2, 1, 1, 1);

        YLineEdit = new QLineEdit(tab);
        YLineEdit->setObjectName(QStringLiteral("YLineEdit"));

        gridLayout_2->addWidget(YLineEdit, 1, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout_2, 0, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        YawLabel = new QLabel(tab);
        YawLabel->setObjectName(QStringLiteral("YawLabel"));

        gridLayout_3->addWidget(YawLabel, 0, 0, 1, 1);

        PitchLabel = new QLabel(tab);
        PitchLabel->setObjectName(QStringLiteral("PitchLabel"));

        gridLayout_3->addWidget(PitchLabel, 1, 0, 1, 1);

        RollLabel = new QLabel(tab);
        RollLabel->setObjectName(QStringLiteral("RollLabel"));

        gridLayout_3->addWidget(RollLabel, 2, 0, 1, 1);

        YawLineEdit = new QLineEdit(tab);
        YawLineEdit->setObjectName(QStringLiteral("YawLineEdit"));

        gridLayout_3->addWidget(YawLineEdit, 0, 1, 1, 1);

        PitchLineEdit = new QLineEdit(tab);
        PitchLineEdit->setObjectName(QStringLiteral("PitchLineEdit"));

        gridLayout_3->addWidget(PitchLineEdit, 1, 1, 1, 1);

        RollLineEdit = new QLineEdit(tab);
        RollLineEdit->setObjectName(QStringLiteral("RollLineEdit"));

        gridLayout_3->addWidget(RollLineEdit, 2, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout_3, 0, 1, 1, 1);

        pauseButton = new QPushButton(tab);
        pauseButton->setObjectName(QStringLiteral("pauseButton"));

        gridLayout_5->addWidget(pauseButton, 1, 2, 1, 1);


        verticalLayout->addLayout(gridLayout_5);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_9 = new QGridLayout(tab_2);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        line_2 = new QFrame(tab_2);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_9->addWidget(line_2, 1, 1, 1, 1);

        groupBox_3 = new QGroupBox(tab_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(18);
        font.setBold(false);
        font.setWeight(50);
        groupBox_3->setFont(font);
        gridLayout_7 = new QGridLayout(groupBox_3);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setWeight(50);
        label_6->setFont(font1);

        gridLayout_7->addWidget(label_6, 1, 0, 1, 1);

        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font1);

        gridLayout_7->addWidget(label_5, 0, 0, 1, 1);

        le_radioPort = new QLineEdit(groupBox_3);
        le_radioPort->setObjectName(QStringLiteral("le_radioPort"));
        QFont font2;
        font2.setPointSize(14);
        le_radioPort->setFont(font2);

        gridLayout_7->addWidget(le_radioPort, 0, 1, 1, 1);

        le_usbPort = new QLineEdit(groupBox_3);
        le_usbPort->setObjectName(QStringLiteral("le_usbPort"));

        gridLayout_7->addWidget(le_usbPort, 1, 1, 1, 1);

        gridLayout_10 = new QGridLayout();
        gridLayout_10->setSpacing(6);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        le_destNode = new QLineEdit(groupBox_3);
        le_destNode->setObjectName(QStringLiteral("le_destNode"));
        le_destNode->setFont(font2);

        gridLayout_10->addWidget(le_destNode, 0, 1, 1, 1);

        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_10->addWidget(label_9, 0, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout_10, 3, 0, 1, 2);

        line_3 = new QFrame(groupBox_3);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_7->addWidget(line_3, 2, 0, 1, 1);

        line_4 = new QFrame(groupBox_3);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout_7->addWidget(line_4, 2, 1, 1, 1);


        gridLayout_9->addWidget(groupBox_3, 0, 1, 1, 1);

        groupBox = new QGroupBox(tab_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QFont font3;
        font3.setFamily(QStringLiteral("Arial"));
        font3.setPointSize(18);
        groupBox->setFont(font3);
        gridLayout_6 = new QGridLayout(groupBox);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font2);

        gridLayout_6->addWidget(label, 0, 0, 1, 1);

        le_ref1 = new QLineEdit(groupBox);
        le_ref1->setObjectName(QStringLiteral("le_ref1"));
        le_ref1->setFont(font2);

        gridLayout_6->addWidget(le_ref1, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font2);

        gridLayout_6->addWidget(label_2, 1, 0, 1, 1);

        le_ref2 = new QLineEdit(groupBox);
        le_ref2->setObjectName(QStringLiteral("le_ref2"));
        le_ref2->setFont(font2);

        gridLayout_6->addWidget(le_ref2, 1, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font2);

        gridLayout_6->addWidget(label_4, 2, 0, 1, 1);

        le_ref3 = new QLineEdit(groupBox);
        le_ref3->setObjectName(QStringLiteral("le_ref3"));
        le_ref3->setFont(font2);

        gridLayout_6->addWidget(le_ref3, 2, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font2);

        gridLayout_6->addWidget(label_3, 3, 0, 1, 1);

        le_ref4 = new QLineEdit(groupBox);
        le_ref4->setObjectName(QStringLiteral("le_ref4"));
        le_ref4->setFont(font2);

        gridLayout_6->addWidget(le_ref4, 3, 1, 1, 1);


        gridLayout_9->addWidget(groupBox, 0, 0, 1, 1);

        line = new QFrame(tab_2);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_9->addWidget(line, 1, 0, 1, 1);

        groupBox_2 = new QGroupBox(tab_2);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setFont(font3);
        verticalLayout_4 = new QVBoxLayout(groupBox_2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        rb_geom2d = new QRadioButton(groupBox_2);
        rb_geom2d->setObjectName(QStringLiteral("rb_geom2d"));
        QFont font4;
        font4.setFamily(QStringLiteral("Arial"));
        font4.setPointSize(14);
        rb_geom2d->setFont(font4);

        verticalLayout_4->addWidget(rb_geom2d);

        rb_nlls2d = new QRadioButton(groupBox_2);
        rb_nlls2d->setObjectName(QStringLiteral("rb_nlls2d"));
        rb_nlls2d->setFont(font2);

        verticalLayout_4->addWidget(rb_nlls2d);

        rb_nlls3d = new QRadioButton(groupBox_2);
        rb_nlls3d->setObjectName(QStringLiteral("rb_nlls3d"));
        rb_nlls3d->setFont(font2);

        verticalLayout_4->addWidget(rb_nlls3d);

        rb_kf2d = new QRadioButton(groupBox_2);
        rb_kf2d->setObjectName(QStringLiteral("rb_kf2d"));
        rb_kf2d->setFont(font2);

        verticalLayout_4->addWidget(rb_kf2d);

        rb_kf3d = new QRadioButton(groupBox_2);
        rb_kf3d->setObjectName(QStringLiteral("rb_kf3d"));
        rb_kf3d->setFont(font2);

        verticalLayout_4->addWidget(rb_kf3d);


        gridLayout_9->addWidget(groupBox_2, 2, 0, 1, 1);

        groupBox_4 = new QGroupBox(tab_2);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setFont(font);
        gridLayout_8 = new QGridLayout(groupBox_4);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_8->addWidget(label_7, 0, 0, 1, 1);

        le_numOfIter = new QLineEdit(groupBox_4);
        le_numOfIter->setObjectName(QStringLiteral("le_numOfIter"));
        le_numOfIter->setFont(font2);

        gridLayout_8->addWidget(le_numOfIter, 0, 1, 1, 1);

        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_8->addWidget(label_8, 1, 0, 1, 1);

        le_E = new QLineEdit(groupBox_4);
        le_E->setObjectName(QStringLiteral("le_E"));
        le_E->setFont(font2);

        gridLayout_8->addWidget(le_E, 1, 1, 1, 1);


        gridLayout_9->addWidget(groupBox_4, 2, 1, 1, 1);

        pb_set = new QPushButton(tab_2);
        pb_set->setObjectName(QStringLiteral("pb_set"));

        gridLayout_9->addWidget(pb_set, 3, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer, 3, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());

        verticalLayout_2->addWidget(tabWidget);


        retranslateUi(Dialog);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0));
        R3Label->setText(QApplication::translate("Dialog", "R3", 0));
        R1Label->setText(QApplication::translate("Dialog", "R1", 0));
        R2Label->setText(QApplication::translate("Dialog", "R2", 0));
        R0Label->setText(QApplication::translate("Dialog", "R0", 0));
        TimeLabel->setText(QApplication::translate("Dialog", "Time", 0));
        XLabel->setText(QApplication::translate("Dialog", "X", 0));
        YLabel->setText(QApplication::translate("Dialog", "Y", 0));
        ZLabel->setText(QApplication::translate("Dialog", "Z", 0));
        YawLabel->setText(QApplication::translate("Dialog", "Yaw", 0));
        PitchLabel->setText(QApplication::translate("Dialog", "Pitch", 0));
        RollLabel->setText(QApplication::translate("Dialog", "Roll", 0));
        pauseButton->setText(QApplication::translate("Dialog", "Start", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Dialog", "Engineering Screen", 0));
        groupBox_3->setTitle(QApplication::translate("Dialog", "Radio Parameters", 0));
        label_6->setText(QApplication::translate("Dialog", "USB Interface Port", 0));
        label_5->setText(QApplication::translate("Dialog", "Radio Port", 0));
        le_radioPort->setText(QApplication::translate("Dialog", "/dev/cu.usbmodem101", 0));
        le_destNode->setText(QApplication::translate("Dialog", "100", 0));
        label_9->setText(QApplication::translate("Dialog", "Destination Node", 0));
        groupBox->setTitle(QApplication::translate("Dialog", "Reference Positions", 0));
        label->setText(QApplication::translate("Dialog", "Ref 1", 0));
        le_ref1->setText(QApplication::translate("Dialog", "-0.500", 0));
        label_2->setText(QApplication::translate("Dialog", "Ref 2", 0));
        le_ref2->setText(QApplication::translate("Dialog", "0.000", 0));
        label_4->setText(QApplication::translate("Dialog", "Ref 3", 0));
        le_ref3->setText(QApplication::translate("Dialog", "0.500", 0));
        label_3->setText(QApplication::translate("Dialog", "Ref 4", 0));
        le_ref4->setText(QApplication::translate("Dialog", "0.000", 0));
        groupBox_2->setTitle(QApplication::translate("Dialog", "Solver Type", 0));
        rb_geom2d->setText(QApplication::translate("Dialog", "Geometric 2D", 0));
        rb_nlls2d->setText(QApplication::translate("Dialog", "Non Linear Least Square 2D", 0));
        rb_nlls3d->setText(QApplication::translate("Dialog", "Non Linear Least Square 3d", 0));
        rb_kf2d->setText(QApplication::translate("Dialog", "Kalman Filter 2D", 0));
        rb_kf3d->setText(QApplication::translate("Dialog", "Kalman Filter 3D", 0));
        groupBox_4->setTitle(QApplication::translate("Dialog", "Solver Parameters", 0));
        label_7->setText(QApplication::translate("Dialog", "Max Num of Iter", 0));
        le_numOfIter->setText(QApplication::translate("Dialog", "15", 0));
        label_8->setText(QApplication::translate("Dialog", "E", 0));
        le_E->setText(QApplication::translate("Dialog", "0.001", 0));
        pb_set->setText(QApplication::translate("Dialog", "Set", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Dialog", "Configuration", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
