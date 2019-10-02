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


SOURCES += main.cpp\
        cubewidget.cpp \
    olapmodel.cpp \
    cubic.cpp \
    axiswidget.cpp \
    viewer.cpp

HEADERS  += cubewidget.h \
    olapmodel.h \
    cubic.h \
    axiswidget.h \
    viewer.h

INCLUDEPATH+=/usr/include/xlslib
LIBS+= -lxls

FORMS    += cubewidget.ui \
    axiswidget.ui

RC_FILE = app.rc

RESOURCES += \
    res.qrc

DISTFILES += \
    configs/Выпуск/profr.txt \
    configs/Зарплата_электроды/profr.txt \
    configs/Количество_прокалок/profr.txt \
    configs/Нормы_3_цех/profr.txt \
    configs/Поступление_электродов_на_склад/profr.txt \
    configs/Производство_проволоки/profr.txt \
    configs/Прокалка_электродов/profr.txt \
    configs/Расход_компонентов/profr.txt \
    configs/Расход_сырья/profr.txt \
    configs/Расход_энергии_на_прокалку/profr.txt \
    configs/Упаковка/profr.txt \
    configs/Упаковка_зп/profr.txt

