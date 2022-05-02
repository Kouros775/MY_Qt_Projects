#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    //engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/QML/canvas_basic.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/QML/canvas_rect.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/QML/canvas_gradients.qml")));
    engine.load(QUrl(QStringLiteral("qrc:/QML/canvas_mousedrawing.qml")));



    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
