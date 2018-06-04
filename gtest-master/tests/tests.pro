include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG += thread

QT += widgets

QMAKE_CXXFLAGS += -Wall -Wextra -Werror
QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov


HEADERS +=     tst_test1.h \
    fibonachi_test.h \
    ../app/liferect.h \
    ../app/widget.h \
    ../app/ui_widget.h

SOURCES +=     main.cpp \
    ../app/liferect.cpp \
    ../app/widget.cpp

INCLUDEPATH += ../app
