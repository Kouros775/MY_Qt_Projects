import QtQuick 2.12
import QtQuick.Window 2.12

Window
{
    visible: true;
    width: 200;
    height: 200;

    Loader
    {
        anchors.centerIn: parent;
        sourceComponent: rect;
    }

    Component
    {
        id: rect;
        Rectangle
        {
            width: 50;
            height: 50;
            color: "red";
        }
    }
}
