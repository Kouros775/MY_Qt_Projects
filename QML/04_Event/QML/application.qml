import QtQuick 2.12
import QtQuick.Window 2.12


Window
{
    visible: true;
    width: 100;
    height: 100;

    Loader
    {
        id: myLoader;
        source: "myitem.qml";
    }
    Connections
    {
        target: myLoader.item;
        onMessage: console.log(msg);
    }
}
