import QtQuick 2.12
import MyCustomTimer 1.0


Rectangle
{
    width: 300;
    height: 200;
    property int timerCnt: 0;

    Image
    {
        id: loadImage;
        source: "./images/loading.png";
        width: 100;
        height: 100;
        anchors.top: parent.top;
        anchors.topMargin: 20;
        anchors.horizontalCenter: parent.horizontalCenter;
    }

    PropertyAnimation
    {
        id: loadAni;
        target: loadImage;
        loops: Animation.Infinite;
        from: 0;
        to: 360;
        property: "rotation";
        duration: 2000;
        running: false;
    }

    Text
    {
        text: timer.active ? qsTr("타이머 동작 중.") : qsTr("타이머 정지 상태.");
        font.pixelSize: 24;
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.top: loadImage.bottom;
        anchors.topMargin: 30;
    }

    MyTimer
    {
        id: timer;
        interval: 1000;
        onTimeout:
        {
            console.log("Timer Call : ", timerCnt++);
        }
    }

    MouseArea
    {
        anchors.fill: parent;
        onClicked:
        {
            if(timer.active == false)
            {
                console.log("Timer start.");
                timer.start();
                loadAni.start();
            }
            else
            {
                console.log("Timer stop.");
                timer.stop();
                loadAni.stop();
            }
        }
    }
}
