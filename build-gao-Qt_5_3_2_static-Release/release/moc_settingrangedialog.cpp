/****************************************************************************
** Meta object code from reading C++ file 'settingrangedialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../gao/settingrangedialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'settingrangedialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SettingRangeDialog_t {
    QByteArrayData data[7];
    char stringdata[127];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SettingRangeDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SettingRangeDialog_t qt_meta_stringdata_SettingRangeDialog = {
    {
QT_MOC_LITERAL(0, 0, 18),
QT_MOC_LITERAL(1, 19, 23),
QT_MOC_LITERAL(2, 43, 0),
QT_MOC_LITERAL(3, 44, 4),
QT_MOC_LITERAL(4, 49, 25),
QT_MOC_LITERAL(5, 75, 25),
QT_MOC_LITERAL(6, 101, 25)
    },
    "SettingRangeDialog\0on_lineEdit_textChanged\0"
    "\0arg1\0on_lineEdit_2_textChanged\0"
    "on_lineEdit_3_textChanged\0"
    "on_lineEdit_4_textChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SettingRangeDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x08 /* Private */,
       4,    1,   37,    2, 0x08 /* Private */,
       5,    1,   40,    2, 0x08 /* Private */,
       6,    1,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,

       0        // eod
};

void SettingRangeDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SettingRangeDialog *_t = static_cast<SettingRangeDialog *>(_o);
        switch (_id) {
        case 0: _t->on_lineEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->on_lineEdit_2_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_lineEdit_3_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_lineEdit_4_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject SettingRangeDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SettingRangeDialog.data,
      qt_meta_data_SettingRangeDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *SettingRangeDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SettingRangeDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SettingRangeDialog.stringdata))
        return static_cast<void*>(const_cast< SettingRangeDialog*>(this));
    if (!strcmp(_clname, "Ui::SettingRangeDialog"))
        return static_cast< Ui::SettingRangeDialog*>(const_cast< SettingRangeDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int SettingRangeDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
