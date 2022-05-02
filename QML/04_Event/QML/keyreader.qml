import QtQuick 2.12


Item
{
    Item
    {
        focus: true;
        Keys.onPressed:
        {
            console.log("Loaded Captured:", event.text);
            event.accepted = true;
        }
    }
}
