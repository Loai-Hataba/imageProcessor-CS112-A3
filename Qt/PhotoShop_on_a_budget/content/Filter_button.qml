import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    id: filter_button
    width: 115
    height: 69

    property alias buttonText: text1.text // This is the new property alias

    Rectangle {
        id: rectangle2
        x: 0
        y: 11
        width: 115
        height: 58
        color: "#000000"
        radius: 15
        border.color: "#ffffff"
        border.width: 0
    }
    Rectangle {
        id: rectangle1
        x: 0
        y: 0
        width: 115
        height: 58
        color: "#990581"
        radius: 15
        border.color: "#ffffff"
        border.width: 2

        Text {
            id: text1
            x: 9
            y: 14
            width: 99
            height: 36
            color: "#ffffff"
            text: buttonText // Use the property alias here
            font.pixelSize: 18
            font.bold: true
            wrapMode: Text.WordWrap
            font.family: "Verdana"
        }
    }
}
