import QtQuick 2.12

Rectangle
{
    id: myItem;
    width: 100;
    height: 100;

    signal message(string msg);

    MouseArea
    {
        anchors.fill: parent;
        onClicked: myItem.message("clicked");
    }
}
