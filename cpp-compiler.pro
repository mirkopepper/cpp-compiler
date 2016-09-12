TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    lexicalanalizer.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    lexicalanalizer.h

