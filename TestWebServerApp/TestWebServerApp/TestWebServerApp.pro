QT -= gui
QT += network sql
QT += core

TARGET = TestWebServer

TEMPLATE = app

CONFIG += c++11 console
#CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0



SOURCES += \
        homepagecontroller.cpp \
        main.cpp \
        requestmapper.cpp

HEADERS += \
    GLOBALS.h \
    homepagecontroller.h \
    requestmapper.h

include(../QtWebApp/QtWebApp/httpserver/httpserver.pri)

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



OTHER_FILES += etc/testwebapp.ini
