/****************************************************************************
** Meta object code from reading C++ file 'database.h'
**
** Created: Wed Jul 1 18:03:59 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../database.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'database.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Database[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x08,
      36,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Database[] = {
    "Database\0\0on_pushButton_2_clicked()\0"
    "on_pushButton_3_clicked()\0"
};

const QMetaObject Database::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Database,
      qt_meta_data_Database, 0 }
};

const QMetaObject *Database::metaObject() const
{
    return &staticMetaObject;
}

void *Database::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Database))
        return static_cast<void*>(const_cast< Database*>(this));
    return QDialog::qt_metacast(_clname);
}

int Database::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_pushButton_2_clicked(); break;
        case 1: on_pushButton_3_clicked(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
