#-------------------------------------------------
#
# Project created by QtCreator 2017-03-10T11:43:40
#
#-------------------------------------------------

QT       += core gui xml
LIBS     += ../Lib/RDLiveSDK.lib
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DemoFull_QtCreator(Qt4)
TEMPLATE = app

PRECOMPILED_HEADER  = stdafx.h

SOURCES += main.cpp\
        RdLiveSdkDemo.cpp \
    ChipItem.cpp \
    ChipItemOper.cpp \
    CPreViewWnd.cpp \
    CRangeSlider.cpp \
    DlgAddLive.cpp \
    DlgEncoderSetting.cpp \
    RdLiveSdkDemo_menu.cpp

HEADERS  += RdLiveSdkDemo.h \
    ChipItem.h \
    ChipItemOper.h \
    CPreViewWnd.h \
    CRangeSlider.h \
    DlgAddLive.h \
    DlgEncoderSetting.h \
    stdafx.h

FORMS    += RdLiveSdkDemo.ui \
    ChipItem.ui \
    ChipItemOper.ui \
    DlgAddLive.ui \
    DlgEncoderSetting.ui
