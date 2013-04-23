/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names
**     of its contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtWidgets>

#include "geometryengine.h"
#include "mainwidget.h"
#include "QFile"
#include "QTextStream"



MainWidget::MainWidget(QWidget *parent)
{
    QHBoxLayout *mainLayout = new QHBoxLayout;

    x = y = 0;
    z = -0.2;
    r = p = w = 10;

            QColor clearColor;
            clearColor.setHsv(180, 200, 255);

            glWidget = new GeometryEngine;
            glWidget->setClearColor(clearColor);
            mainLayout->addWidget(glWidget);


    this->setLayout(mainLayout);



    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(rotateOneStep()));
    timer->start(1);

    setWindowTitle(tr("Textures"));

    file.setFileName(":/Test1Log.txt");
    //file.setFileName(":/90degHallDistance.txt");
    //file.setFileName(":/90degStandStill.txt");
    //file.setFileName(":/VerticalHallDistance.txt");
    //file.setFileName(":/verticalStandStill1.txt");
    //file.setFileName(":/NLLS3Doutput.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

    in.setDevice(&file);


}

//void Window::setCurrentGlWidget()
//{
//    currentGlWidget = qobject_cast<GLWidget *>(sender());
//}

void MainWidget::rotateOneStep(float x, float y, float z, float r, float p, float w)
{
    //QString xstr,ystr,zstr,rstr,pstr,wstr;


//    if(!file.atEnd())
//    {
//        QString line = in.readLine();
//        QStringList list = line.split(",");
//        xstr = list.at(2);
//        ystr = list.at(3);
//        zstr = list.at(4);
//        rstr = list.at(5);
//        pstr = list.at(6);
//        wstr = list.at(7);
//    }




    //qDebug() << "x = "<< xstr << ", y = " << ystr << ", z = " << zstr << ", r = " << rstr << ", p = " << pstr << ", w = " << wstr;


//    x = xstr.toFloat()/3.0;
//    y = ystr.toFloat();
//    z = zstr.toFloat() * -1;

//    r = rstr.toFloat();
//    p = pstr.toFloat();
//    w = wstr.toFloat();


//    x += 0.01;
//    y += 0.01;
//    z -= 0.01;

//    r += 10.0;
//    p += 10.0;
//    w += 10.0;
   x = x /3.0;
    z = z * -10.0;


    qDebug() << "x = "<< x << ", y = " << y << ", z = " << z << ", r = " << r << ", p = " << p << ", w = " << w;

    glWidget->rotateBy(r, p, w, x, y, z);
    //glWidget->updateGL();

}
