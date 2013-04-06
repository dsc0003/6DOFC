/********************************************************************************
** Form generated from reading UI file 'imudialog.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMUDIALOG_H
#define UI_IMUDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_IMUDialog
{
public:
    QDialogButtonBox *buttonBox;
    QTextEdit *textEditStream;
    QPushButton *connectButton;
    QPushButton *disconButton;

    void setupUi(QDialog *IMUDialog)
    {
        if (IMUDialog->objectName().isEmpty())
            IMUDialog->setObjectName(QStringLiteral("IMUDialog"));
        IMUDialog->resize(494, 300);
        buttonBox = new QDialogButtonBox(IMUDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        textEditStream = new QTextEdit(IMUDialog);
        textEditStream->setObjectName(QStringLiteral("textEditStream"));
        textEditStream->setGeometry(QRect(20, 20, 411, 111));
        connectButton = new QPushButton(IMUDialog);
        connectButton->setObjectName(QStringLiteral("connectButton"));
        connectButton->setGeometry(QRect(20, 150, 114, 32));
        disconButton = new QPushButton(IMUDialog);
        disconButton->setObjectName(QStringLiteral("disconButton"));
        disconButton->setGeometry(QRect(150, 150, 114, 32));

        retranslateUi(IMUDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), IMUDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), IMUDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(IMUDialog);
    } // setupUi

    void retranslateUi(QDialog *IMUDialog)
    {
        IMUDialog->setWindowTitle(QApplication::translate("IMUDialog", "Dialog", 0));
        connectButton->setText(QApplication::translate("IMUDialog", "Connect", 0));
        disconButton->setText(QApplication::translate("IMUDialog", "Disconnect", 0));
    } // retranslateUi

};

namespace Ui {
    class IMUDialog: public Ui_IMUDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMUDIALOG_H
