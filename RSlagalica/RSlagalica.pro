#-------------------------------------------------
#
# Project created by QtCreator 2017-05-26T13:00:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RSlagalica
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


SOURCES += \
    src/main.cpp\
    src/mainwindow.cpp \
    src/game.cpp \
    src/level.cpp \
    src/levellongestword.cpp \
    src/levelmynumber.cpp \
    src/levelassociations.cpp \
    src/expressionelementnode.cpp \
    src/numericelementnode.cpp \
    src/binaryoperationnode.cpp \
    src/binaryexpressionbuilder.cpp \
    src/levelconnections.cpp

HEADERS  += \
    headers/mainwindow.h \
    headers/game.h \
    headers/level.h \
    headers/levellongestword.h \
    headers/levelmynumber.h \
    headers/levelassociations.h \
    headers/expressionelementnode.h \
    headers/numericelementnode.h \
    headers/binaryoperationnode.h \
    headers/binaryexpressionbuilder.h \
    headers/levelconnections.h

FORMS    += \
    ui/mainwindow.ui

RESOURCES += \
    resources/images/images.qrc \
    resources/dictionaries/dictionaries.qrc \
    resources/games_data/games_data.qrc \
    src/connectors_tests.qrc

DISTFILES +=




QMAKE_CXXFLAGS+= -std=c++11
CONFIG+= c++11
