#-------------------------------------------------
#
# Project created by QtCreator 2013-06-24T16:24:31
#
#-------------------------------------------------

QT       += core gui\
             xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = Aufgabe_3_2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    typewindow.cpp \
    xmlstreamreader.cpp \
    person.cpp \
    highscore.cpp\
    qcustomplot.cpp \
    testwidget.cpp

HEADERS  += mainwindow.h \
    typewindow.h \
    xmlstreamreader.h \
    person.h \
    highscore.h\
    qcustomplot.h \
    testwidget.h

FORMS    += mainwindow.ui \
    typewindow.ui \
    highscore.ui

QTPLUGIN += qsqlmysql


RESOURCES += \
    testPfad.qrc



