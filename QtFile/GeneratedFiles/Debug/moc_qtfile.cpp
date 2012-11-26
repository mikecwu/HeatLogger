/****************************************************************************
** Meta object code from reading C++ file 'qtfile.h'
**
** Created: Fri Oct 19 13:26:18 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qtfile.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtfile.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QtFile[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x08,
      24,    7,    7,    7, 0x08,
      44,    7,    7,    7, 0x08,
      60,    7,    7,    7, 0x08,
      81,    7,    7,    7, 0x08,
     104,    7,    7,    7, 0x08,
     126,    7,    7,    7, 0x08,
     149,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QtFile[] = {
    "QtFile\0\0Take_Function()\0Suppress_Function()\0"
    "Test_Function()\0onNumberChanged(int)\0"
    "Temp_Button_Function()\0Hum_Button_Function()\0"
    "Single_Mode_Function()\0"
    "Continious_Mode_Function()\0"
};

void QtFile::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QtFile *_t = static_cast<QtFile *>(_o);
        switch (_id) {
        case 0: _t->Take_Function(); break;
        case 1: _t->Suppress_Function(); break;
        case 2: _t->Test_Function(); break;
        case 3: _t->onNumberChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->Temp_Button_Function(); break;
        case 5: _t->Hum_Button_Function(); break;
        case 6: _t->Single_Mode_Function(); break;
        case 7: _t->Continious_Mode_Function(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QtFile::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QtFile::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_QtFile,
      qt_meta_data_QtFile, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QtFile::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QtFile::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QtFile::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QtFile))
        return static_cast<void*>(const_cast< QtFile*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int QtFile::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
