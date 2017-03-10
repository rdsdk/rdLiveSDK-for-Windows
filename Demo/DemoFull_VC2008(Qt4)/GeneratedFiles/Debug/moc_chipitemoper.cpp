/****************************************************************************
** Meta object code from reading C++ file 'ChipItemOper.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "StdAfx.h"
#include "../../chipitemoper.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ChipItemOper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ChipItemOper[] = {

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
      27,   14,   13,   13, 0x0a,
      67,   14,   13,   13, 0x0a,
     107,   13,   13,   13, 0x0a,
     132,   13,   13,   13, 0x0a,
     157,   13,   13,   13, 0x0a,
     181,   13,   13,   13, 0x0a,
     205,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ChipItemOper[] = {
    "ChipItemOper\0\0fLeft,fRight\0"
    "on_widClipLR_sliderRange(double,double)\0"
    "on_widClipTB_sliderRange(double,double)\0"
    "on_butClip16_9_clicked()\0"
    "on_butClip9_16_clicked()\0"
    "on_butClip4_3_clicked()\0on_butClip3_4_clicked()\0"
    "on_butRestore_clicked()\0"
};

void ChipItemOper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ChipItemOper *_t = static_cast<ChipItemOper *>(_o);
        switch (_id) {
        case 0: _t->on_widClipLR_sliderRange((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 1: _t->on_widClipTB_sliderRange((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 2: _t->on_butClip16_9_clicked(); break;
        case 3: _t->on_butClip9_16_clicked(); break;
        case 4: _t->on_butClip4_3_clicked(); break;
        case 5: _t->on_butClip3_4_clicked(); break;
        case 6: _t->on_butRestore_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ChipItemOper::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ChipItemOper::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ChipItemOper,
      qt_meta_data_ChipItemOper, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ChipItemOper::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ChipItemOper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ChipItemOper::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ChipItemOper))
        return static_cast<void*>(const_cast< ChipItemOper*>(this));
    return QWidget::qt_metacast(_clname);
}

int ChipItemOper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
