TEMPLATE = subdirs

CONFIG -= app_bundle
CONFIG += qt

QT  += widgets

QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage -O0 -std=c++0x

SUBDIRS = app tests

CONFIG += ordered
