import QtQuick 2.12
import QtQuick.Window 2.12


Window
{
    id: root;
    visible: true;
    width: 250;
    height: 100;
    color: "lightblue";

    NewCheckBox
    {
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.verticalCenter: parent.vertcialCenter;

        onMyChecked: checkValue ? root.color = "red" : root.color = "lightblue";
    }
}
