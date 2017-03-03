/****************************************************************************
** Meta object code from reading C++ file 'DlgEncoderSetting.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "StdAfx.h"
#include "../../dlgencodersetting.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DlgEncoderSetting.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DlgEncoderSetting[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      25,   19,   18,   18, 0x0a,
      70,   19,   18,   18, 0x0a,
     116,  114,   18,   18, 0x0a,
     154,  114,   18,   18, 0x0a,
     193,   19,   18,   18, 0x0a,
     238,   18,   18,   18, 0x0a,
     267,   18,   18,   18, 0x0a,
     296,   18,   18,   18, 0x0a,
     323,   18,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_DlgEncoderSetting[] = {
    "DlgEncoderSetting\0\0index\0"
    "on_combVideoEncoder_currentIndexChanged(int)\0"
    "on_combVideoPerset_currentIndexChanged(int)\0"
    "i\0on_spinVideoBitrate_valueChanged(int)\0"
    "on_spinVBVBitrateMax_valueChanged(int)\0"
    "on_combVideoVBVMode_currentIndexChanged(int)\0"
    "on_butBrowVideoDir_clicked()\0"
    "on_butViewVideoDir_clicked()\0"
    "on_butAddLiveUrl_clicked()\0"
    "on_butDelLiveUrl_clicked()\0"
};

void DlgEncoderSetting::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DlgEncoderSetting *_t = static_cast<DlgEncoderSetting *>(_o);
        switch (_id) {
        case 0: _t->on_combVideoEncoder_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_combVideoPerset_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_spinVideoBitrate_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_spinVBVBitrateMax_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_combVideoVBVMode_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_butBrowVideoDir_clicked(); break;
        case 6: _t->on_butViewVideoDir_clicked(); break;
        case 7: _t->on_butAddLiveUrl_clicked(); break;
        case 8: _t->on_butDelLiveUrl_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData DlgEncoderSetting::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DlgEncoderSetting::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DlgEncoderSetting,
      qt_meta_data_DlgEncoderSetting, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DlgEncoderSetting::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DlgEncoderSetting::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DlgEncoderSetting::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DlgEncoderSetting))
        return static_cast<void*>(const_cast< DlgEncoderSetting*>(this));
    return QWidget::qt_metacast(_clname);
}

int DlgEncoderSetting::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
