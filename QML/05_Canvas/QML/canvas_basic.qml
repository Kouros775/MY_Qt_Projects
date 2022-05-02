import QtQuick 2.12
import QtQuick.Window 2.12


Window
{
    visible: true;
    width: 200;
    height: 200;

    Canvas
    {
        id: root;
        width: 200;
        height: 200;

        onPaint:
        {
            var ctx = getContext("2d");

            ctx.lineWidth = 4;
            ctx.strokeStyle = "blue";
            ctx.cillStyle = "steelblue";

            ctx.beginPath();
            ctx.moveTo(50, 50);
            ctx.lineTo(150, 50);
            ctx.lineTo(150, 150);
            ctx.lineTo(50, 150);
            ctx.closePath();

            ctx.fill();
            ctx.stroke();
        }
    }
}
