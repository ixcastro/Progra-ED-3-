/****************************************************************************
** Meta object code from reading C++ file 'menu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Cliente/Clientes/menu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'menu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Menu_t {
    QByteArrayData data[18];
    char stringdata0[294];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Menu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Menu_t qt_meta_stringdata_Menu = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Menu"
QT_MOC_LITERAL(1, 5, 15), // "MostrarInfoPais"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 7), // "pNombre"
QT_MOC_LITERAL(4, 30, 18), // "on_txtConP_clicked"
QT_MOC_LITERAL(5, 49, 18), // "on_txtConC_clicked"
QT_MOC_LITERAL(6, 68, 19), // "on_txtConCo_clicked"
QT_MOC_LITERAL(7, 88, 18), // "on_txtConT_clicked"
QT_MOC_LITERAL(8, 107, 20), // "on_txtConPre_clicked"
QT_MOC_LITERAL(9, 128, 19), // "on_txtConNA_clicked"
QT_MOC_LITERAL(10, 148, 18), // "on_txtConR_clicked"
QT_MOC_LITERAL(11, 167, 17), // "on_txtRes_clicked"
QT_MOC_LITERAL(12, 185, 17), // "on_txtFac_clicked"
QT_MOC_LITERAL(13, 203, 18), // "on_botCons_clicked"
QT_MOC_LITERAL(14, 222, 17), // "on_botRes_clicked"
QT_MOC_LITERAL(15, 240, 17), // "on_botFac_clicked"
QT_MOC_LITERAL(16, 258, 16), // "on_botBR_clicked"
QT_MOC_LITERAL(17, 275, 18) // "on_botBR_2_clicked"

    },
    "Menu\0MostrarInfoPais\0\0pNombre\0"
    "on_txtConP_clicked\0on_txtConC_clicked\0"
    "on_txtConCo_clicked\0on_txtConT_clicked\0"
    "on_txtConPre_clicked\0on_txtConNA_clicked\0"
    "on_txtConR_clicked\0on_txtRes_clicked\0"
    "on_txtFac_clicked\0on_botCons_clicked\0"
    "on_botRes_clicked\0on_botFac_clicked\0"
    "on_botBR_clicked\0on_botBR_2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Menu[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x08 /* Private */,
       4,    0,   92,    2, 0x08 /* Private */,
       5,    0,   93,    2, 0x08 /* Private */,
       6,    0,   94,    2, 0x08 /* Private */,
       7,    0,   95,    2, 0x08 /* Private */,
       8,    0,   96,    2, 0x08 /* Private */,
       9,    0,   97,    2, 0x08 /* Private */,
      10,    0,   98,    2, 0x08 /* Private */,
      11,    0,   99,    2, 0x08 /* Private */,
      12,    0,  100,    2, 0x08 /* Private */,
      13,    0,  101,    2, 0x08 /* Private */,
      14,    0,  102,    2, 0x08 /* Private */,
      15,    0,  103,    2, 0x08 /* Private */,
      16,    0,  104,    2, 0x08 /* Private */,
      17,    0,  105,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
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
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Menu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Menu *_t = static_cast<Menu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 10: _t->on_botCons_clicked(); break;
        case 11: _t->on_botRes_clicked(); break;
        case 12: _t->on_botFac_clicked(); break;
        case 13: _t->on_botBR_clicked(); break;
        case 14: _t->on_botBR_2_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Menu::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Menu.data,
    qt_meta_data_Menu,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Menu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Menu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Menu.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Menu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
