import QtQuick 2.12
import QtQuick.Window 2.12

Window
{
    visible: true;
    width: 200;
    height: 200;

    Loader
    {
        id: loader;
        focus: true;
        source: "keyreader.qml";
    }
}
