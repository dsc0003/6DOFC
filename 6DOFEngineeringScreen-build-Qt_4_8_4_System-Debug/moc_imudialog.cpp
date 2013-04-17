/****************************************************************************
** Meta object code from reading C++ file 'imudialog.h'
**
** Created: Tue Apr 16 19:22:22 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../6DOFEngineeringScreen/imudialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imudialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_IMUDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x0a,
      20,   10,   10,   10, 0x0a,
      29,   10,   10,   10, 0x0a,
      42,   10,   10,   10, 0x0a,
      58,   51,   10,   10, 0x0a,
      77,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_IMUDialog[] = {
    "IMUDialog\0\0openUp()\0discon()\0stopStream()\0"
    "stream()\0status\0onDsrChanged(bool)\0"
    "onReadyRead()\0"
};

void IMUDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        IMUDialog *_t = static_cast<IMUDialog *>(_o);
        switch (_id) {
        case 0: _t->openUp(); break;
        case 1: _t->discon(); break;
        case 2: _t->stopStream(); break;
        case 3: _t->stream(); break;
        case 4: _t->onDsrChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->onReadyRead(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData IMUDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject IMUDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_IMUDialog,
      qt_meta_data_IMUDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &IMUDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *IMUDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *IMUDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_IMUDialog))
        return static_cast<void*>(const_cast< IMUDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int IMUDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
