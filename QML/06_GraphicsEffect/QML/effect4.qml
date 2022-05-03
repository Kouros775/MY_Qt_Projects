import QtQuick 2.12
import QtQuick.Window 2.12
import QtGraphicalEffects 1.0


Window
{
    visible: true;
    width: 300;
    height: 300;

    Item
    {
        width: parent.width;
        height: parent.height;

        Image
        {
            id: butterfly;
            source: "../images/butterfly.png";
            sourceSize: Qt.size(parent.width, parent.height);
            smooth: true;
            visible: false;
        }

        LevelAdjust
        {
            anchors.fill: butterfly;
            source: butterfly;
            minimumInput: "#00000070"
            maximumInput: "#ffffff";
            minimumOutput: "#000000";
            maximumOutput: "#ffffff"
        }
    }
}
