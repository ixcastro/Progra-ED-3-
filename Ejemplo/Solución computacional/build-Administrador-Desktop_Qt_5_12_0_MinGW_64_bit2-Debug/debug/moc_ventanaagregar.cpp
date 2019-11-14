/****************************************************************************
** Meta object code from reading C++ file 'ventanaagregar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Administrador/ventanaagregar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ventanaagregar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VentanaAgregar_t {
    QByteArrayData data[9];
    char stringdata0[192];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VentanaAgregar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VentanaAgregar_t qt_meta_stringdata_VentanaAgregar = {
    {
QT_MOC_LITERAL(0, 0, 14), // "VentanaAgregar"
QT_MOC_LITERAL(1, 15, 24), // "on_btAceptarPais_clicked"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 22), // "on_btAceptarCi_clicked"
QT_MOC_LITERAL(4, 64, 22), // "on_btAceptarCo_clicked"
QT_MOC_LITERAL(5, 87, 24), // "on_btAceptarTipo_clicked"
QT_MOC_LITERAL(6, 112, 24), // "on_btAceptarTren_clicked"
QT_MOC_LITERAL(7, 137, 24), // "on_btAceptarRuta_clicked"
QT_MOC_LITERAL(8, 162, 29) // "on_btAceptarAtraccion_clicked"

    },
    "VentanaAgregar\0on_btAceptarPais_clicked\0"
    "\0on_btAceptarCi_clicked\0on_btAceptarCo_clicked\0"
    "on_btAceptarTipo_clicked\0"
    "on_btAceptarTren_clicked\0"
    "on_btAceptarRuta_clicked\0"
    "on_btAceptarAtraccion_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VentanaAgregar[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void VentanaAgregar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VentanaAgregar *_t = static_cast<VentanaAgregar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btAceptarPais_clicked(); break;
        case 1: _t->on_btAceptarCi_clicked(); break;
        case 2: _t->on_btAceptarCo_clicked(); break;
        case 3: _t->on_btAceptarTipo_clicked(); break;
        case 4: _t->on_btAceptarTren_clicked(); break;
        case 5: _t->on_btAceptarRuta_clicked(); break;
        case 6: _t->on_btAceptarAtraccion_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject VentanaAgregar::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_VentanaAgregar.data,
    qt_meta_data_VentanaAgregar,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *VentanaAgregar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VentanaAgregar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VentanaAgregar.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int VentanaAgregar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
