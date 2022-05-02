import QtQuick 2.12

Rectangle
{
    width: 200;
    height: 100;
    color: "green";

    Text
    {
        anchors.centerIn: parent;
        text: "page1 loaded";
        font.bold: true;
        color: "blue";
    }
}
