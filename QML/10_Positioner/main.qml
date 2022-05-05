import QtQuick 2.12
import QtQuick.Window 2.12


Window
{
    visible: true;
    width: 200;
    height: 200;

    Grid
    {
        Repeater
        {
            model: 16;

            Rectangle
            {
                id: rect;
                width: 50;
                height: 50;
                border.width: 1;
                color: Positioner.isFirstItem ? "yellow" : "lightsteelblue";

                Text
                {
                    text: rect.Positioner.index;
                }
            }
        }
    }
}
