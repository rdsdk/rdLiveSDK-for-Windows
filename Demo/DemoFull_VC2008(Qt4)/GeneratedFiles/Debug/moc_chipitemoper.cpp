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
      33,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      24,   14,   13,   13, 0x0a,
      64,   14,   13,   13, 0x0a,
     104,   14,   13,   13, 0x0a,
     157,  150,   13,   13, 0x0a,
     202,  197,   13,   13, 0x0a,
     237,  197,   13,   13, 0x0a,
     270,  150,   13,   13, 0x0a,
     308,   13,   13,   13, 0x0a,
     333,   13,   13,   13, 0x0a,
     358,   13,   13,   13, 0x0a,
     382,   13,   13,   13, 0x0a,
     406,   13,   13,   13, 0x0a,
     430,   13,   13,   13, 0x0a,
     451,   13,   13,   13, 0x0a,
     473,   13,   13,   13, 0x0a,
     502,  494,   13,   13, 0x0a,
     527,   13,   13,   13, 0x0a,
     556,   13,   13,   13, 0x0a,
     585,  494,   13,   13, 0x0a,
     614,   13,   13,   13, 0x0a,
     649,  643,   13,   13, 0x0a,
     676,  643,   13,   13, 0x0a,
     710,  643,   13,   13, 0x0a,
     744,  643,   13,   13, 0x0a,
     776,  643,   13,   13, 0x0a,
     812,  494,   13,   13, 0x0a,
     841,   13,   13,   13, 0x0a,
     872,  867,   13,   13, 0x0a,
     914,  494,   13,   13, 0x0a,
     944,  494,   13,   13, 0x0a,
     972,  494,   13,   13, 0x0a,
    1009, 1007,   13,   13, 0x0a,
    1056,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ChipItemOper[] = {
    "ChipItemOper\0\0fMin,fMax\0"
    "on_widClipLR_areaChanged(double,double)\0"
    "on_widClipTB_areaChanged(double,double)\0"
    "on_widPlayProgress_areaChanged(double,double)\0"
    "fValue\0on_widPlayProgress_valueChanged(double)\0"
    "time\0on_tiePlayStart_timeChanged(QTime)\0"
    "on_tiePlayEnd_timeChanged(QTime)\0"
    "on_widPlayVolume_valueChanged(double)\0"
    "on_butClip16_9_clicked()\0"
    "on_butClip9_16_clicked()\0"
    "on_butClip4_3_clicked()\0on_butClip3_4_clicked()\0"
    "on_butRestore_clicked()\0on_butPlay_clicked()\0"
    "on_butPause_clicked()\0on_butStop_clicked()\0"
    "checked\0on_chkMute_clicked(bool)\0"
    "on_butSetPlayRange_clicked()\0"
    "on_butUsePlayRange_clicked()\0"
    "on_chkLoopPlay_clicked(bool)\0"
    "on_timPlayProgress_timeout()\0value\0"
    "on_hsHue_valueChanged(int)\0"
    "on_hsSaturation_valueChanged(int)\0"
    "on_hsLighteness_valueChanged(int)\0"
    "on_hsContrast_valueChanged(int)\0"
    "on_hsTransparency_valueChanged(int)\0"
    "on_chkFixedHue_clicked(bool)\0"
    "on_texInput_textChanged()\0font\0"
    "on_fontComboBox_currentFontChanged(QFont)\0"
    "on_butTexItalic_clicked(bool)\0"
    "on_butTexBold_clicked(bool)\0"
    "on_butTexSizeByWidth_clicked(bool)\0d\0"
    "on_dspScrollCharPerSecond_valueChanged(double)\0"
    "on_butTexColor_clicked()\0"
};

void ChipItemOper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ChipItemOper *_t = static_cast<ChipItemOper *>(_o);
        switch (_id) {
        case 0: _t->on_widClipLR_areaChanged((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 1: _t->on_widClipTB_areaChanged((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 2: _t->on_widPlayProgress_areaChanged((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 3: _t->on_widPlayProgress_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->on_tiePlayStart_timeChanged((*reinterpret_cast< const QTime(*)>(_a[1]))); break;
        case 5: _t->on_tiePlayEnd_timeChanged((*reinterpret_cast< const QTime(*)>(_a[1]))); break;
        case 6: _t->on_widPlayVolume_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->on_butClip16_9_clicked(); break;
        case 8: _t->on_butClip9_16_clicked(); break;
        case 9: _t->on_butClip4_3_clicked(); break;
        case 10: _t->on_butClip3_4_clicked(); break;
        case 11: _t->on_butRestore_clicked(); break;
        case 12: _t->on_butPlay_clicked(); break;
        case 13: _t->on_butPause_clicked(); break;
        case 14: _t->on_butStop_clicked(); break;
        case 15: _t->on_chkMute_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: _t->on_butSetPlayRange_clicked(); break;
        case 17: _t->on_butUsePlayRange_clicked(); break;
        case 18: _t->on_chkLoopPlay_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 19: _t->on_timPlayProgress_timeout(); break;
        case 20: _t->on_hsHue_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->on_hsSaturation_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->on_hsLighteness_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->on_hsContrast_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: _t->on_hsTransparency_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: _t->on_chkFixedHue_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 26: _t->on_texInput_textChanged(); break;
        case 27: _t->on_fontComboBox_currentFontChanged((*reinterpret_cast< const QFont(*)>(_a[1]))); break;
        case 28: _t->on_butTexItalic_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 29: _t->on_butTexBold_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 30: _t->on_butTexSizeByWidth_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 31: _t->on_dspScrollCharPerSecond_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 32: _t->on_butTexColor_clicked(); break;
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
        if (_id < 33)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 33;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
