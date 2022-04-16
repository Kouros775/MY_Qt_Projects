QT       += core gui opengl
QT       += 3dcore 3drender 3dinput 3dextras

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MY_Viewer
TEMPLATE = app
DEFINES += QT_DEPRECATED_WARNINGS
CONFIG += c++11

LIBS += -lopengl32

SOURCES += \
    Render/meshmodel.cpp \
    Render/renderbase.cpp \
    Render/renderer.cpp \
        main.cpp \
        mainwindow.cpp \
    Command/icommand.cpp \
    Command/Transform/commandtransformtranslate.cpp \
    Widget/renderwidget.cpp \
    Render/rendercamera.cpp \
    Widget/renderwindow.cpp \
    Widget/modellistwidgetitem.cpp \
    Command/commandloadmodel.cpp \
    Command/commandremovemodel.cpp \
    Command/commandselectlistwidgetitem.cpp \
    Command/commandtorusadd.cpp \
    Document/document.cpp \
    Command/commandeditmodelcolor.cpp

HEADERS += \
    Render/meshmodel.h \
    Render/renderbase.h \
    Render/renderer.h \
        mainwindow.h \
    Command/icommand.h \
    Command/Transform/commandtransformtranslate.h \
    Widget/renderwidget.h \
    Render/rendercamera.h \
    Widget/renderwindow.h \
    Widget/modellistwidgetitem.h \
    Command/commandloadmodel.h \
    Command/commandremovemodel.h \
    Command/commandselectlistwidgetitem.h \
    Command/commandtorusadd.h \
    Document/document.h \
    Command/commandeditmodelcolor.h


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
