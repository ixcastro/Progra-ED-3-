/****************************************************************************
** Meta object code from reading C++ file 'window_report.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AdminGUI/window_report.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'window_report.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_window_report_t {
    QByteArrayData data[14];
    char stringdata0[319];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_window_report_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_window_report_t qt_meta_stringdata_window_report = {
    {
QT_MOC_LITERAL(0, 0, 13), // "window_report"
QT_MOC_LITERAL(1, 14, 15), // "on_back_clicked"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 29), // "on_pasilloMasVisitado_clicked"
QT_MOC_LITERAL(4, 61, 31), // "on_pasilloMenosVisitado_clicked"
QT_MOC_LITERAL(5, 93, 26), // "on_marcaMasVendida_clicked"
QT_MOC_LITERAL(6, 120, 27), // "on_ClienteMasCompro_clicked"
QT_MOC_LITERAL(7, 148, 29), // "on_ClienteMenosCompro_clicked"
QT_MOC_LITERAL(8, 178, 26), // "on_prodCargadoGond_clicked"
QT_MOC_LITERAL(9, 205, 27), // "on_clientMasFacturo_clicked"
QT_MOC_LITERAL(10, 233, 28), // "on_facturaMayorMonto_clicked"
QT_MOC_LITERAL(11, 262, 19), // "on_clientes_clicked"
QT_MOC_LITERAL(12, 282, 18), // "on_pasillo_clicked"
QT_MOC_LITERAL(13, 301, 17) // "on_invent_clicked"

    },
    "window_report\0on_back_clicked\0\0"
    "on_pasilloMasVisitado_clicked\0"
    "on_pasilloMenosVisitado_clicked\0"
    "on_marcaMasVendida_clicked\0"
    "on_ClienteMasCompro_clicked\0"
    "on_ClienteMenosCompro_clicked\0"
    "on_prodCargadoGond_clicked\0"
    "on_clientMasFacturo_clicked\0"
    "on_facturaMayorMonto_clicked\0"
    "on_clientes_clicked\0on_pasillo_clicked\0"
    "on_invent_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_window_report[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    0,   84,    2, 0x08 /* Private */,
      13,    0,   85,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void window_report::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<window_report *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_back_clicked(); break;
        case 1: _t->on_pasilloMasVisitado_clicked(); break;
        case 2: _t->on_pasilloMenosVisitado_clicked(); break;
        case 3: _t->on_marcaMasVendida_clicked(); break;
        case 4: _t->on_ClienteMasCompro_clicked(); break;
        case 5: _t->on_ClienteMenosCompro_clicked(); break;
        case 6: _t->on_prodCargadoGond_clicked(); break;
        case 7: _t->on_clientMasFacturo_clicked(); break;
        case 8: _t->on_facturaMayorMonto_clicked(); break;
        case 9: _t->on_clientes_clicked(); break;
        case 10: _t->on_pasillo_clicked(); break;
        case 11: _t->on_invent_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject window_report::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_window_report.data,
    qt_meta_data_window_report,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *window_report::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *window_report::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_window_report.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int window_report::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
