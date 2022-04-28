#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    //engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/animatedimage.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/text_image_anchors.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/gradient.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/systempalette.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/screen.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/fontloader.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/repeater.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/image.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/transformation.qml")));
    engine.load(QUrl(QStringLiteral("qrc:/simple_accessible.qml")));

    if (engine.rootObjects().isEmpty())
    {
        qDebug() << __FUNCTION__;
        return -1;
    }

    return app.exec();
}
