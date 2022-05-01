#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    //engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/QML/MouseArea.qml")));
    engine.load(QUrl(QStringLiteral("qrc:/01_Import_Box.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/QML/02_ContainsMouse.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/QML/03_Drag.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/QML/04_TextInput.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/QML/06_Keys.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/QML/07_Flickable.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/QML/08_Flickable_Ground.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/QML/09_SignalHandler_exam1.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/QML/09_SignalHandler_exam2.qml")));



    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
