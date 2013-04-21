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

#include "glwidget.h"
#include "window.h"

Window::Window(QWidget *parent)
{
    x_in = y_in = z_in = 0.001;
    roll_in = pitch_in = yaw_in = 10.0;

    QHBoxLayout *mainLayout = new QHBoxLayout;

//    for (int i = 0; i < NumRows; ++i) {
//        for (int j = 0; j < NumColumns; ++j) {
//            QColor clearColor;
//            clearColor.setHsv(((i * NumColumns) + j) * 255
//                              / (NumRows * NumColumns), //***** - 1),*****//
//                              255, 63);

//            glWidgets[i][j] = new GLWidget(0, 0);
//            glWidgets[i][j]->setClearColor(clearColor);
//            glWidgets[i][j]->rotateBy(+42 * 16, +42 * 16, -21 * 16);
//            mainLayout->addWidget(glWidgets[i][j], i, j);

//            connect(glWidgets[i][j], SIGNAL(clicked()),
//                    this, SLOT(setCurrentGlWidget()));
//        }
//    }


    QColor clearColor;
    clearColor.setHsv(210, 150, 255);

    glWidget = new GLWidget;
    glWidget->setClearColor(clearColor);
    //glWidget->rotateBy();
    mainLayout->addWidget(glWidget);


    //connect(glWidgets[i][j], SIGNAL(clicked()), this, SLOT(setCurrentGlWidget()));


    setLayout(mainLayout);

    //currentGlWidget = glWidgets[0][0];

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(rotateOneStep()));
    timer->start();

    //setWindowTitle(tr("6DOFC: Sword of Life"));
}

//void Window::setCurrentGlWidget()
//{
//    qDebug() << "setCurrentGLWidget()";

//    currentGlWidget = qobject_cast<GLWidget *>(sender());
//}

void Window::rotateOneStep()
{

    //qDebug() << "rotateOneStep() parameters: x,y,z,r,p,w " << x_in << ", " << y_in << ", " << z_in << ", " << roll_in << ", " << pitch_in << ", " << yaw_in << endl << endl;

    float x,y,z,r,p,w;
    x=y=z=r=p=w=0.0;

    x += x_in;
    y += y_in;
    z += z_in;

    r += roll_in;
    p += pitch_in;
    w += yaw_in;

    qDebug() << "rotateOneStep() parameters:  " << x_in << ", " << y_in << ", " << z_in << ", " << roll_in << ", " << pitch_in << ", " << yaw_in << endl << endl;
    qDebug() << "rotateOneStep() parameters: x,y,z,r,p,w " << x << ", " << y << ", " << z << ", " << r << ", " << p << ", " << w << endl << endl;


    glWidget->rotateBy(r,p,w,x,y,z);

    //glWidget->rotateBy(roll_in, pitch_in, yaw_in, x_in, y_in, z_in);

    glWidget->updateGL();

    //if (currentGlWidget)
        //currentGlWidget->rotateBy(+2 * 16, +2 * 16, -1 * 16);
        //currentGlWidget->rotateBy(roll_in, pitch_in, yaw_in, x_in, y_in, z_in);
}


//void Window::translateOneStep()
//{
//    qDebug() << "translateOneStep()";

//    if(currentGlWidget)
//        currentGlWidget->translateBy(x_in, y_in, z_in);
//}


void Window::updatePositionData(float x, float y, float z)
{
    qDebug() << "updatePositionData: x, y , z " << x << ", " << y << ", " << z;

//    glWidget->xTrans = x;
//    glWidget->yTrans = y;
//    glWidget->zTrans = z;

    x_in_ptr = x/100.0;
    y_in_ptr = y/100.0;
    z_in_ptr = z/100.0;




//    x_in = x;
//    y_in = y;
//    z_in = z;

    //qDebug() << "glWidget->parameters: x,y,z " << glWidget->xTrans << ", " << glWidget->yTrans << ", " << glWidget->zTrans << endl << endl;

    qDebug() << "glWidget->parameters: x,y,z " << x_in << ", " << y_in << ", " << z_in << endl << endl;

}

void Window::updateRotationData(float roll, float pitch, float yaw)
{
    qDebug() << "updateRotationData: r,p,w " << roll << ", " << pitch << ", " << yaw;

//    glWidget->xRot = roll;
//    glWidget->yRot = pitch;
//    glWidget->zRot = yaw;


    roll_in_ptr += 10;
    pitch_in_ptr += 10;
    yaw_in_ptr += 10.0;

//    roll_in = roll;
//    pitch_in = pitch;
//    yaw_in = yaw;

    //qDebug() << "glWidget->parameters: r,p,w " << glWidget->xRot << ", " << glWidget->yRot << ", " << glWidget->zRot << endl << endl;


    qDebug() << "glWidget->parameters: r,p,w " << roll_in << ", " << pitch_in << ", " << yaw_in << endl << endl;


}
