import QtQuick 2.12
import QtQuick.Window 2.12


Window
{
    visible: true;
    width: 300;
    height: 250;

    Rectangle
    {
        width: 300;
        height: 250;
        color: "white";

        Image
        {
            x: 10;
            y: 10;
            source: "./images/qtlogo.png";
        }
    }
}
