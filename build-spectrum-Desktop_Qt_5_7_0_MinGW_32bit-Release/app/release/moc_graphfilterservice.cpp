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
    QByteArrayData data[22];
    char stringdata0[233];
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
QT_MOC_LITERAL(6, 57, 12), // "applyFilters"
QT_MOC_LITERAL(7, 70, 4), // "save"
QT_MOC_LITERAL(8, 75, 5), // "start"
QT_MOC_LITERAL(9, 81, 3), // "end"
QT_MOC_LITERAL(10, 85, 10), // "QIODevice*"
QT_MOC_LITERAL(11, 96, 3), // "out"
QT_MOC_LITERAL(12, 100, 17), // "subscribeWaveForm"
QT_MOC_LITERAL(13, 118, 10), // "QXYSeries*"
QT_MOC_LITERAL(14, 129, 3), // "set"
QT_MOC_LITERAL(15, 133, 6), // "chanel"
QT_MOC_LITERAL(16, 140, 20), // "unSubscribeWaveFormm"
QT_MOC_LITERAL(17, 161, 17), // "subscribeSpectrum"
QT_MOC_LITERAL(18, 179, 19), // "unSubscribeSpectrum"
QT_MOC_LITERAL(19, 199, 13), // "formatChanged"
QT_MOC_LITERAL(20, 213, 12), // "QAudioFormat"
QT_MOC_LITERAL(21, 226, 6) // "format"

    },
    "GraphFilterService\0bufferChanged\0\0"
    "position\0length\0buffer\0applyFilters\0"
    "save\0start\0end\0QIODevice*\0out\0"
    "subscribeWaveForm\0QXYSeries*\0set\0"
    "chanel\0unSubscribeWaveFormm\0"
    "subscribeSpectrum\0unSubscribeSpectrum\0"
    "formatChanged\0QAudioFormat\0format"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GraphFilterService[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   54,    2, 0x0a /* Public */,
       6,    1,   61,    2, 0x0a /* Public */,
       7,    3,   64,    2, 0x0a /* Public */,
      12,    2,   71,    2, 0x0a /* Public */,
      16,    2,   76,    2, 0x0a /* Public */,
      17,    2,   81,    2, 0x0a /* Public */,
      18,    2,   86,    2, 0x0a /* Public */,
      19,    1,   91,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong, QMetaType::QByteArray,    3,    4,    5,
    QMetaType::QByteArray, QMetaType::QByteArray,    5,
    QMetaType::Bool, QMetaType::LongLong, QMetaType::LongLong, 0x80000000 | 10,    8,    9,   11,
    QMetaType::Void, 0x80000000 | 13, QMetaType::Int,   14,   15,
    QMetaType::Void, 0x80000000 | 13, QMetaType::Int,   14,   15,
    QMetaType::Void, 0x80000000 | 13, QMetaType::Int,   14,   15,
    QMetaType::Void, 0x80000000 | 13, QMetaType::Int,   14,   15,
    QMetaType::Void, 0x80000000 | 20,   21,

       0        // eod
};

void GraphFilterService::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GraphFilterService *_t = static_cast<GraphFilterService *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->bufferChanged((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])),(*reinterpret_cast< const QByteArray(*)>(_a[3]))); break;
        case 1: { QByteArray _r = _t->applyFilters((*reinterpret_cast< const QByteArray(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QByteArray*>(_a[0]) = _r; }  break;
        case 2: { bool _r = _t->save((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])),(*reinterpret_cast< QIODevice*(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: _t->subscribeWaveForm((*reinterpret_cast< QXYSeries*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->unSubscribeWaveFormm((*reinterpret_cast< QXYSeries*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->subscribeSpectrum((*reinterpret_cast< QXYSeries*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->unSubscribeSpectrum((*reinterpret_cast< QXYSeries*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->formatChanged((*reinterpret_cast< const QAudioFormat(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QIODevice* >(); break;
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
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QXYSeries* >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAudioFormat >(); break;
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
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
