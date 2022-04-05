QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MY_Viewer
TEMPLATE = app
DEFINES += QT_DEPRECATED_WARNINGS
CONFIG += c++11

LIBS += -lopengl32

SOURCES += \
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
    Command/Transform/commandtransformscale.cpp

HEADERS += \
        mainwindow.h \
        mdimainwindow.h \
    openglwidget.h \
    Command/icommand.h \
    Command/commandopenfile.h \
    Command/commandnewscene.h \
    Command/Transform/commandtransformtranslate.h \
    Command/Transform/commandtransform.h \
    Command/Transform/commandtransformrotate.h \
    Command/Transform/commandtransformscale.h

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
