#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QtOpenGL/QGLWidget>
#include <QGLFunctions>

#include <QMatrix4x4>
#include <QQuaternion>
#include <QVector2D>

class QBasicTimer;
class QGLShaderProgram;

class GeometryEngine;

class MainWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit MainWidget(QWidget *parent = 0);
    virtual ~MainWidget();
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void timerEvent(QTimerEvent *e);
    void controllerMovement(int x, int y);
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    int xOld;
    int yOld;
    void initShaders();
    void initTextures();
public slots:
protected:
private:
    QBasicTimer *timer;
    QGLShaderProgram *program;
    GeometryEngine *geometries;
    GLuint texture;
    QMatrix4x4 projection;
    QVector2D mousePressPosition;
    QVector3D rotationAxis;
    qreal angularSpeed;
    QQuaternion rotation;
};

#endif // MAINWIDGET_H
