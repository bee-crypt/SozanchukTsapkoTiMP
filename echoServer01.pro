QT += core network

CONFIG += c++11 console
CONFIG -= app_bundle

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    main.cpp \
    mytcpserver.cpp

HEADERS += \
    mytcpserver.h

# Убедитесь, что нет других SOURCES или HEADERS
