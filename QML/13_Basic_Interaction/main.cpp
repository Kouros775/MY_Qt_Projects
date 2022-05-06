#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlContext>
#include <qqml.h>
#include "message.h"
#include "invokable_exam_1.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQuickView viewer;

    invokable_exam_1 msg;
    viewer.engine()->rootContext()->setContextProperty("msg", &msg);
    //viewer.setSource(QUrl("qrc:/main.qml"));
    viewer.setSource(QUrl("qrc:/invokable_exam_1.qml"));

    return app.exec();

}
