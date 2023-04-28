QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    MouseMacro/clickthread.cpp \
    MouseMacro/keycontrollerthread.cpp \
    MouseMacro/mousemacrowidget.cpp \
    haluoshow.cpp \
    haluoshowlabel.cpp \
    main.cpp \
    haluo.cpp \
    menuwidget.cpp \
    music/musicwidget.cpp \
    note/notewidget.cpp

HEADERS += \
    MouseMacro/clickthread.h \
    MouseMacro/keycontrollerthread.h \
    MouseMacro/mousemacrowidget.h \
    haluo.h \
    haluoshow.h \
    haluoshowlabel.h \
    menuwidget.h \
    music/musicwidget.h \
    note/notewidget.h

FORMS += \
    haluo.ui \
    haluoshow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
