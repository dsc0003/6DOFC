/****************************************************************************
** Meta object code from reading C++ file 'mainwidget.h'
**
** Created: Tue Apr 16 19:22:19 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../6DOFEngineeringScreen/mainwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      45,   12,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWidget[] = {
    "MainWidget\0\0x,y,z,R0,R1,R2,R3,roll,pitch,yaw\0"
    "updateCube(float,float,float,float,float,float,float,float,float,float"
    ")\0"
};

void MainWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWidget *_t = static_cast<MainWidget *>(_o);
        switch (_id) {
        case 0: _t->updateCube((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])),(*reinterpret_cast< float(*)>(_a[5])),(*reinterpret_cast< float(*)>(_a[6])),(*reinterpret_cast< float(*)>(_a[7])),(*reinterpret_cast< float(*)>(_a[8])),(*reinterpret_cast< float(*)>(_a[9])),(*reinterpret_cast< float(*)>(_a[10]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWidget::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_MainWidget,
      qt_meta_data_MainWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWidget))
        return static_cast<void*>(const_cast< MainWidget*>(this));
    if (!strcmp(_clname, "QGLFunctions"))
        return static_cast< QGLFunctions*>(const_cast< MainWidget*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int MainWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
