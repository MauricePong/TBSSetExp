/****************************************************************************
** Meta object code from reading C++ file 'setmactool.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../setmactool.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'setmactool.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SetMACTool_t {
    QByteArrayData data[9];
    char stringdata0[128];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SetMACTool_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SetMACTool_t qt_meta_stringdata_SetMACTool = {
    {
QT_MOC_LITERAL(0, 0, 10), // "SetMACTool"
QT_MOC_LITERAL(1, 11, 14), // "threadFinished"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 17), // "soltsDisplayMsgUI"
QT_MOC_LITERAL(4, 45, 13), // "TBS_Msg_Type*"
QT_MOC_LITERAL(5, 59, 3), // "msg"
QT_MOC_LITERAL(6, 63, 23), // "on_btn_Macapply_clicked"
QT_MOC_LITERAL(7, 87, 36), // "slot_com_LocalIP_currentIndex..."
QT_MOC_LITERAL(8, 124, 3) // "idx"

    },
    "SetMACTool\0threadFinished\0\0soltsDisplayMsgUI\0"
    "TBS_Msg_Type*\0msg\0on_btn_Macapply_clicked\0"
    "slot_com_LocalIP_currentIndexChanged\0"
    "idx"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SetMACTool[] = {

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
       1,    0,   34,    2, 0x08 /* Private */,
       3,    1,   35,    2, 0x08 /* Private */,
       6,    0,   38,    2, 0x08 /* Private */,
       7,    1,   39,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,

       0        // eod
};

void SetMACTool::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SetMACTool *_t = static_cast<SetMACTool *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->threadFinished(); break;
        case 1: _t->soltsDisplayMsgUI((*reinterpret_cast< TBS_Msg_Type*(*)>(_a[1]))); break;
        case 2: _t->on_btn_Macapply_clicked(); break;
        case 3: _t->slot_com_LocalIP_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject SetMACTool::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SetMACTool.data,
      qt_meta_data_SetMACTool,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SetMACTool::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SetMACTool::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SetMACTool.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int SetMACTool::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
