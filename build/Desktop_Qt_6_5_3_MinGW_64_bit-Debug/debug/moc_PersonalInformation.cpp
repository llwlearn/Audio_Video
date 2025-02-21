/****************************************************************************
** Meta object code from reading C++ file 'PersonalInformation.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/view/PersonalInformation.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PersonalInformation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSPersonalInformationENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSPersonalInformationENDCLASS = QtMocHelpers::stringData(
    "PersonalInformation",
    "personalInformationChanged",
    "",
    "onSaveButtonClicked",
    "onCancelButtonClicked",
    "onYearComboBoxCurrentIndexChanged",
    "index",
    "onProvinceComboBoxCurrentIndexChanged",
    "loadProvinceData"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSPersonalInformationENDCLASS_t {
    uint offsetsAndSizes[18];
    char stringdata0[20];
    char stringdata1[27];
    char stringdata2[1];
    char stringdata3[20];
    char stringdata4[22];
    char stringdata5[34];
    char stringdata6[6];
    char stringdata7[38];
    char stringdata8[17];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSPersonalInformationENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSPersonalInformationENDCLASS_t qt_meta_stringdata_CLASSPersonalInformationENDCLASS = {
    {
        QT_MOC_LITERAL(0, 19),  // "PersonalInformation"
        QT_MOC_LITERAL(20, 26),  // "personalInformationChanged"
        QT_MOC_LITERAL(47, 0),  // ""
        QT_MOC_LITERAL(48, 19),  // "onSaveButtonClicked"
        QT_MOC_LITERAL(68, 21),  // "onCancelButtonClicked"
        QT_MOC_LITERAL(90, 33),  // "onYearComboBoxCurrentIndexCha..."
        QT_MOC_LITERAL(124, 5),  // "index"
        QT_MOC_LITERAL(130, 37),  // "onProvinceComboBoxCurrentInde..."
        QT_MOC_LITERAL(168, 16)   // "loadProvinceData"
    },
    "PersonalInformation",
    "personalInformationChanged",
    "",
    "onSaveButtonClicked",
    "onCancelButtonClicked",
    "onYearComboBoxCurrentIndexChanged",
    "index",
    "onProvinceComboBoxCurrentIndexChanged",
    "loadProvinceData"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSPersonalInformationENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   51,    2, 0x08,    2 /* Private */,
       4,    0,   52,    2, 0x08,    3 /* Private */,
       5,    1,   53,    2, 0x08,    4 /* Private */,
       7,    1,   56,    2, 0x08,    6 /* Private */,
       8,    0,   59,    2, 0x08,    8 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject PersonalInformation::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSPersonalInformationENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSPersonalInformationENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSPersonalInformationENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<PersonalInformation, std::true_type>,
        // method 'personalInformationChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSaveButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onCancelButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onYearComboBoxCurrentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onProvinceComboBoxCurrentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'loadProvinceData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void PersonalInformation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PersonalInformation *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->personalInformationChanged(); break;
        case 1: _t->onSaveButtonClicked(); break;
        case 2: _t->onCancelButtonClicked(); break;
        case 3: _t->onYearComboBoxCurrentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->onProvinceComboBoxCurrentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->loadProvinceData(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PersonalInformation::*)();
            if (_t _q_method = &PersonalInformation::personalInformationChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *PersonalInformation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PersonalInformation::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSPersonalInformationENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int PersonalInformation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void PersonalInformation::personalInformationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
