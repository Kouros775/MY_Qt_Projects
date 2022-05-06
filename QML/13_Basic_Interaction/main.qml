import QtQuick 2.12
import QtQuick.Window 2.12


Window
{
    width: 360;
    height: 300;
    visible: true;

    Text
    {
        id: myText;
        anchors.centerIn: parent;
        text: msg.author;
        Component.onCompleted:
        {
            msg.author = "Hello";
            myText.text = msg.author;
        }
    }
}
