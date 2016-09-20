/****************************************************************************
** Meta object code from reading C++ file 'spectrograph.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../spectrum/app/spectrograph.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'spectrograph.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Spectrograph_t {
    QByteArrayData data[26];
    char stringdata0[281];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Spectrograph_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Spectrograph_t qt_meta_stringdata_Spectrograph = {
    {
QT_MOC_LITERAL(0, 0, 12), // "Spectrograph"
QT_MOC_LITERAL(1, 13, 11), // "infoMessage"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 7), // "message"
QT_MOC_LITERAL(4, 34, 10), // "intervalMs"
QT_MOC_LITERAL(5, 45, 5), // "reset"
QT_MOC_LITERAL(6, 51, 15), // "spectrumChanged"
QT_MOC_LITERAL(7, 67, 17), // "FrequencySpectrum"
QT_MOC_LITERAL(8, 85, 8), // "spectrum"
QT_MOC_LITERAL(9, 94, 17), // "setWindowFunction"
QT_MOC_LITERAL(10, 112, 14), // "WindowFunction"
QT_MOC_LITERAL(11, 127, 4), // "type"
QT_MOC_LITERAL(12, 132, 17), // "calculateSpectrum"
QT_MOC_LITERAL(13, 150, 11), // "QByteArray&"
QT_MOC_LITERAL(14, 162, 8), // "m_buffer"
QT_MOC_LITERAL(15, 171, 8), // "position"
QT_MOC_LITERAL(16, 180, 9), // "setFormat"
QT_MOC_LITERAL(17, 190, 12), // "QAudioFormat"
QT_MOC_LITERAL(18, 203, 6), // "format"
QT_MOC_LITERAL(19, 210, 13), // "bufferChanged"
QT_MOC_LITERAL(20, 224, 6), // "length"
QT_MOC_LITERAL(21, 231, 6), // "buffer"
QT_MOC_LITERAL(22, 238, 14), // "subsctibeChart"
QT_MOC_LITERAL(23, 253, 10), // "QXYSeries*"
QT_MOC_LITERAL(24, 264, 3), // "set"
QT_MOC_LITERAL(25, 268, 12) // "getBarNumber"

    },
    "Spectrograph\0infoMessage\0\0message\0"
    "intervalMs\0reset\0spectrumChanged\0"
    "FrequencySpectrum\0spectrum\0setWindowFunction\0"
    "WindowFunction\0type\0calculateSpectrum\0"
    "QByteArray&\0m_buffer\0position\0setFormat\0"
    "QAudioFormat\0format\0bufferChanged\0"
    "length\0buffer\0subsctibeChart\0QXYSeries*\0"
    "set\0getBarNumber"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Spectrograph[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   64,    2, 0x0a /* Public */,
       6,    1,   65,    2, 0x0a /* Public */,
       9,    1,   68,    2, 0x0a /* Public */,
      12,    2,   71,    2, 0x0a /* Public */,
      16,    1,   76,    2, 0x0a /* Public */,
      19,    3,   79,    2, 0x0a /* Public */,
      22,    1,   86,    2, 0x0a /* Public */,
      25,    0,   89,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 13, QMetaType::LongLong,   14,   15,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong, QMetaType::QByteArray,   15,   20,   21,
    QMetaType::Void, 0x80000000 | 23,   24,
    QMetaType::Int,

       0        // eod
};

void Spectrograph::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Spectrograph *_t = static_cast<Spectrograph *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->infoMessage((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->reset(); break;
        case 2: _t->spectrumChanged((*reinterpret_cast< const FrequencySpectrum(*)>(_a[1]))); break;
        case 3: _t->setWindowFunction((*reinterpret_cast< WindowFunction(*)>(_a[1]))); break;
        case 4: _t->calculateSpectrum((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 5: _t->setFormat((*reinterpret_cast< const QAudioFormat(*)>(_a[1]))); break;
        case 6: _t->bufferChanged((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])),(*reinterpret_cast< const QByteArray(*)>(_a[3]))); break;
        case 7: _t->subsctibeChart((*reinterpret_cast< QXYSeries*(*)>(_a[1]))); break;
        case 8: { int _r = _t->getBarNumber();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAudioFormat >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QXYSeries* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Spectrograph::*_t)(const QString & , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Spectrograph::infoMessage)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Spectrograph::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Spectrograph.data,
      qt_meta_data_Spectrograph,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Spectrograph::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Spectrograph::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Spectrograph.stringdata0))
        return static_cast<void*>(const_cast< Spectrograph*>(this));
    return QObject::qt_metacast(_clname);
}

int Spectrograph::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Spectrograph::infoMessage(const QString & _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
