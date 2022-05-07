#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlContext>
#include <qqml.h>
#include "message.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    qmlRegisterType<Message>("Message", 1, 0, "Msg");

    QQuickView viewer;
    Message msg;
    viewer.engine()->rootContext()->setContextProperty("msg", &msg);

    viewer.setSource(QUrl("qrc:/main.qml"));
    viewer.show();

    return app.exec();
}
