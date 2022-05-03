import QtQuick 2.12
import QtQuick.Window 2.12


Window
{
    visible: true;
    width: 400;
    height: 100;
    color: "lightblue";

    NewLineEdit
    {
        id: lineEdit;
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.top: parent.top;
        anchors.topMargin: 16;
        width: 300;
        height: 50;
    }

    Text
    {
        anchors.top: lineEdit.bottom;
        anchors.topMargin: 12;
        anchors.left: parent.left;
        anchors.leftMargin: 16;
        font.pixelSize: 320;
        text: "<b>Summary:</b>" + lineEdit.text;
    }
}
