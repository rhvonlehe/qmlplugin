import QtQuick 2.0

Rectangle {
    id: main
    width: 320; height: 480
    color: "darkgray"

    Loader
    {
        id: mainLoader
        anchors.verticalCenter: main.verticalCenter
        source: "qrc:/hello.qml"
    }

}
