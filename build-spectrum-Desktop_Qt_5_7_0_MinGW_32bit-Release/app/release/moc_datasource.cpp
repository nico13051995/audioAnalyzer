/****************************************************************************
** Meta object code from reading C++ file 'datasource.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../spectrum/app/datasource.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'datasource.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WaveFormCustom_t {
    QByteArrayData data[16];
    char stringdata0[169];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WaveFormCustom_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WaveFormCustom_t qt_meta_stringdata_WaveFormCustom = {
    {
QT_MOC_LITERAL(0, 0, 14), // "WaveFormCustom"
QT_MOC_LITERAL(1, 15, 12), // "generateData"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 4), // "type"
QT_MOC_LITERAL(4, 34, 8), // "rowCount"
QT_MOC_LITERAL(5, 43, 8), // "colCount"
QT_MOC_LITERAL(6, 52, 13), // "bufferChanged"
QT_MOC_LITERAL(7, 66, 8), // "position"
QT_MOC_LITERAL(8, 75, 6), // "length"
QT_MOC_LITERAL(9, 82, 6), // "buffer"
QT_MOC_LITERAL(10, 89, 9), // "getSeries"
QT_MOC_LITERAL(11, 99, 16), // "QAbstractSeries*"
QT_MOC_LITERAL(12, 116, 15), // "subscribeSeries"
QT_MOC_LITERAL(13, 132, 5), // "value"
QT_MOC_LITERAL(14, 138, 12), // "channelCount"
QT_MOC_LITERAL(15, 151, 17) // "unSubscribeSeries"

    },
    "WaveFormCustom\0generateData\0\0type\0"
    "rowCount\0colCount\0bufferChanged\0"
    "position\0length\0buffer\0getSeries\0"
    "QAbstractSeries*\0subscribeSeries\0value\0"
    "channelCount\0unSubscribeSeries"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WaveFormCustom[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   39,    2, 0x0a /* Public */,
       6,    3,   46,    2, 0x0a /* Public */,
      10,    0,   53,    2, 0x0a /* Public */,
      12,    2,   54,    2, 0x0a /* Public */,
      15,    2,   59,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong, QMetaType::QByteArray,    7,    8,    9,
    0x80000000 | 11,
    QMetaType::Void, 0x80000000 | 11, QMetaType::Int,   13,   14,
    QMetaType::Bool, 0x80000000 | 11, QMetaType::Int,   13,   14,

       0        // eod
};

void WaveFormCustom::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WaveFormCustom *_t = static_cast<WaveFormCustom *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->generateData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->bufferChanged((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])),(*reinterpret_cast< const QByteArray(*)>(_a[3]))); break;
        case 2: { QAbstractSeries* _r = _t->getSeries();
            if (_a[0]) *reinterpret_cast< QAbstractSeries**>(_a[0]) = _r; }  break;
        case 3: _t->subscribeSeries((*reinterpret_cast< QAbstractSeries*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: { bool _r = _t->unSubscribeSeries((*reinterpret_cast< QAbstractSeries*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSeries* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSeries* >(); break;
            }
            break;
        }
    }
}

const QMetaObject WaveFormCustom::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_WaveFormCustom.data,
      qt_meta_data_WaveFormCustom,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *WaveFormCustom::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WaveFormCustom::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_WaveFormCustom.stringdata0))
        return static_cast<void*>(const_cast< WaveFormCustom*>(this));
    return QObject::qt_metacast(_clname);
}

int WaveFormCustom::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
