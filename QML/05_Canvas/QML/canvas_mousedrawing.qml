import QtQuick 2.12
import QtQuick.Window 2.12


Window
{
    visible: true;
    width: 360;
    height: 360;

    Rectangle
    {
        id: root;
        width: 360;
        height: 360;

        Canvas
        {
            id: myCanvas;
            anchors.fill: parent;

            property int xpos;
            property int ypos;

            onPaint:
            {
                var ctx = getContext("2d");
                ctx.fillStyle = "red";
                ctx.fillRect(myCanvas.xpos - 1, myCanvas.ypos - 1, 3, 3);
            }

            MouseArea
            {
                anchors.fill: parent;
                onPressed:
                {
                    myCanvas.xpos = mouseX;
                    myCanvas.ypos = mouseY;
                    myCanvas.requestPaint();
                }
                onMouseXChanged:
                {
                    myCanvas.xpos = mouseX;
                    myCanvas.ypos = mouseY;
                    myCanvas.requestPaint();
                }
                onMouseYChanged:
                {
                    myCanvas.xpos = mouseX;
                    myCanvas.ypos = mouseY;
                    myCanvas.requestPaint();
                }
            }
        }
    }
}








