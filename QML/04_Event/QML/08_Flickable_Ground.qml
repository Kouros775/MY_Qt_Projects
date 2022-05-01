import QtQuick 2.12
import QtQuick.Window 2.12


Window
{
    visible: true;
    width: Screen.width;
    height: Screen.height;

    Flickable
    {
        width: parent.width;
        height: parent.height;
        contentWidth: parent.width;
        contentHeight: parent.height * 2;
        interactive: true;

        Image
        {
            id: ground;
            anchors.fill: parent;
            source: "../images/ground.jpg";
            sourceSize.width: parent.width;
            sourceSize.height: parent.height;
        }
        Image
        {
            id: player;
            source: "../images/player.png";
            x: parent.width/ 2;
            y: parent.height / 2;
        }
    }
}
