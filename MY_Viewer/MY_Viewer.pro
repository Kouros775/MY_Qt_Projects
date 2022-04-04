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
    icommand.cpp \
    commandopenfile.cpp \
    openglwidget.cpp

HEADERS += \
        mainwindow.h \
        mdimainwindow.h \
    icommand.h \
    commandopenfile.h \
    openglwidget.h

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
