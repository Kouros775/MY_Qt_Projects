import QtQuick 2.12
import QtQuick.Window 2.12
//import "../02_QML_Basic2"
import "."


Window
{
    visible: true;
    id: window;
    width: 240;
    height: 100;
    color: "white";

    Column
    {
        id: column;
        spacing: 6;
        anchors.margins: 10;
        anchors.fill: parent;
        width: parent.width;

        Text
        {
            id: status;
            width: column.width;
        }

        Row
        {
            spacing: 6;
            button
            {
                id: sendButton;
                width: 100;
                height: 40;
                text: "Send";
                onClicked:
                {
                    status.text = "Send 버튼 클릭함";
                }
            }
            button
            {
                id: discardButton;
                width: 100;
                height: 40;
                text: "Discard";
                onClicked:
                {
                    status.text = "Discard 버튼 클릭함.";
                }
            }

        }
    }
}
