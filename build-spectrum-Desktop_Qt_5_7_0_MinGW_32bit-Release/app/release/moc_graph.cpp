/****************************************************************************
** Meta object code from reading C++ file 'graph.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../spectrum/app/graph.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'graph.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Graph_t {
    QByteArrayData data[16];
    char stringdata0[140];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Graph_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Graph_t qt_meta_stringdata_Graph = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Graph"
QT_MOC_LITERAL(1, 6, 7), // "getType"
QT_MOC_LITERAL(2, 14, 11), // "GRAPHICTYPE"
QT_MOC_LITERAL(3, 26, 0), // ""
QT_MOC_LITERAL(4, 27, 7), // "setType"
QT_MOC_LITERAL(5, 35, 5), // "value"
QT_MOC_LITERAL(6, 41, 9), // "getChanel"
QT_MOC_LITERAL(7, 51, 9), // "setChanel"
QT_MOC_LITERAL(8, 61, 15), // "getTemplateName"
QT_MOC_LITERAL(9, 77, 15), // "setTemplateName"
QT_MOC_LITERAL(10, 93, 7), // "getName"
QT_MOC_LITERAL(11, 101, 7), // "setName"
QT_MOC_LITERAL(12, 109, 5), // "getId"
QT_MOC_LITERAL(13, 115, 6), // "SPECTR"
QT_MOC_LITERAL(14, 122, 4), // "WAVE"
QT_MOC_LITERAL(15, 127, 12) // "STYLE_FILLED"

    },
    "Graph\0getType\0GRAPHICTYPE\0\0setType\0"
    "value\0getChanel\0setChanel\0getTemplateName\0"
    "setTemplateName\0getName\0setName\0getId\0"
    "SPECTR\0WAVE\0STYLE_FILLED"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Graph[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       1,   76, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    3, 0x0a /* Public */,
       4,    1,   60,    3, 0x0a /* Public */,
       6,    0,   63,    3, 0x0a /* Public */,
       7,    1,   64,    3, 0x0a /* Public */,
       8,    0,   67,    3, 0x0a /* Public */,
       9,    1,   68,    3, 0x0a /* Public */,
      10,    0,   71,    3, 0x0a /* Public */,
      11,    1,   72,    3, 0x0a /* Public */,
      12,    0,   75,    3, 0x0a /* Public */,

 // slots: parameters
    0x80000000 | 2,
    QMetaType::Void, 0x80000000 | 2,    5,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Int,

 // enums: name, flags, count, data
       2, 0x0,    3,   80,

 // enum data: key, value
      13, uint(Graph::SPECTR),
      14, uint(Graph::WAVE),
      15, uint(Graph::STYLE_FILLED),

       0        // eod
};

void Graph::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Graph *_t = static_cast<Graph *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { GRAPHICTYPE _r = _t->getType();
            if (_a[0]) *reinterpret_cast< GRAPHICTYPE*>(_a[0]) = _r; }  break;
        case 1: _t->setType((*reinterpret_cast< const GRAPHICTYPE(*)>(_a[1]))); break;
        case 2: { int _r = _t->getChanel();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 3: _t->setChanel((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: { QString _r = _t->getTemplateName();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 5: _t->setTemplateName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: { QString _r = _t->getName();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 7: _t->setName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: { int _r = _t->getId();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject Graph::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Graph.data,
      qt_meta_data_Graph,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Graph::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Graph::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Graph.stringdata0))
        return static_cast<void*>(const_cast< Graph*>(this));
    return QObject::qt_metacast(_clname);
}

int Graph::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
