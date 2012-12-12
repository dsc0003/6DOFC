#ifndef ENGINEERINGSCREEN_H
#define ENGINEERINGSCREEN_H

#include <QDialog>
#include <QtGui>
#include <refinterface.h>
#include <guiinterface.h>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    
private:
    Ui::Dialog *ui;

private slots:
    void pause();
    void updateDisplay();

protected:
    RefInterface refinterface;
    GuiInterface guiinterface;
    void closeEvent(QCloseEvent *event);

};

#endif // ENGINEERINGSCREEN_H
