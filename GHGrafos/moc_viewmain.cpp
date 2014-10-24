/****************************************************************************
** Meta object code from reading C++ file 'viewmain.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "viewmain.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'viewmain.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ViewMain_t {
    QByteArrayData data[24];
    char stringdata[269];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ViewMain_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ViewMain_t qt_meta_stringdata_ViewMain = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 9),
QT_MOC_LITERAL(2, 19, 0),
QT_MOC_LITERAL(3, 20, 12),
QT_MOC_LITERAL(4, 33, 5),
QT_MOC_LITERAL(5, 39, 10),
QT_MOC_LITERAL(6, 50, 12),
QT_MOC_LITERAL(7, 63, 6),
QT_MOC_LITERAL(8, 70, 13),
QT_MOC_LITERAL(9, 84, 15),
QT_MOC_LITERAL(10, 100, 12),
QT_MOC_LITERAL(11, 113, 11),
QT_MOC_LITERAL(12, 125, 10),
QT_MOC_LITERAL(13, 136, 15),
QT_MOC_LITERAL(14, 152, 12),
QT_MOC_LITERAL(15, 165, 11),
QT_MOC_LITERAL(16, 177, 4),
QT_MOC_LITERAL(17, 182, 7),
QT_MOC_LITERAL(18, 190, 7),
QT_MOC_LITERAL(19, 198, 11),
QT_MOC_LITERAL(20, 210, 18),
QT_MOC_LITERAL(21, 229, 16),
QT_MOC_LITERAL(22, 246, 4),
QT_MOC_LITERAL(23, 251, 16)
    },
    "ViewMain\0mouseMove\0\0QMouseEvent*\0event\0"
    "mousePress\0mouseRelease\0resize\0"
    "QResizeEvent*\0topologicalSort\0"
    "checkBarrier\0openNewFile\0deepsearch\0"
    "deepsearchcolor\0breadhsearch\0conectivity\0"
    "prim\0kruskal\0djkstra\0bellmanford\0"
    "generateTransposed\0startNodeChanged\0"
    "arg1\0finalNodeChanged\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ViewMain[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  104,    2, 0x05,
       5,    1,  107,    2, 0x05,
       6,    1,  110,    2, 0x05,
       7,    1,  113,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       9,    0,  116,    2, 0x0a,
      10,    0,  117,    2, 0x0a,
      11,    0,  118,    2, 0x0a,
      12,    0,  119,    2, 0x0a,
      13,    0,  120,    2, 0x0a,
      14,    0,  121,    2, 0x0a,
      15,    0,  122,    2, 0x0a,
      16,    0,  123,    2, 0x0a,
      17,    0,  124,    2, 0x0a,
      18,    0,  125,    2, 0x0a,
      19,    0,  126,    2, 0x0a,
      20,    0,  127,    2, 0x0a,
      21,    1,  128,    2, 0x0a,
      23,    1,  131,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 8,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   22,
    QMetaType::Void, QMetaType::QString,   22,

       0        // eod
};

void ViewMain::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ViewMain *_t = static_cast<ViewMain *>(_o);
        switch (_id) {
        case 0: _t->mouseMove((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 1: _t->mousePress((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 2: _t->mouseRelease((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 3: _t->resize((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        case 4: _t->topologicalSort(); break;
        case 5: _t->checkBarrier(); break;
        case 6: _t->openNewFile(); break;
        case 7: _t->deepsearch(); break;
        case 8: _t->deepsearchcolor(); break;
        case 9: _t->breadhsearch(); break;
        case 10: _t->conectivity(); break;
        case 11: _t->prim(); break;
        case 12: _t->kruskal(); break;
        case 13: _t->djkstra(); break;
        case 14: _t->bellmanford(); break;
        case 15: _t->generateTransposed(); break;
        case 16: _t->startNodeChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 17: _t->finalNodeChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ViewMain::*_t)(QMouseEvent * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ViewMain::mouseMove)) {
                *result = 0;
            }
        }
        {
            typedef void (ViewMain::*_t)(QMouseEvent * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ViewMain::mousePress)) {
                *result = 1;
            }
        }
        {
            typedef void (ViewMain::*_t)(QMouseEvent * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ViewMain::mouseRelease)) {
                *result = 2;
            }
        }
        {
            typedef void (ViewMain::*_t)(QResizeEvent * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ViewMain::resize)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject ViewMain::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ViewMain.data,
      qt_meta_data_ViewMain,  qt_static_metacall, 0, 0}
};


const QMetaObject *ViewMain::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ViewMain::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ViewMain.stringdata))
        return static_cast<void*>(const_cast< ViewMain*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ViewMain::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void ViewMain::mouseMove(QMouseEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ViewMain::mousePress(QMouseEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ViewMain::mouseRelease(QMouseEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ViewMain::resize(QResizeEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
