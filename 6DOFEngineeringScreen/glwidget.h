#ifndef GLWIDGET_H
#define GLWIDGET_H


#include <QtOpenGL/QGLWidget>
#include <QMouseEvent>

class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);
    
signals:

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    
public slots:
    
};

#endif // GLWIDGET_H
