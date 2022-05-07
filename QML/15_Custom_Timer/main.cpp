#include <QGuiApplication>
#include <QQuickView>
#include <qqml.h>
#include "timer.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<Timer>("MyCustomTimer", 1, 0, "MyTimer");
    QQuickView viewer;
    viewer.setSource(QUrl("qrc:/main.qml"));
    viewer.show();

    return app.exec();
}
