import QtQuick 2.12
import QtQuick.Window 2.12


Window
{
    width: 200;
    height: 200;
    visible: true;

    Text
    {
        id: myText;
        anchors.centerIn: parent;
        text: msg.autohr;
        Component.onCompleted:
        {
            msg.author = "Hello";
        }
    }

    MouseArea
    {
        anchors.fill: parent;
        onClicked:
        {
            var str = "Who are you?";
            var result = msg.postMessage(str);
            console.log("Result of postMessage():", result);
            msg.refresh();
        }
    }
}
