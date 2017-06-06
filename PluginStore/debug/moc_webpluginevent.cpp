/****************************************************************************
** Meta object code from reading C++ file 'webpluginevent.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../webpluginevent.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'webpluginevent.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PluginItem_t {
    QByteArrayData data[6];
    char stringdata0[85];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PluginItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PluginItem_t qt_meta_stringdata_PluginItem = {
    {
QT_MOC_LITERAL(0, 0, 10), // "PluginItem"
QT_MOC_LITERAL(1, 11, 24), // "on_web_downfile_progress"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 10), // "qiRecvSize"
QT_MOC_LITERAL(4, 48, 11), // "qiTotalSize"
QT_MOC_LITERAL(5, 60, 24) // "on_web_downfile_finished"

    },
    "PluginItem\0on_web_downfile_progress\0"
    "\0qiRecvSize\0qiTotalSize\0"
    "on_web_downfile_finished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PluginItem[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x0a /* Public */,
       5,    0,   29,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,    3,    4,
    QMetaType::Void,

       0        // eod
};

void PluginItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PluginItem *_t = static_cast<PluginItem *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_web_downfile_progress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 1: _t->on_web_downfile_finished(); break;
        default: ;
        }
    }
}

const QMetaObject PluginItem::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PluginItem.data,
      qt_meta_data_PluginItem,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PluginItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PluginItem::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PluginItem.stringdata0))
        return static_cast<void*>(const_cast< PluginItem*>(this));
    return QObject::qt_metacast(_clname);
}

int PluginItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
struct qt_meta_stringdata_WebPluginEvent_t {
    QByteArrayData data[24];
    char stringdata0[344];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WebPluginEvent_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WebPluginEvent_t qt_meta_stringdata_WebPluginEvent = {
    {
QT_MOC_LITERAL(0, 0, 14), // "WebPluginEvent"
QT_MOC_LITERAL(1, 15, 13), // "DownLoadState"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 11), // "strPluginID"
QT_MOC_LITERAL(4, 42, 13), // "iDownLoadSize"
QT_MOC_LITERAL(5, 56, 10), // "iTotalSize"
QT_MOC_LITERAL(6, 67, 18), // "GetLocalPluginList"
QT_MOC_LITERAL(7, 86, 21), // "GetLocalPluginVersion"
QT_MOC_LITERAL(8, 108, 17), // "DownLoadPluginUrl"
QT_MOC_LITERAL(9, 126, 5), // "param"
QT_MOC_LITERAL(10, 132, 13), // "InstallPlugin"
QT_MOC_LITERAL(11, 146, 15), // "UninstallPlugin"
QT_MOC_LITERAL(12, 162, 16), // "RemoveFilePlugin"
QT_MOC_LITERAL(13, 179, 23), // "GetCurrentSaveDirectory"
QT_MOC_LITERAL(14, 203, 19), // "SetNewSaveDirectory"
QT_MOC_LITERAL(15, 223, 12), // "strDirectory"
QT_MOC_LITERAL(16, 236, 7), // "OpenUrl"
QT_MOC_LITERAL(17, 244, 3), // "url"
QT_MOC_LITERAL(18, 248, 20), // "SetDownloadPluginDir"
QT_MOC_LITERAL(19, 269, 20), // "on_web_load_finished"
QT_MOC_LITERAL(20, 290, 2), // "ok"
QT_MOC_LITERAL(21, 293, 21), // "on_web_downfile_start"
QT_MOC_LITERAL(22, 315, 23), // "QWebEngineDownloadItem*"
QT_MOC_LITERAL(23, 339, 4) // "item"

    },
    "WebPluginEvent\0DownLoadState\0\0strPluginID\0"
    "iDownLoadSize\0iTotalSize\0GetLocalPluginList\0"
    "GetLocalPluginVersion\0DownLoadPluginUrl\0"
    "param\0InstallPlugin\0UninstallPlugin\0"
    "RemoveFilePlugin\0GetCurrentSaveDirectory\0"
    "SetNewSaveDirectory\0strDirectory\0"
    "OpenUrl\0url\0SetDownloadPluginDir\0"
    "on_web_load_finished\0ok\0on_web_downfile_start\0"
    "QWebEngineDownloadItem*\0item"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WebPluginEvent[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   86,    2, 0x0a /* Public */,
       7,    1,   87,    2, 0x0a /* Public */,
       8,    1,   90,    2, 0x0a /* Public */,
      10,    1,   93,    2, 0x0a /* Public */,
      11,    1,   96,    2, 0x0a /* Public */,
      12,    1,   99,    2, 0x0a /* Public */,
      13,    0,  102,    2, 0x0a /* Public */,
      14,    1,  103,    2, 0x0a /* Public */,
      16,    1,  106,    2, 0x0a /* Public */,
      18,    0,  109,    2, 0x0a /* Public */,
      19,    1,  110,    2, 0x0a /* Public */,
      21,    1,  113,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::LongLong, QMetaType::LongLong,    3,    4,    5,

 // slots: parameters
    QMetaType::QVariant,
    QMetaType::QString, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QVariantMap,    9,
    QMetaType::QString, QMetaType::QVariant,    9,
    QMetaType::QString, QMetaType::QVariant,    9,
    QMetaType::QString, QMetaType::QVariant,    9,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::QString,
    QMetaType::Void, QMetaType::Bool,   20,
    QMetaType::Void, 0x80000000 | 22,   23,

       0        // eod
};

void WebPluginEvent::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WebPluginEvent *_t = static_cast<WebPluginEvent *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->DownLoadState((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])),(*reinterpret_cast< qint64(*)>(_a[3]))); break;
        case 1: { QVariant _r = _t->GetLocalPluginList();
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 2: { QString _r = _t->GetLocalPluginVersion((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 3: _t->DownLoadPluginUrl((*reinterpret_cast< const QVariantMap(*)>(_a[1]))); break;
        case 4: { QString _r = _t->InstallPlugin((*reinterpret_cast< const QVariant(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 5: { QString _r = _t->UninstallPlugin((*reinterpret_cast< const QVariant(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 6: { QString _r = _t->RemoveFilePlugin((*reinterpret_cast< const QVariant(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 7: { QString _r = _t->GetCurrentSaveDirectory();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 8: _t->SetNewSaveDirectory((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->OpenUrl((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: { QString _r = _t->SetDownloadPluginDir();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 11: _t->on_web_load_finished((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->on_web_downfile_start((*reinterpret_cast< QWebEngineDownloadItem*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWebEngineDownloadItem* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WebPluginEvent::*_t)(QString , qint64 , qint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WebPluginEvent::DownLoadState)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject WebPluginEvent::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_WebPluginEvent.data,
      qt_meta_data_WebPluginEvent,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *WebPluginEvent::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WebPluginEvent::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_WebPluginEvent.stringdata0))
        return static_cast<void*>(const_cast< WebPluginEvent*>(this));
    return QObject::qt_metacast(_clname);
}

int WebPluginEvent::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void WebPluginEvent::DownLoadState(QString _t1, qint64 _t2, qint64 _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
