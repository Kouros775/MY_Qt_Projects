import QtQuick 2.12
import QtQuick.Window 2.12


Window
{
    visible: true;
    width: 300;
    height: 300;

    Component
    {
        id: redSquare;
        Rectangle
        {
            color: "red";
            width: 100;
            height: 100;
        }
    }

    Loader
    {
        sourceComponent: redSquare;
    }
    Loader
    {
        sourceComponent: redSquare;
        x: 100;
        y: 100;
    }
}
