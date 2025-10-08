QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    authregform.cpp \
    functionsforclient.cpp \
    main.cpp \
    mainwindow.cpp \
    stat_window.cpp \
    task1_vigenere.cpp \
    task2_bisection.cpp

HEADERS += \
    authregform.h \
    functionsforclient.h \
    mainwindow.h \
    stat_window.h \
    task1_vigenere.h \
    task2_bisection.h

FORMS += \
    authregform.ui \
    mainwindow.ui \
    stat_window.ui \
    task1_vigenere.ui \
    task2_bisection.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target