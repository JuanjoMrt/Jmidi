#-------------------------------------------------
#
# Project created by QtCreator 2019-06-13T21:18:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Jmidi
TEMPLATE = app
INCLUDEPATH += .

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        select_note_dialog.cpp \
        select_rest_widget.cpp \
        src/* \
        src/gradual_tremolo_dialog.cpp \
        ui/tremolo_dialog.cpp

HEADERS += \
        header/* \
        select_note_dialog.h \
        select_rest_widget.h \
        src/gradual_tremolo_dialog.h \
        ui/tremolo_dialog.h

FORMS += \
        select_instrument_dialog.ui \
        select_note_dialog.ui \
        select_rest_widget.ui \
        src/gradual_tremolo_dialog.ui \
        ui/* \
        ui/tremolo_dialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ui/icons/quarter-note.qrc \
    ui/resources.qrc
