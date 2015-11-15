/****************************************************************************
** Meta object code from reading C++ file 'settingnumberdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../gao/settingnumberdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'settingnumberdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SettingNumberDialog_t {
    QByteArrayData data[3];
    char stringdata[45];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SettingNumberDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SettingNumberDialog_t qt_meta_stringdata_SettingNumberDialog = {
    {
QT_MOC_LITERAL(0, 0, 19),
QT_MOC_LITERAL(1, 20, 23),
QT_MOC_LITERAL(2, 44, 0)
    },
    "SettingNumberDialog\0on_lineEdit_textChanged\0"
    ""
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SettingNumberDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void SettingNumberDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SettingNumberDialog *_t = static_cast<SettingNumberDialog *>(_o);
        switch (_id) {
        case 0: _t->on_lineEdit_textChanged(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject SettingNumberDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SettingNumberDialog.data,
      qt_meta_data_SettingNumberDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *SettingNumberDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SettingNumberDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SettingNumberDialog.stringdata))
        return static_cast<void*>(const_cast< SettingNumberDialog*>(this));
    if (!strcmp(_clname, "Ui::SettingNumberDialog"))
        return static_cast< Ui::SettingNumberDialog*>(const_cast< SettingNumberDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int SettingNumberDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
