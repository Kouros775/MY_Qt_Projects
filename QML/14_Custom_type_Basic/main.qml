import QtQuick 2.12
import Message 1.0


Rectangle
{
    width: 300;
    height: 300;

    Text
    {
        id: myText;
        anchors.centerIn: parent;
        text: myMsg.author;
        font.pixelSize: 25;
        Component.onCompleted:
        {
            myMsg.author = "Hello";
        }
        Msg
        {
            id: myMsg;
            onNewMessagePosted:
            {
                console.log("Meesage received: ", subject);
                myText.font.pixelSize  = 25;
                myText.text = subject;
            }
        }
    }
}
