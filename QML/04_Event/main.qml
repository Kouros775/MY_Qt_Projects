import QtQuick 2.9
import QtQuick.Window 2.2
import "./QML"

Window
{
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    MouseArea
    {
        id: myMouseArea;
    }
}
