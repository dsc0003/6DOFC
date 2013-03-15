#include "mainwidget.h"

#include "geometryengine.h"

#include <QtOpenGL/QGLShaderProgram>
#include <qwaitcondition.h>
#include <QBasicTimer>
#include <QMouseEvent>
#include <QDebug>
#include <math.h>

#include <QDebug>

MainWidget::MainWidget(QWidget *parent) :
    QGLWidget(parent),
    timer(new QBasicTimer),
    program(new QGLShaderProgram),
    geometries(new GeometryEngine)
{
    //xOld=0;
    //yOld=0;
}

MainWidget::~MainWidget()
{
    delete timer; timer = 0;
    delete program; program = 0;
    delete geometries; geometries = 0;

    deleteTexture(texture);
}

void MainWidget::controllerMovement(int x, int y){
    qDebug() << "controller movement detected" << x << "   " << y ;
    //qDebug() << "old movement values" << xOld << "   " << yOld ;
    mousePressPosition = QVector2D((x/5-50),(y/5-10));
    //QWaitCondition sleep;
    //sleep.wait(1000);
    QVector2D diff = QVector2D((x/5),(y/5)) - mousePressPosition;
    QVector3D n = QVector3D(diff.y(), diff.x(), 0.0).normalized();

    qreal acc = diff.length() / 100.0;
    rotationAxis = (rotationAxis * angularSpeed + n * acc).normalized();
    angularSpeed += acc;
    updateGL();
    xOld = x;
    yOld = y;
}

void MainWidget::mousePressEvent(QMouseEvent *e)
{
    qDebug()<<"Function:: Mouse Press Event";
    // Saving mouse press position
    /* By design QVector values are stored as floats, so we can use those
    QVector2D can be set as QVector2D(qreal xpos, qreal ypos); */
    mousePressPosition = QVector2D(e->pos());

}

void MainWidget::mouseReleaseEvent(QMouseEvent *e)
{
    qDebug()<<"Function:: Mouse Release Event";
    // Mouse release position - mouse press position
    QVector2D diff = QVector2D(e->pos()) - mousePressPosition;
    /* We must find the initial position (as last updated pos)
       and then determine current position to get motion translated
       Rotation axis is perpendicular to the mouse position difference
       vector */
    QVector3D n = QVector3D(diff.y(), diff.x(), 0.0).normalized();
    /* QVector3D can be set as QVector3D(qreal xpos, qreal ypos, qreal zpos);
       hence we can transfer 3D movement.
       Accelerate angular speed relative to the length of the mouse sweep */
    qreal acc = diff.length() / 100.0;

    // Calculate new rotation axis as weighted sum
    rotationAxis = (rotationAxis * angularSpeed + n * acc).normalized();

    // Increase angular speed
    angularSpeed += acc;
}

void MainWidget::timerEvent(QTimerEvent *e)
{
    Q_UNUSED(e);
    //qDebug()<<"Function:: Timer Event";
    // Decrease angular speed (friction)
    angularSpeed *= 0.99;

    // Stop rotation when speed goes below threshold
    if (angularSpeed < 0.01)
        angularSpeed = 0.0;
    else {
        // Update rotation
        rotation = QQuaternion::fromAxisAndAngle(rotationAxis, angularSpeed) * rotation;

        // Update scene
        updateGL();
    }
}

void MainWidget::initializeGL()
{
    qglClearColor(Qt::black);

    qDebug() << "Initializing shaders...";
    initShaders();

    qDebug() << "Initializing textures...";
    initTextures();

    // Enable depth buffer
    glEnable(GL_DEPTH_TEST);

    // Enable back face culling
    glEnable(GL_CULL_FACE);

    qDebug() << "Initializing geometries...";
    geometries->init();

    // using QBasicTimer because its faster that QTimer
    timer->start(12, this);
}

void MainWidget::initShaders()
{
    // Overriding system locale until shaders are compiled
    setlocale(LC_NUMERIC, "C");
    qDebug()<<"Function:: initShaders";
    // Compiling vertex shader
    if (!program->addShaderFromSourceFile(QGLShader::Vertex, ":/vshader.glsl"))
        close();

    // Compiling fragment shader
    if (!program->addShaderFromSourceFile(QGLShader::Fragment, ":/fshader.glsl"))
        close();

    // Linking shader pipeline
    if (!program->link())
        close();

    // Binding shader pipeline for use
    if (!program->bind())
        close();
    qDebug()<<"Function:: initShadersEnd";
    // Restore system locale
    setlocale(LC_ALL, "");
}

void MainWidget::initTextures()
{
    // Loading cube.png to texture unit 0
    //GLFunctions functions;
    //functions.initializeGLFunctions(QGLContext::currentContext());

    //functions.glActiveTexture(GL_TEXTURE0);
    //glEnable(GL_TEXTURE_2D);
    //texture = bindTexture(QImage(":/cube.png"));
    //glActiveTexture(GL_TEXTURE0);
    glEnable(GL_TEXTURE_2D);
    texture = bindTexture(QImage(":/cube.png"));

    // Set nearest filtering mode for texture minification
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    // Set bilinear filtering mode for texture magnification
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    qDebug()<<"Function:: initTextures";
    // Wrap texture coordinates by repeating
    // f.ex. texture coordinate (1.1, 1.2) is same as (0.1, 0.2)
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
}

void MainWidget::resizeGL(int w, int h)
{
    // Set OpenGL viewport to cover whole widget
    glViewport(0, 0, w, h);
    qDebug()<<"Function:: ResizeGL";
    // Calculate aspect ratio
    qreal aspect = (qreal)w / ((qreal)h?h:1);

    // Set near plane to 3.0, far plane to 7.0, field of view 45 degrees
    const qreal zNear = 3.0, zFar = 7.0, fov = 45.0;

    // Reset projection
    projection.setToIdentity();

    // Set perspective projection
    projection.perspective(fov, aspect, zNear, zFar);
}

void MainWidget::paintGL()
{
    // Clear color and depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //qDebug()<<"Function:: PaintGL";
    // Calculate model view transformation
    QMatrix4x4 matrix;
    matrix.translate(0.0, 0.0, -5.0);
    matrix.rotate(rotation);

    // Set modelview-projection matrix
    program->setUniformValue("mvp_matrix", projection * matrix);

    // Using texture unit 0 which contains cube.png
    program->setUniformValue("texture", 0);

    // Draw cube geometry
    geometries->drawCubeGeometry(program);
}
