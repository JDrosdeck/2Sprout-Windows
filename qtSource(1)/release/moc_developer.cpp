/****************************************************************************
** Meta object code from reading C++ file 'developer.h'
**
** Created: Sat Mar 6 20:33:55 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../developer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'developer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Developer[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x08,
      35,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Developer[] = {
    "Developer\0\0on_pushButton_clicked()\0"
    "on_pushButton_2_clicked()\0"
};

const QMetaObject Developer::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Developer,
      qt_meta_data_Developer, 0 }
};

const QMetaObject *Developer::metaObject() const
{
    return &staticMetaObject;
}

void *Developer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Developer))
        return static_cast<void*>(const_cast< Developer*>(this));
    return QDialog::qt_metacast(_clname);
}

int Developer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_pushButton_clicked(); break;
        case 1: on_pushButton_2_clicked(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
