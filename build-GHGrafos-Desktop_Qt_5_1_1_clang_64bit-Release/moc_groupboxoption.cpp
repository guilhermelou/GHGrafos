/****************************************************************************
** Meta object code from reading C++ file 'groupboxoption.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GHGrafos/groupboxoption.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'groupboxoption.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GroupBoxOption_t {
    QByteArrayData data[21];
    char stringdata[473];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_GroupBoxOption_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_GroupBoxOption_t qt_meta_stringdata_GroupBoxOption = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 21),
QT_MOC_LITERAL(2, 37, 0),
QT_MOC_LITERAL(3, 38, 23),
QT_MOC_LITERAL(4, 62, 22),
QT_MOC_LITERAL(5, 85, 15),
QT_MOC_LITERAL(6, 101, 18),
QT_MOC_LITERAL(7, 120, 18),
QT_MOC_LITERAL(8, 139, 22),
QT_MOC_LITERAL(9, 162, 32),
QT_MOC_LITERAL(10, 195, 4),
QT_MOC_LITERAL(11, 200, 32),
QT_MOC_LITERAL(12, 233, 24),
QT_MOC_LITERAL(13, 258, 26),
QT_MOC_LITERAL(14, 285, 25),
QT_MOC_LITERAL(15, 311, 18),
QT_MOC_LITERAL(16, 330, 21),
QT_MOC_LITERAL(17, 352, 21),
QT_MOC_LITERAL(18, 374, 25),
QT_MOC_LITERAL(19, 400, 35),
QT_MOC_LITERAL(20, 436, 35)
    },
    "GroupBoxOption\0btndeepsearch_clicked\0"
    "\0btnbreadhsearch_clicked\0"
    "btnconectivity_clicked\0btnprim_clicked\0"
    "btnkruskal_clicked\0btndjkstra_clicked\0"
    "btnbellmanford_clicked\0"
    "cbxstartnode_currentIndexChanged\0arg1\0"
    "cbxfinalnode_currentIndexChanged\0"
    "on_btndeepsearch_clicked\0"
    "on_btnbreadhsearch_clicked\0"
    "on_btnconectivity_clicked\0on_btnprim_clicked\0"
    "on_btnkruskal_clicked\0on_btndjkstra_clicked\0"
    "on_btnbellmanford_clicked\0"
    "on_cbxstartnode_currentIndexChanged\0"
    "on_cbxfinalnode_currentIndexChanged\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GroupBoxOption[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x05,
       3,    0,  105,    2, 0x05,
       4,    0,  106,    2, 0x05,
       5,    0,  107,    2, 0x05,
       6,    0,  108,    2, 0x05,
       7,    0,  109,    2, 0x05,
       8,    0,  110,    2, 0x05,
       9,    1,  111,    2, 0x05,
      11,    1,  114,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
      12,    0,  117,    2, 0x08,
      13,    0,  118,    2, 0x08,
      14,    0,  119,    2, 0x08,
      15,    0,  120,    2, 0x08,
      16,    0,  121,    2, 0x08,
      17,    0,  122,    2, 0x08,
      18,    0,  123,    2, 0x08,
      19,    1,  124,    2, 0x08,
      20,    1,  127,    2, 0x08,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   10,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   10,

       0        // eod
};

void GroupBoxOption::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GroupBoxOption *_t = static_cast<GroupBoxOption *>(_o);
        switch (_id) {
        case 0: _t->btndeepsearch_clicked(); break;
        case 1: _t->btnbreadhsearch_clicked(); break;
        case 2: _t->btnconectivity_clicked(); break;
        case 3: _t->btnprim_clicked(); break;
        case 4: _t->btnkruskal_clicked(); break;
        case 5: _t->btndjkstra_clicked(); break;
        case 6: _t->btnbellmanford_clicked(); break;
        case 7: _t->cbxstartnode_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->cbxfinalnode_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->on_btndeepsearch_clicked(); break;
        case 10: _t->on_btnbreadhsearch_clicked(); break;
        case 11: _t->on_btnconectivity_clicked(); break;
        case 12: _t->on_btnprim_clicked(); break;
        case 13: _t->on_btnkruskal_clicked(); break;
        case 14: _t->on_btndjkstra_clicked(); break;
        case 15: _t->on_btnbellmanford_clicked(); break;
        case 16: _t->on_cbxstartnode_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 17: _t->on_cbxfinalnode_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GroupBoxOption::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GroupBoxOption::btndeepsearch_clicked)) {
                *result = 0;
            }
        }
        {
            typedef void (GroupBoxOption::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GroupBoxOption::btnbreadhsearch_clicked)) {
                *result = 1;
            }
        }
        {
            typedef void (GroupBoxOption::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GroupBoxOption::btnconectivity_clicked)) {
                *result = 2;
            }
        }
        {
            typedef void (GroupBoxOption::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GroupBoxOption::btnprim_clicked)) {
                *result = 3;
            }
        }
        {
            typedef void (GroupBoxOption::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GroupBoxOption::btnkruskal_clicked)) {
                *result = 4;
            }
        }
        {
            typedef void (GroupBoxOption::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GroupBoxOption::btndjkstra_clicked)) {
                *result = 5;
            }
        }
        {
            typedef void (GroupBoxOption::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GroupBoxOption::btnbellmanford_clicked)) {
                *result = 6;
            }
        }
        {
            typedef void (GroupBoxOption::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GroupBoxOption::cbxstartnode_currentIndexChanged)) {
                *result = 7;
            }
        }
        {
            typedef void (GroupBoxOption::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GroupBoxOption::cbxfinalnode_currentIndexChanged)) {
                *result = 8;
            }
        }
    }
}

const QMetaObject GroupBoxOption::staticMetaObject = {
    { &QGroupBox::staticMetaObject, qt_meta_stringdata_GroupBoxOption.data,
      qt_meta_data_GroupBoxOption,  qt_static_metacall, 0, 0}
};


const QMetaObject *GroupBoxOption::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GroupBoxOption::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GroupBoxOption.stringdata))
        return static_cast<void*>(const_cast< GroupBoxOption*>(this));
    return QGroupBox::qt_metacast(_clname);
}

int GroupBoxOption::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGroupBox::qt_metacall(_c, _id, _a);
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
void GroupBoxOption::btndeepsearch_clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void GroupBoxOption::btnbreadhsearch_clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void GroupBoxOption::btnconectivity_clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void GroupBoxOption::btnprim_clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void GroupBoxOption::btnkruskal_clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void GroupBoxOption::btndjkstra_clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void GroupBoxOption::btnbellmanford_clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void GroupBoxOption::cbxstartnode_currentIndexChanged(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void GroupBoxOption::cbxfinalnode_currentIndexChanged(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_END_MOC_NAMESPACE
