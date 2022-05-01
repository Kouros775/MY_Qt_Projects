import QtQuick 2.12
import QtQuick.Window 2.12


Window
{
    visible: true;
    width: 400;
    height: 112;

    Rectangle
    {
        width: 400;
        height: 112;
        color: "lightblue";

        TextInput
        {
            anchors.left: parent.left;
            y: 16;
            anchors.right: parent.right;
            text: "MinYoung Programming";
            font.pixelSize: 32;
            color: focus ? "black" : " gray";
            focus : true;
        }
        TextInput
        {
            anchors.left: parent.left;
            y: 64;
            anchors.right: parent.right;
            text: "Handsome";
            font.pixelSize: 32;
            color: focus ? "black" : "gray";
        }
    }
}
