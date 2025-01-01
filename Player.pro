QT       += core gui multimedia multimediawidgets sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    MainWindow.cpp \
    main.cpp \
    src/tool/CustomScrollArea.cpp \
    src/tool/Database.cpp \
    src/tool/EventFilter.cpp \
    src/tool/Interface.cpp \
    src/tool/window_customization.cpp \
    src/view/Login.cpp \
    src/view/PurchaseMembership.cpp \
    src/view/Recommend.cpp \
    src/view/SearchFor.cpp \
    src/view/UserInfo.cpp

HEADERS += \
    MainWindow.h \
    src/tool/CustomScrollArea.h \
    src/tool/Database.h \
    src/tool/EventFilter.h \
    src/tool/Interface.h \
    src/tool/window_customization.h \
    src/view/Login.h \
    src/view/PurchaseMembership.h \
    src/view/Recommend.h \
    src/view/SearchFor.h \
    src/view/UserInfo.h

FORMS += \
    MainWindow.ui \
    src/view/Login.ui \
    src/view/PurchaseMembership.ui \
    src/view/Recommend.ui \
    src/view/SearchFor.ui \
    src/view/UserInfo.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    src/img/img.qrc
    qt.conf
