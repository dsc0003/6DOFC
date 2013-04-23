/****************************************************************************
** Meta object code from reading C++ file 'refinterface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../6DOFEngineeringScreen/refinterface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'refinterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RefInterface_t {
    QByteArrayData data[18];
    char stringdata[107];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_RefInterface_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_RefInterface_t qt_meta_stringdata_RefInterface = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 10),
QT_MOC_LITERAL(2, 24, 0),
QT_MOC_LITERAL(3, 25, 14),
QT_MOC_LITERAL(4, 40, 10),
QT_MOC_LITERAL(5, 51, 7),
QT_MOC_LITERAL(6, 59, 1),
QT_MOC_LITERAL(7, 61, 1),
QT_MOC_LITERAL(8, 63, 1),
QT_MOC_LITERAL(9, 65, 2),
QT_MOC_LITERAL(10, 68, 2),
QT_MOC_LITERAL(11, 71, 2),
QT_MOC_LITERAL(12, 74, 2),
QT_MOC_LITERAL(13, 77, 4),
QT_MOC_LITERAL(14, 82, 5),
QT_MOC_LITERAL(15, 88, 3),
QT_MOC_LITERAL(16, 92, 6),
QT_MOC_LITERAL(17, 99, 6)
    },
    "RefInterface\0getIMUData\0\0sendErrorCount\0"
    "errorCount\0display\0x\0y\0z\0R0\0R1\0R2\0R3\0"
    "roll\0pitch\0yaw\0mError\0status\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RefInterface[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x05,
       3,    1,   30,    2, 0x05,
       5,   12,   33,    2, 0x05,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float,    6,    7,    8,    9,   10,   11,   12,   13,   14,   15,   16,   17,

       0        // eod
};

void RefInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RefInterface *_t = static_cast<RefInterface *>(_o);
        switch (_id) {
        case 0: _t->getIMUData(); break;
        case 1: _t->sendErrorCount((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->display((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])),(*reinterpret_cast< float(*)>(_a[5])),(*reinterpret_cast< float(*)>(_a[6])),(*reinterpret_cast< float(*)>(_a[7])),(*reinterpret_cast< float(*)>(_a[8])),(*reinterpret_cast< float(*)>(_a[9])),(*reinterpret_cast< float(*)>(_a[10])),(*reinterpret_cast< float(*)>(_a[11])),(*reinterpret_cast< float(*)>(_a[12]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (RefInterface::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RefInterface::getIMUData)) {
                *result = 0;
            }
        }
        {
            typedef void (RefInterface::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RefInterface::sendErrorCount)) {
                *result = 1;
            }
        }
        {
            typedef void (RefInterface::*_t)(float , float , float , float , float , float , float , float , float , float , float , float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RefInterface::display)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject RefInterface::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_RefInterface.data,
      qt_meta_data_RefInterface,  qt_static_metacall, 0, 0}
};


const QMetaObject *RefInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RefInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RefInterface.stringdata))
        return static_cast<void*>(const_cast< RefInterface*>(this));
    return QThread::qt_metacast(_clname);
}

int RefInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void RefInterface::getIMUData()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void RefInterface::sendErrorCount(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void RefInterface::display(float _t1, float _t2, float _t3, float _t4, float _t5, float _t6, float _t7, float _t8, float _t9, float _t10, float _t11, float _t12)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)), const_cast<void*>(reinterpret_cast<const void*>(&_t8)), const_cast<void*>(reinterpret_cast<const void*>(&_t9)), const_cast<void*>(reinterpret_cast<const void*>(&_t10)), const_cast<void*>(reinterpret_cast<const void*>(&_t11)), const_cast<void*>(reinterpret_cast<const void*>(&_t12)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
