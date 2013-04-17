/********************************************************************************
** Form generated from reading UI file 'imudialog.ui'
**
** Created: Tue Apr 16 19:21:40 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMUDIALOG_H
#define UI_IMUDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>

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
            IMUDialog->setObjectName(QString::fromUtf8("IMUDialog"));
        IMUDialog->resize(494, 300);
        buttonBox = new QDialogButtonBox(IMUDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        textEditStream = new QTextEdit(IMUDialog);
        textEditStream->setObjectName(QString::fromUtf8("textEditStream"));
        textEditStream->setGeometry(QRect(20, 20, 411, 111));
        connectButton = new QPushButton(IMUDialog);
        connectButton->setObjectName(QString::fromUtf8("connectButton"));
        connectButton->setGeometry(QRect(20, 150, 114, 32));
        disconButton = new QPushButton(IMUDialog);
        disconButton->setObjectName(QString::fromUtf8("disconButton"));
        disconButton->setGeometry(QRect(150, 150, 114, 32));

        retranslateUi(IMUDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), IMUDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), IMUDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(IMUDialog);
    } // setupUi

    void retranslateUi(QDialog *IMUDialog)
    {
        IMUDialog->setWindowTitle(QApplication::translate("IMUDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        connectButton->setText(QApplication::translate("IMUDialog", "Connect", 0, QApplication::UnicodeUTF8));
        disconButton->setText(QApplication::translate("IMUDialog", "Disconnect", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class IMUDialog: public Ui_IMUDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMUDIALOG_H
