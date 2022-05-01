import QtQuick 2.12
import QtQuick.Window 2.12


Window
{
    visible: true;
    width: 240;
    height: 200;

    Rectangle
    {
        width: parent.width;
        height: parent.height;
        color: "white";

        Image
        {
            id: logo;
            x: 20;
            y: 20;
            source: "../images/qtlogo.png"
            transformOrigin: Item.Top;
        }

        Keys.onPressed:
        {
            if(event.key == Qt.Key_Left)
            {
                logo.rotation = (logo.rotation - 10) % 360;
            }
            else if(event.key == Qt.Key_Right)
            {
                logo.rotation = (logo.rotation + 10) % 360;
            }
        }

        focus: true;
    }
}
