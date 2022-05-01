import QtQuick 2.12
import QtQuick.Window 2.12


Window
{
    visible: true;
    width: 360;
    height: 360;

    Rectangle
    {
        id: rect;
        width: 360;
        height: 360;
        color: "blue";

        MouseArea
        {
            id: mouseArea;
            anchors.fill: parent;
        }
        Connections
        {
            target: mouseArea;
            onClicked:
            {
                rect.color = Qt.rgba(Math.random(),
                                     Math.random(),
                                     Math.random()
                                     , 1);
            }
        }
    }
}
