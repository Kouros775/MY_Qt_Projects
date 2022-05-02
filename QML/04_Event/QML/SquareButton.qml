import QtQuick 2.12


Rectangle
{
    id: root;
    signal activated(real xPosition, real yPosition);
    signal deactivated;

    MouseArea
    {
        anchors.fill: parent;
        onPressed:
        {
            root.activated(mouse.x, mouse.y);
        }
        onReleased:
        {
            root.deactivated();
        }
    }
}
