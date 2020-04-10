/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../server/widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Widget_t {
    QByteArrayData data[20];
    char stringdata0[257];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Widget_t qt_meta_stringdata_Widget = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Widget"
QT_MOC_LITERAL(1, 7, 13), // "read_mpu_data"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 12), // "data_display"
QT_MOC_LITERAL(4, 35, 7), // "double&"
QT_MOC_LITERAL(5, 43, 1), // "x"
QT_MOC_LITERAL(6, 45, 1), // "y"
QT_MOC_LITERAL(7, 47, 15), // "creatConnection"
QT_MOC_LITERAL(8, 63, 13), // "useConnection"
QT_MOC_LITERAL(9, 77, 14), // "receiveMessage"
QT_MOC_LITERAL(10, 92, 15), // "openThreadSlot1"
QT_MOC_LITERAL(11, 108, 16), // "closeThreadSlot1"
QT_MOC_LITERAL(12, 125, 15), // "openThreadSlot2"
QT_MOC_LITERAL(13, 141, 16), // "closeThreadSlot2"
QT_MOC_LITERAL(14, 158, 15), // "openThreadSlot3"
QT_MOC_LITERAL(15, 174, 16), // "closeThreadSlot3"
QT_MOC_LITERAL(16, 191, 15), // "openThreadSlot4"
QT_MOC_LITERAL(17, 207, 16), // "closeThreadSlot4"
QT_MOC_LITERAL(18, 224, 15), // "openThreadSlot5"
QT_MOC_LITERAL(19, 240, 16) // "closeThreadSlot5"

    },
    "Widget\0read_mpu_data\0\0data_display\0"
    "double&\0x\0y\0creatConnection\0useConnection\0"
    "receiveMessage\0openThreadSlot1\0"
    "closeThreadSlot1\0openThreadSlot2\0"
    "closeThreadSlot2\0openThreadSlot3\0"
    "closeThreadSlot3\0openThreadSlot4\0"
    "closeThreadSlot4\0openThreadSlot5\0"
    "closeThreadSlot5"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x0a /* Public */,
       3,    2,   90,    2, 0x0a /* Public */,
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
      18,    0,  106,    2, 0x08 /* Private */,
      19,    0,  107,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4,    5,    6,
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

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Widget *_t = static_cast<Widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->read_mpu_data(); break;
        case 1: _t->data_display((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 2: _t->creatConnection(); break;
        case 3: _t->useConnection(); break;
        case 4: _t->receiveMessage(); break;
        case 5: _t->openThreadSlot1(); break;
        case 6: _t->closeThreadSlot1(); break;
        case 7: _t->openThreadSlot2(); break;
        case 8: _t->closeThreadSlot2(); break;
        case 9: _t->openThreadSlot3(); break;
        case 10: _t->closeThreadSlot3(); break;
        case 11: _t->openThreadSlot4(); break;
        case 12: _t->closeThreadSlot4(); break;
        case 13: _t->openThreadSlot5(); break;
        case 14: _t->closeThreadSlot5(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Widget.data,
      qt_meta_data_Widget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Widget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
