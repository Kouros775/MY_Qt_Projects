QT       += core gui opengl
QT       += 3dcore 3drender 3dinput 3dextras

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MY_Viewer
TEMPLATE = app
DEFINES += QT_DEPRECATED_WARNINGS
CONFIG += c++11

LIBS += -lopengl32

SOURCES += \
    Render/renderbase.cpp \
    Render/rendermodel.cpp \
        main.cpp \
        mainwindow.cpp \
        mdimainwindow.cpp \
    openglwidget.cpp \
    Command/icommand.cpp \
    Command/commandopenfile.cpp \
    Command/commandnewscene.cpp \
    Command/Transform/commandtransformtranslate.cpp \
    Command/Transform/commandtransform.cpp \
    Command/Transform/commandtransformrotate.cpp \
    Command/Transform/commandtransformscale.cpp \
    Render/camera.cpp \
    Render/renderer.cpp \
    Loader/modelloader.cpp \
    Widget/renderwidget.cpp \
    Render/rendercamera.cpp \
    Widget/renderwindow.cpp

HEADERS += \
    Render/renderbase.h \
    Render/rendermodel.h \
        mainwindow.h \
        mdimainwindow.h \
    openglwidget.h \
    Command/icommand.h \
    Command/commandopenfile.h \
    Command/commandnewscene.h \
    Command/Transform/commandtransformtranslate.h \
    Command/Transform/commandtransform.h \
    Command/Transform/commandtransformrotate.h \
    Command/Transform/commandtransformscale.h \
    Render/camera.h \
    Render/renderer.h \
    Loader/modelloader.h \
    Widget/renderwidget.h \
    Render/rendercamera.h \
    Widget/renderwindow.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES += \
    fragmentshader.frag \
    vertexshader.vert
