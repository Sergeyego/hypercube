#-------------------------------------------------
#
# Project created by QtCreator 2014-01-20T12:42:07
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = hypercube
TEMPLATE = app


SOURCES += main.cpp \
    olap/axiswidget.cpp \
    olap/cubewidget.cpp \
    olap/cubic.cpp \
    olap/olapmodel.cpp \
    olap/tableview.cpp \
    dialogopen.cpp

HEADERS  += \
    olap/axiswidget.h \
    olap/cubewidget.h \
    olap/cubic.h \
    olap/olapmodel.h \
    olap/tableview.h \
    dialogopen.h

INCLUDEPATH+=/usr/include/xlslib
LIBS+= -lxls

FORMS    += \
    olap/axiswidget.ui \
    olap/cubewidget.ui \
    dialogopen.ui

RC_FILE = app.rc

RESOURCES += \
    res.qrc

DISTFILES += \
    app.rc

