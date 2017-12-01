#-------------------------------------------------
#
# Project created by QtCreator 2017-01-23T11:12:57
#
#-------------------------------------------------

QT       += core gui bluetooth

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SwarmDebug
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    datathread.cpp \
    machinevision.cpp \
    visualiser.cpp \
    cameracontroller.cpp \
    datamodel.cpp \
    robotdata.cpp \
    util.cpp \
    settings.cpp \
    visconfig.cpp \
    visposition.cpp \
    visdirection.cpp \
    visname.cpp \
    visstate.cpp \
    visproximity.cpp \
    irdataview.cpp \
    vispath.cpp \
    proximitysettingsdialog.cpp \
    pathsettingsdialog.cpp \
    visid.cpp \
    idsettingsdialog.cpp \
    log.cpp \
    namesettingsdialog.cpp \
    statesettingsdialog.cpp \
    viscustom.cpp \
    customsettingsdialog.cpp \
    testingwindow.cpp \
    addidmappingdialog.cpp \
    robotinfodialog.cpp \
    bluetoothdatathread.cpp

HEADERS  += mainwindow.h \
    datathread.h \
    machinevision.h \
    visualiser.h \
    appconfig.h \
    cameracontroller.h \
    datamodel.h \
    robotdata.h \
    util.h \
    settings.h \
    visconfig.h \
    viselement.h \
    visposition.h \
    visdirection.h \
    visname.h \
    visstate.h \
    visproximity.h \
    irdataview.h \
    vispath.h \
    proximitysettingsdialog.h \
    pathsettingsdialog.h \
    visid.h \
    idsettingsdialog.h \
    log.h \
    namesettingsdialog.h \
    statesettingsdialog.h \
    viscustom.h \
    customsettingsdialog.h \
    testingwindow.h \
    addidmappingdialog.h \
    robotinfodialog.h \
    bluetoothdatathread.h

FORMS    += mainwindow.ui

CONFIG += link_pkgconfig \
    c++11
PKGCONFIG += opencv


#LIBS += -L/opt/cvb/lib/ -lCVCImg
#LIBS += -L/opt/cvb/lib/ -lCVCDriver
#LIBS += -L/opt/cvb/lib/ -lCVCUtilities

INCLUDEPATH += /opt/cvb/include
DEPENDPATH += /opt/cvb/include
