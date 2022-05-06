import QtQuick 2.12
import QtQuick.Window 2.12


Window
{
    width: 400;
    height: 200;
    visible: true;
    color: "white";
    id: root;

    ListModel
    {
        id: nameModel;
        ListElement
        {
            name: "Alice";
        }
        ListElement
        {
            name: "Bob";
        }
        ListElement
        {
            name: "Jane";
        }
        ListElement
        {
            name: "Victor";
        }
        ListElement
        {
            name: "Wendy";
        }
    }

    Component
    {
        id: nameDelegate;

        Text
        {
            text: name;
            font.pixelSize: 24;
            anchors.left: parent.left;
            anchors.leftMargin: 2;
        }
    }

    Component
    {
        id: bannerComponent;

        Rectangle
        {
            id: banner;
            width: root.width;
            height: 50;
            gradient: clubcolors;
            border
            {
                color: "#9EDDF2";
                width: 2;
            }
            Text
            {
                anchors.centerIn: parent;
                text: "Members";
                font.pixelSize: 32;
            }
        }
    }

    Gradient
    {
        id: clubcolors;
        GradientStop
        {
            position: 0.0;
            color: "#8EE2FE";
        }
        GradientStop
        {
            position: 0.66;
            color: "#7ED2EE";
        }
    }

    ListView
    {
        anchors.fill: parent;
        clip: true;
        model: nameModel;
        delegate: nameDelegate;
        header: bannerComponent;
        footer:
            Rectangle
            {
              width: parent.width;
              height: 30;
              gradient: clubcolors;
            }
        highlight: Rectangle {
         color: "lightgray"
         }


        focus: true;
    }
}
