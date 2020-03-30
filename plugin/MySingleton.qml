pragma Singleton
import QtQuick 2.0

Item {
    readonly property int value1: 1
    readonly property int value2: 2
    readonly property string theText: "singleton Text"

    function getTheText()
    {
        return theText
    }
}
