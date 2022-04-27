import QtQuick 2.12
import QtQuick.Window 2.12

Window
{
    visible: true;
    width: 300;
    height: 300;

    Rectangle
    {
        width: 300;
        height: 300;
        color: "lightblue";
        id: rectangle1;

        Rectangle
        {
            id: subRect;
            width: 300;
            height: 100;
            color: "yellow";
        }

        Text
        {
            text: "Centered Text.";
            color: "green";
            font.family: "Helvetica";
            font.pixelSize: 32;
            anchors.top: surRect.bottom;
            anchors.centerIn: rectangle1;
        }
    }
}
