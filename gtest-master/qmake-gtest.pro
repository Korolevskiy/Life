TEMPLATE = subdirs

CONFIG -= app_bundle
CONFIG += qt

QT  += widgets

QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage -O0

SUBDIRS = app tests

CONFIG += ordered
