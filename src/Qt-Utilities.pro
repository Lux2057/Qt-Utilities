QT += quick quickcontrols2 multimedia

CONFIG += c++17 embed_translations

DEFINES += QT_DEPRECATED_WARNINGSs

SOURCES += main.cpp \

RESOURCES += qml.qrc \    

include(Utilities/Utilities.pri)
include(Samples/Samples.pri)
