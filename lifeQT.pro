QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lifeQT
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    liferect.cpp

HEADERS  += widget.h \
    liferect.h

FORMS    += widget.ui

