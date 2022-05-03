import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.2


ApplicationWindow
{
    width: 400;
    height: 300;
    visible: true;

    RowLayout
    {
        id: layout;
        anchors.fill: parent;
        spacing: 6;

        Rectangle
        {
            color: "blue";
            Layout.fillWidth: true;
            Layout.minimumWidth: 50;
            Layout.preferredWidth: 100;
            Layout.maximumWidth: 300;
            Layout.minimumHeight: 150;

            Text
            {
                anchors.centerIn: parent;
                color: "white";
                text: parent.width + 'x' + parent.height;
            }

            Rectangle
            {
                color: 'green'
                Layout.fillWidth: true
                Layout.minimumWidth: 100
                Layout.preferredWidth: 200
                Layout.preferredHeight: 100
                Text {
                anchors.centerIn: parent; color: "white"
                text: parent.width + 'x' + parent.height
                }
            }
        }
    }
}


