#-------------------------------------------------
#
# Project created by QtCreator 2017-12-24T14:41:23
#
#-------------------------------------------------

QT       += core gui
QT       += widgets
QT       += xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DragonCreator
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

CONFIG += static

SOURCES += \
    src/core/main.cpp \
    src/ui/mainwindow.cpp \
    src/core/moduleeditor.cpp \
    src/core/edit/itemeditor.cpp \
    src/core/config.cpp \
    src/util/text/textreader.cpp \
    src/util/engine.cpp \
    src/core/edit/weaponseditor.cpp \
    src/ui/widgets/weaponseditorwidget.cpp \
    src/core/data/object/item/weapon.cpp \
    src/core/data/dconnector.cpp \
    src/core/edit/xml/qxmleditor.cpp \
    src/core/edit/xml/parser/itemparser.cpp \
    src/core/data/object/modifier.cpp \
    src/core/edit/xml/parser/modifierparser.cpp \
    src/core/edit/baseeditor.cpp \
    src/ui/widgets/newmoddifierdialog.cpp \
    src/util/modifierutils.cpp \
    src/ui/lang.cpp \
    src/ui/widgets/welcomewidget.cpp \
    src/ui/widgets/moduleinfowidget.cpp \
    src/core/data/object/module.cpp

HEADERS += \
    src/ui/mainwindow.h \
    src/core/moduleeditor.h \
    src/core/edit/itemeditor.h \
    src/core/config.h \
    src/util/text/textreader.h \
    src/util/engine.h \
    src/core/edit/weaponseditor.h \
    src/ui/widgets/weaponseditorwidget.h \
    src/core/data/object/item/weapon.h \
    src/core/data/dconnector.h \
    src/core/edit/xml/qxmleditor.h \
    src/core/edit/xml/parser/itemparser.h \
    src/core/data/object/modifier.h \
    src/core/edit/xml/parser/modifierparser.h \
    src/core/edit/baseeditor.h \
    src/ui/widgets/newmoddifierdialog.h \
    src/util/modifierutils.h \
    src/ui/lang.h \
    src/ui/widgets/welcomewidget.h \
    src/ui/widgets/moduleinfowidget.h \
    src/core/data/object/module.h

FORMS += \
    src/ui/forms/mainwindow.ui \
    src/ui/forms/weaponseditorwidget.ui \
    src/ui/forms/newmoddifierdialog.ui \
    src/ui/forms/welcomewidget.ui \
    src/ui/forms/moduleinfowidget.ui

SUBDIRS += \
    DragonCreator.pro

RESOURCES +=
