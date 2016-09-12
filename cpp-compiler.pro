TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    lexicalanalyzer.cpp \
    symbolstable.cpp \
    entry.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    lexicalanalyzer.h \
    symbolstable.h \
    constants.h \
    entry.h

