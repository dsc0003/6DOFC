/****************************************************************************
** Meta object code from reading C++ file 'guiinterface.h'
**
** Created: Tue Apr 16 19:22:14 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../6DOFEngineeringScreen/guiinterface.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'guiinterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GuiInterface[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      47,   14,   13,   13, 0x05,
     157,  116,   13,   13, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_GuiInterface[] = {
    "GuiInterface\0\0x,y,z,R0,R1,R2,R3,roll,pitch,yaw\0"
    "display(float,float,float,float,float,float,float,float,float,float)\0"
    "x,y,z,R0,R1,R2,R3,roll,pitch,yaw,reqNode\0"
    "logSignal(float,float,float,float,float,float,float,float,float,float,"
    "QString)\0"
};

void GuiInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        GuiInterface *_t = static_cast<GuiInterface *>(_o);
        switch (_id) {
        case 0: _t->display((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])),(*reinterpret_cast< float(*)>(_a[5])),(*reinterpret_cast< float(*)>(_a[6])),(*reinterpret_cast< float(*)>(_a[7])),(*reinterpret_cast< float(*)>(_a[8])),(*reinterpret_cast< float(*)>(_a[9])),(*reinterpret_cast< float(*)>(_a[10]))); break;
        case 1: _t->logSignal((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])),(*reinterpret_cast< float(*)>(_a[5])),(*reinterpret_cast< float(*)>(_a[6])),(*reinterpret_cast< float(*)>(_a[7])),(*reinterpret_cast< float(*)>(_a[8])),(*reinterpret_cast< float(*)>(_a[9])),(*reinterpret_cast< float(*)>(_a[10])),(*reinterpret_cast< QString(*)>(_a[11]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData GuiInterface::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject GuiInterface::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_GuiInterface,
      qt_meta_data_GuiInterface, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GuiInterface::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GuiInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GuiInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GuiInterface))
        return static_cast<void*>(const_cast< GuiInterface*>(this));
    return QThread::qt_metacast(_clname);
}

int GuiInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void GuiInterface::display(float _t1, float _t2, float _t3, float _t4, float _t5, float _t6, float _t7, float _t8, float _t9, float _t10)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)), const_cast<void*>(reinterpret_cast<const void*>(&_t8)), const_cast<void*>(reinterpret_cast<const void*>(&_t9)), const_cast<void*>(reinterpret_cast<const void*>(&_t10)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GuiInterface::logSignal(float _t1, float _t2, float _t3, float _t4, float _t5, float _t6, float _t7, float _t8, float _t9, float _t10, QString _t11)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)), const_cast<void*>(reinterpret_cast<const void*>(&_t8)), const_cast<void*>(reinterpret_cast<const void*>(&_t9)), const_cast<void*>(reinterpret_cast<const void*>(&_t10)), const_cast<void*>(reinterpret_cast<const void*>(&_t11)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
