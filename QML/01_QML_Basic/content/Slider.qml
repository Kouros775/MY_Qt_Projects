import QtQuick 2.12

// Minimal slider implementation
Rectangle {
    id: slider

    property alias text: buttonText.text
    Accessible.role: Accessible.Slider

    property int value: 5         // required
    property int minimumValue: 0  // optional (default INT_MIN)
    property int maximumValue: 20 // optional (default INT_MAX)
    property int stepSize: 1      // optional (default 1)

    width: 100
    height: 30
    border.color: "black"
    border.width: 1

    Rectangle {
        id: indicator
        x: 1
        y: 1
        height: parent.height - 2
        width: ((parent.width - 2) / maximumValue) * value
        color: "lightgrey"
        Behavior on width {
            NumberAnimation { duration: 50 }
        }
    }

    Text {
        id: buttonText
        text: parent.value
        anchors.centerIn: parent
        font.pixelSize: parent.height * .5
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            var pos = mouse.x / slider.width * (maximumValue - minimumValue) + minimumValue
            slider.value = pos
        }
    }

    Keys.onLeftPressed: value > minimumValue ? value = value - stepSize : minimumValue
    Keys.onRightPressed: value < maximumValue ? value = value + stepSize : maximumValue
}
