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
    QByteArrayData data[26];
    char stringdata[255];
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
QT_MOC_LITERAL(4, 40, 12),
QT_MOC_LITERAL(5, 53, 12),
QT_MOC_LITERAL(6, 66, 12),
QT_MOC_LITERAL(7, 79, 12),
QT_MOC_LITERAL(8, 92, 18),
QT_MOC_LITERAL(9, 111, 21),
QT_MOC_LITERAL(10, 133, 21),
QT_MOC_LITERAL(11, 155, 21),
QT_MOC_LITERAL(12, 177, 21),
QT_MOC_LITERAL(13, 199, 7),
QT_MOC_LITERAL(14, 207, 1),
QT_MOC_LITERAL(15, 209, 1),
QT_MOC_LITERAL(16, 211, 1),
QT_MOC_LITERAL(17, 213, 2),
QT_MOC_LITERAL(18, 216, 2),
QT_MOC_LITERAL(19, 219, 2),
QT_MOC_LITERAL(20, 222, 2),
QT_MOC_LITERAL(21, 225, 4),
QT_MOC_LITERAL(22, 230, 5),
QT_MOC_LITERAL(23, 236, 3),
QT_MOC_LITERAL(24, 240, 6),
QT_MOC_LITERAL(25, 247, 6)
    },
    "RefInterface\0getIMUData\0\0sendErrorCount\0"
    "errorCountR0\0errorCountR1\0errorCountR2\0"
    "errorCountR3\0sendThresholdCount\0"
    "thresholdErrorCountR0\0thresholdErrorCountR1\0"
    "thresholdErrorCountR2\0thresholdErrorCountR3\0"
    "display\0x\0y\0z\0R0\0R1\0R2\0R3\0roll\0pitch\0"
    "yaw\0mError\0status\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RefInterface[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x05,
       3,    4,   35,    2, 0x05,
       8,    4,   44,    2, 0x05,
      13,   12,   53,    2, 0x05,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    4,    5,    6,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    9,   10,   11,   12,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float,   14,   15,   16,   17,   18,   19,   20,   21,   22,   23,   24,   25,

       0        // eod
};

void RefInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RefInterface *_t = static_cast<RefInterface *>(_o);
        switch (_id) {
        case 0: _t->getIMUData(); break;
        case 1: _t->sendErrorCount((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 2: _t->sendThresholdCount((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 3: _t->display((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])),(*reinterpret_cast< float(*)>(_a[5])),(*reinterpret_cast< float(*)>(_a[6])),(*reinterpret_cast< float(*)>(_a[7])),(*reinterpret_cast< float(*)>(_a[8])),(*reinterpret_cast< float(*)>(_a[9])),(*reinterpret_cast< float(*)>(_a[10])),(*reinterpret_cast< float(*)>(_a[11])),(*reinterpret_cast< float(*)>(_a[12]))); break;
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
            typedef void (RefInterface::*_t)(int , int , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RefInterface::sendErrorCount)) {
                *result = 1;
            }
        }
        {
            typedef void (RefInterface::*_t)(int , int , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RefInterface::sendThresholdCount)) {
                *result = 2;
            }
        }
        {
            typedef void (RefInterface::*_t)(float , float , float , float , float , float , float , float , float , float , float , float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RefInterface::display)) {
                *result = 3;
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
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void RefInterface::getIMUData()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void RefInterface::sendErrorCount(int _t1, int _t2, int _t3, int _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void RefInterface::sendThresholdCount(int _t1, int _t2, int _t3, int _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void RefInterface::display(float _t1, float _t2, float _t3, float _t4, float _t5, float _t6, float _t7, float _t8, float _t9, float _t10, float _t11, float _t12)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)), const_cast<void*>(reinterpret_cast<const void*>(&_t8)), const_cast<void*>(reinterpret_cast<const void*>(&_t9)), const_cast<void*>(reinterpret_cast<const void*>(&_t10)), const_cast<void*>(reinterpret_cast<const void*>(&_t11)), const_cast<void*>(reinterpret_cast<const void*>(&_t12)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
