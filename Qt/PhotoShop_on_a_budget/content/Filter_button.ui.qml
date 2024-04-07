import QtQuick 6.6

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
            x: 4
            y: 14
            width: 107
            height: 36
            color: "#ffffff"
            text: buttonText // Use the property alias here
            font.pixelSize: 15
            font.family: "Verdana"
        }
    }
}
