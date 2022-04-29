import QtQuick 2.12
import QtQuick.Window 2.12


Window
{
    id: mybutton
    visible: true;
    width: 400;
    height: 400;
    GradientStop { position: 0.5; color: "yellow" }

    Rectangle
    {
        width: 400;
        height: 400;

        gradient: Gradient {
         GradientStop { position: 0.0; color: "red" }
         GradientStop { position: 1.0; color: "green" }
         }
    }
}
