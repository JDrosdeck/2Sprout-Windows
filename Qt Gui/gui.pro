# -------------------------------------------------
# Project created by QtCreator 2009-06-27T17:30:19
# -------------------------------------------------
TARGET = 2sprout
TEMPLATE = app
RESOURCES = icons.qrc
RC_FILE = app.rc
SOURCES += main.cpp \
    mainwindow.cpp \
    database.cpp \
    network.cpp \
    developer.cpp
HEADERS += mainwindow.h \
    database.h \
    network.h \
    developer.h
FORMS += mainwindow.ui \
    database.ui \
    network.ui \
    developer.ui

mystaticconfig{
    QMAKE_LIBS_QT =
LIBS += /usr/local/TrollTech/Qt-4.6.0/lib/libQtCore.a
LIBS += /usr/local/TrollTech/Qt-4.6.0/lib/libQtGui.a -lz -framework Carbon
}
