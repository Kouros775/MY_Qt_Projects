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
        text: "FileDialog loading";
        onClicked:
        {
            fileDialog.visible = true;
        }
    }

    FileDialog
    {
        id: fileDialog;
        title: "Please choose a file.";
        folder: shortcuts.home;
        onAccepted:
        {
            console.log("path : " + fileDialog.fileUrls);
            Qt.quit();
        }
        onRejected:
        {
            console.log("Canceled");
            Qt.quit();
        }
        Component.onCompleted: visible = false;
    }
}
