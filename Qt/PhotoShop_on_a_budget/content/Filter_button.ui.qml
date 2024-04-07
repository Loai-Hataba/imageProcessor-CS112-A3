import QtQuick 6.6

Item {
    id: filter_button
    width: 115
    height: 69

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
            x: 17
            y: 10
            color: "#ffffff"
            text: qsTr("Filter")
            font.pixelSize: 32
            font.family: "Verdana"
        }
    }
}
