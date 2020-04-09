import QtQuick 2.0
import org.example.PluginInterface 1.0

Rectangle {
    id: page
    width: 320; height: 240
    color: "lightgray"

    Text {
        id: helloText
        text: "Hello world!"
        y: 30
        anchors.horizontalCenter: page.horizontalCenter
        font.pointSize: 24; font.bold: true
    }

    Rectangle {
        id: innerPage
        width: 300; height: 30
        anchors.horizontalCenter: page.horizontalCenter
        color: "blue"

        Text {
            id: nextOne
            color: "white"
//            text: "literal Text"
            text: MySingleton.getTheText()
            anchors.verticalCenter: innerPage.verticalCenter
            anchors.horizontalCenter: innerPage.horizontalCenter
            font.pointSize: 18; font.bold: false
        }
    }

    OtherThing {
        id: myOtherThing
        x: 20; y: 150
    }

}


