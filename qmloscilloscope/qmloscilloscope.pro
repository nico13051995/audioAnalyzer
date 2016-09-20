TEMPLATE = app

QT += core gui widgets charts qml quick

RESOURCES += resources.qrc
SOURCES += main.cpp \
           datasource.cpp
OTHER_FILES += qml/qmloscilloscope/*

HEADERS += \
    datasource.h
