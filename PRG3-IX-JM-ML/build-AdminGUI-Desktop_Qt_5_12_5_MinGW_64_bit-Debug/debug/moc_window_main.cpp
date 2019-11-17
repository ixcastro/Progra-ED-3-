/****************************************************************************
** Meta object code from reading C++ file 'window_main.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AdminGUI/window_main.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'window_main.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_window_main_t {
    QByteArrayData data[13];
    char stringdata0[206];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_window_main_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_window_main_t qt_meta_stringdata_window_main = {
    {
QT_MOC_LITERAL(0, 0, 11), // "window_main"
QT_MOC_LITERAL(1, 12, 17), // "on_insert_clicked"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 17), // "on_modify_clicked"
QT_MOC_LITERAL(4, 49, 19), // "on_delete_2_clicked"
QT_MOC_LITERAL(5, 69, 16), // "on_query_clicked"
QT_MOC_LITERAL(6, 86, 16), // "on_check_clicked"
QT_MOC_LITERAL(7, 103, 16), // "on_stock_clicked"
QT_MOC_LITERAL(8, 120, 17), // "on_report_clicked"
QT_MOC_LITERAL(9, 138, 15), // "on_city_clicked"
QT_MOC_LITERAL(10, 154, 16), // "on_close_clicked"
QT_MOC_LITERAL(11, 171, 18), // "on_refresh_clicked"
QT_MOC_LITERAL(12, 190, 15) // "on_bill_clicked"

    },
    "window_main\0on_insert_clicked\0\0"
    "on_modify_clicked\0on_delete_2_clicked\0"
    "on_query_clicked\0on_check_clicked\0"
    "on_stock_clicked\0on_report_clicked\0"
    "on_city_clicked\0on_close_clicked\0"
    "on_refresh_clicked\0on_bill_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_window_main[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,
      11,    0,   78,    2, 0x08 /* Private */,
      12,    0,   79,    2, 0x08 /* Private */,

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

       0        // eod
};

void window_main::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<window_main *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_insert_clicked(); break;
        case 1: _t->on_modify_clicked(); break;
        case 2: _t->on_delete_2_clicked(); break;
        case 3: _t->on_query_clicked(); break;
        case 4: _t->on_check_clicked(); break;
        case 5: _t->on_stock_clicked(); break;
        case 6: _t->on_report_clicked(); break;
        case 7: _t->on_city_clicked(); break;
        case 8: _t->on_close_clicked(); break;
        case 9: _t->on_refresh_clicked(); break;
        case 10: _t->on_bill_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject window_main::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_window_main.data,
    qt_meta_data_window_main,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *window_main::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *window_main::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_window_main.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int window_main::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
