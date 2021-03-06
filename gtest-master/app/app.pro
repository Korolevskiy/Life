TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += qt

QT += widgets

SOURCES += main.cpp \
    liferect.cpp \
    widget.cpp

HEADERS += \
    liferect.h \
    widget.h \
    ui_widget.h

QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov
