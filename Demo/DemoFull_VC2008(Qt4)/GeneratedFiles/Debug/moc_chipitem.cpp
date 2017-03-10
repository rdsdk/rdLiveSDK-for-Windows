/****************************************************************************
** Meta object code from reading C++ file 'ChipItem.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "StdAfx.h"
#include "../../chipitem.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ChipItem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ChipItem[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   10,    9,    9, 0x0a,
      47,   10,    9,    9, 0x0a,
      78,   10,    9,    9, 0x0a,
     106,   10,    9,    9, 0x0a,
     135,   10,    9,    9, 0x0a,
     165,   10,    9,    9, 0x0a,
     192,   10,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ChipItem[] = {
    "ChipItem\0\0checked\0on_chkHideChip_clicked(bool)\0"
    "on_chkLockAspect_clicked(bool)\0"
    "on_chkLockPos_clicked(bool)\0"
    "on_chkLockSize_clicked(bool)\0"
    "on_chkLockAngle_clicked(bool)\0"
    "on_butMiddle_clicked(bool)\0"
    "on_butScaleFull_clicked(bool)\0"
};

void ChipItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ChipItem *_t = static_cast<ChipItem *>(_o);
        switch (_id) {
        case 0: _t->on_chkHideChip_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->on_chkLockAspect_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_chkLockPos_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_chkLockSize_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_chkLockAngle_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_butMiddle_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->on_butScaleFull_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ChipItem::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ChipItem::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ChipItem,
      qt_meta_data_ChipItem, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ChipItem::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ChipItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ChipItem::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ChipItem))
        return static_cast<void*>(const_cast< ChipItem*>(this));
    return QWidget::qt_metacast(_clname);
}

int ChipItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
