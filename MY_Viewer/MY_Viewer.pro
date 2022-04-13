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
        mdimainwindow.cpp \
    Command/icommand.cpp \
    Command/Transform/commandtransformtranslate.cpp \
    Command/Transform/commandtransform.cpp \
    Command/Transform/commandtransformrotate.cpp \
    Command/Transform/commandtransformscale.cpp \
    Widget/renderwidget.cpp \
    Render/rendercamera.cpp \
    Widget/renderwindow.cpp \
    Document/modeldocument.cpp

HEADERS += \
    Render/meshmodel.h \
    Render/renderbase.h \
    Render/renderer.h \
        mainwindow.h \
        mdimainwindow.h \
    Command/icommand.h \
    Command/Transform/commandtransformtranslate.h \
    Command/Transform/commandtransform.h \
    Command/Transform/commandtransformrotate.h \
    Command/Transform/commandtransformscale.h \
    Widget/renderwidget.h \
    Render/rendercamera.h \
    Widget/renderwindow.h \
    Document/modeldocument.h


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
