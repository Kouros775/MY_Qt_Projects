import QtQuick 2.12
import QtQuick.Window 2.12


Window
{
    width: 320;
    height: 230;
    visible: true;

    Image
    {
        id: proAni;
        source: "./images/qtlogo.png";
        x: 50;
        y: 40;
        width: 50;
        height: 50;
    }

    PropertyAnimation
    {
        target: proAni;
        properties: "width, height";
        from: 0;
        to: 100;
        duration: 1000;
        running: true;
    }
}
