import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Dialogs 1.2


ApplicationWindow
{
    width: 300;
    height: 300;
    visible: true;

    Button
    {
        text: "ColorDialog loading";
        onClicked:
        {
            colorDialog.visible = true;
        }
    }

    ColorDialog
    {
        id: colorDialog;
        title: "Please choose a color.";
        onAccepted:
        {
            console.log("Color : " + colorDialog.color);
            Qt.quit();
        }
        onRejected:
        {
            console.log("Canceled.");
            Qt.quit();
        }
        Component.onCompleted: visible = false;
    }
}
