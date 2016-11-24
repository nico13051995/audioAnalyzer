/****************************************************************************
** Meta object code from reading C++ file 'graphfilterservice.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../spectrum/app/graphfilterservice.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'graphfilterservice.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GraphFilterService_t {
    QByteArrayData data[18];
    char stringdata0[186];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GraphFilterService_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GraphFilterService_t qt_meta_stringdata_GraphFilterService = {
    {
QT_MOC_LITERAL(0, 0, 18), // "GraphFilterService"
QT_MOC_LITERAL(1, 19, 13), // "bufferChanged"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 8), // "position"
QT_MOC_LITERAL(4, 43, 6), // "length"
QT_MOC_LITERAL(5, 50, 6), // "buffer"
QT_MOC_LITERAL(6, 57, 4), // "save"
QT_MOC_LITERAL(7, 62, 5), // "start"
QT_MOC_LITERAL(8, 68, 3), // "end"
QT_MOC_LITERAL(9, 72, 10), // "QIODevice*"
QT_MOC_LITERAL(10, 83, 3), // "out"
QT_MOC_LITERAL(11, 87, 17), // "subscribeWaveForm"
QT_MOC_LITERAL(12, 105, 10), // "QXYSeries*"
QT_MOC_LITERAL(13, 116, 3), // "set"
QT_MOC_LITERAL(14, 120, 6), // "chanel"
QT_MOC_LITERAL(15, 127, 20), // "unSubscribeWaveFormm"
QT_MOC_LITERAL(16, 148, 17), // "subscribeSpectrum"
QT_MOC_LITERAL(17, 166, 19) // "unSubscribeSpectrum"

    },
    "GraphFilterService\0bufferChanged\0\0"
    "position\0length\0buffer\0save\0start\0end\0"
    "QIODevice*\0out\0subscribeWaveForm\0"
    "QXYSeries*\0set\0chanel\0unSubscribeWaveFormm\0"
    "subscribeSpectrum\0unSubscribeSpectrum"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GraphFilterService[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   44,    2, 0x0a /* Public */,
       6,    3,   51,    2, 0x0a /* Public */,
      11,    2,   58,    2, 0x0a /* Public */,
      15,    2,   63,    2, 0x0a /* Public */,
      16,    1,   68,    2, 0x0a /* Public */,
      17,    1,   71,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong, QMetaType::QByteArray,    3,    4,    5,
    QMetaType::Bool, QMetaType::LongLong, QMetaType::LongLong, 0x80000000 | 9,    7,    8,   10,
    QMetaType::Void, 0x80000000 | 12, QMetaType::Int,   13,   14,
    QMetaType::Void, 0x80000000 | 12, QMetaType::Int,   13,   14,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, 0x80000000 | 12,   13,

       0        // eod
};

void GraphFilterService::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GraphFilterService *_t = static_cast<GraphFilterService *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->bufferChanged((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])),(*reinterpret_cast< const QByteArray(*)>(_a[3]))); break;
        case 1: { bool _r = _t->save((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])),(*reinterpret_cast< QIODevice*(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 2: _t->subscribeWaveForm((*reinterpret_cast< QXYSeries*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->unSubscribeWaveFormm((*reinterpret_cast< QXYSeries*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->subscribeSpectrum((*reinterpret_cast< QXYSeries*(*)>(_a[1]))); break;
        case 5: _t->unSubscribeSpectrum((*reinterpret_cast< QXYSeries*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QIODevice* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QXYSeries* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QXYSeries* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QXYSeries* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QXYSeries* >(); break;
            }
            break;
        }
    }
}

const QMetaObject GraphFilterService::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GraphFilterService.data,
      qt_meta_data_GraphFilterService,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GraphFilterService::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GraphFilterService::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GraphFilterService.stringdata0))
        return static_cast<void*>(const_cast< GraphFilterService*>(this));
    return QObject::qt_metacast(_clname);
}

int GraphFilterService::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
