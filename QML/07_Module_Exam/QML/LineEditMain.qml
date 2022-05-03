import QtQuick 2.12
import QtQuick.Window 2.12


Window
{
    visible: true;
    width: 400;
    height: 100;
    color: "lightblue";

    LineEdit
    {
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.verticalCenter: parent.verticalCenter;
        width: 300;
        height: 50;
    }
}
