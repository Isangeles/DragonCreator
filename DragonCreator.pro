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

#INCLUDEPATH += lib/zipios/include
#INCLUDEPATH += lib/zipios/lib64
#LIBS += -L"lib/zipios/lib64" -lzipios

SOURCES += \
    src/core/data/object/item/weapon.cpp \
    src/core/data/object/modifier.cpp \
    src/core/data/object/module.cpp \
    src/core/data/dconnector.cpp \
    src/core/edit/xml/parser/itemparser.cpp \
    src/core/edit/xml/parser/modifierparser.cpp \
    src/core/edit/xml/qxmleditor.cpp \
    src/core/edit/zip/zipeditor.cpp \
    src/core/edit/baseeditor.cpp \
    src/core/edit/itemeditor.cpp \
    src/core/edit/weaponseditor.cpp \
    src/core/config.cpp \
    src/core/main.cpp \
    src/core/moduleeditor.cpp \
    src/ui/widgets/moduleinfowidget.cpp \
    src/ui/widgets/newmoddifierdialog.cpp \
    src/ui/widgets/weaponseditorwidget.cpp \
    src/ui/widgets/welcomewidget.cpp \
    src/ui/lang.cpp \
    src/ui/mainwindow.cpp \
    src/util/text/textreader.cpp \
    src/util/engine.cpp \
    src/util/modifierutils.cpp \
    src/util/weaponutils.cpp \
    src/ui/widgets/settingswidget.cpp \
    src/core/data/tconnector.cpp \
    src/core/data/object/effect.cpp \
    src/ui/widgets/effectseditorwidget.cpp \
    src/core/edit/effectseditor.cpp \
    src/core/edit/xml/parser/effectparser.cpp \
    src/util/effectutils.cpp \
    src/ui/util/modifierlistitem.cpp \
    src/core/data/object/baseobject.cpp \
    src/ui/util/baseobjectlistitem.cpp \
    src/ui/widgets/addeffectdialog.cpp \
    src/core/data/object/requirement.cpp \
    src/util/requirementutils.cpp \
    src/core/edit/xml/parser/requirementparser.cpp \
    src/ui/widgets/newrequirementdialog.cpp

HEADERS += \
    src/core/data/object/item/weapon.h \
    src/core/data/object/modifier.h \
    src/core/data/object/module.h \
    src/core/data/dconnector.h \
    src/core/edit/xml/parser/itemparser.h \
    src/core/edit/xml/parser/modifierparser.h \
    src/core/edit/xml/qxmleditor.h \
    src/core/edit/zip/zipeditor.h \
    src/core/edit/baseeditor.h \
    src/core/edit/itemeditor.h \
    src/core/edit/weaponseditor.h \
    src/core/config.h \
    src/core/moduleeditor.h \
    src/ui/widgets/moduleinfowidget.h \
    src/ui/widgets/newmoddifierdialog.h \
    src/ui/widgets/weaponseditorwidget.h \
    src/ui/widgets/welcomewidget.h \
    src/ui/lang.h \
    src/ui/mainwindow.h \
    src/util/text/textreader.h \
    src/util/engine.h \
    src/util/modifierutils.h \
    src/util/weaponutils.h \
    src/ui/widgets/settingswidget.h \
    src/core/data/tconnector.h \
    src/core/data/object/effect.h \
    src/ui/widgets/effectseditorwidget.h \
    src/core/edit/effectseditor.h \
    src/core/edit/xml/parser/effectparser.h \
    src/util/effectutils.h \
    src/ui/util/modifierlistitem.h \
    src/core/data/object/baseobject.h \
    src/ui/util/baseobjectlistitem.h \
    src/ui/widgets/addeffectdialog.h \
    src/core/data/object/requirement.h \
    src/core/data/object/requirement.h \
    src/util/requirementutils.h \
    src/core/edit/xml/parser/requirementparser.h \
    src/ui/widgets/newrequirementdialog.h

FORMS += \
    src/ui/forms/mainwindow.ui \
    src/ui/forms/moduleinfowidget.ui \
    src/ui/forms/newmoddifierdialog.ui \
    src/ui/forms/weaponseditorwidget.ui \
    src/ui/forms/welcomewidget.ui \
    src/ui/forms/settingswidget.ui \
    src/ui/forms/effectseditorwidget.ui \
    src/ui/forms/addeffectdialog.ui \
    src/ui/forms/newrequirementdialog.ui

SUBDIRS += \
    DragonCreator.pro

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/zipios/lib64/release/ -lzipios
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/zipios/lib64/debug/ -lzipios
else:unix: LIBS += -L$$PWD/lib/zipios/lib64/ -lzipios

INCLUDEPATH += $$PWD/lib/zipios/include
DEPENDPATH += $$PWD/lib/zipios/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/quazip/lib/release/ -lquazip
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/quazip/lib/debug/ -lquazip
else:unix: LIBS += -L$$PWD/lib/quazip/lib/ -lquazip

INCLUDEPATH += $$PWD/lib/quazip/include
DEPENDPATH += $$PWD/lib/quazip/include
