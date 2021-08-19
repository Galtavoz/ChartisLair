/****************************************************************************
** Meta object code from reading C++ file 'controller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GUI/controller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Controller_t {
    QByteArrayData data[16];
    char stringdata0[216];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Controller_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Controller_t qt_meta_stringdata_Controller = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Controller"
QT_MOC_LITERAL(1, 11, 4), // "esci"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 6), // "carica"
QT_MOC_LITERAL(4, 24, 9), // "tornaHome"
QT_MOC_LITERAL(5, 34, 11), // "vediRicerca"
QT_MOC_LITERAL(6, 46, 13), // "vediInserisci"
QT_MOC_LITERAL(7, 60, 20), // "vediInfoSviluppatore"
QT_MOC_LITERAL(8, 81, 16), // "vediInfoCatalogo"
QT_MOC_LITERAL(9, 98, 15), // "ricercaProdotti"
QT_MOC_LITERAL(10, 114, 22), // "inserisciNuovoProdotto"
QT_MOC_LITERAL(11, 137, 8), // "modifica"
QT_MOC_LITERAL(12, 146, 15), // "modificaRicerca"
QT_MOC_LITERAL(13, 162, 14), // "salvaModifiche"
QT_MOC_LITERAL(14, 177, 15), // "rimuoviProdotto"
QT_MOC_LITERAL(15, 193, 22) // "rimuoviProdottoRicerca"

    },
    "Controller\0esci\0\0carica\0tornaHome\0"
    "vediRicerca\0vediInserisci\0"
    "vediInfoSviluppatore\0vediInfoCatalogo\0"
    "ricercaProdotti\0inserisciNuovoProdotto\0"
    "modifica\0modificaRicerca\0salvaModifiche\0"
    "rimuoviProdotto\0rimuoviProdottoRicerca"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Controller[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x0a /* Public */,
       3,    0,   85,    2, 0x0a /* Public */,
       4,    0,   86,    2, 0x0a /* Public */,
       5,    0,   87,    2, 0x0a /* Public */,
       6,    0,   88,    2, 0x0a /* Public */,
       7,    0,   89,    2, 0x0a /* Public */,
       8,    0,   90,    2, 0x0a /* Public */,
       9,    0,   91,    2, 0x0a /* Public */,
      10,    0,   92,    2, 0x0a /* Public */,
      11,    0,   93,    2, 0x0a /* Public */,
      12,    0,   94,    2, 0x0a /* Public */,
      13,    0,   95,    2, 0x0a /* Public */,
      14,    0,   96,    2, 0x0a /* Public */,
      15,    0,   97,    2, 0x0a /* Public */,

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
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Controller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Controller *_t = static_cast<Controller *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->esci(); break;
        case 1: _t->carica(); break;
        case 2: _t->tornaHome(); break;
        case 3: _t->vediRicerca(); break;
        case 4: _t->vediInserisci(); break;
        case 5: _t->vediInfoSviluppatore(); break;
        case 6: _t->vediInfoCatalogo(); break;
        case 7: _t->ricercaProdotti(); break;
        case 8: _t->inserisciNuovoProdotto(); break;
        case 9: _t->modifica(); break;
        case 10: _t->modificaRicerca(); break;
        case 11: _t->salvaModifiche(); break;
        case 12: _t->rimuoviProdotto(); break;
        case 13: _t->rimuoviProdottoRicerca(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Controller::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Controller.data,
      qt_meta_data_Controller,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Controller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Controller::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Controller.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Controller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
