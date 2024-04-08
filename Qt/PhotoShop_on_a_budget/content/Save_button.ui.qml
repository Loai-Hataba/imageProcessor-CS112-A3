import QtQuick 6.6

Item {
    id: save_button
    width: 136
    height: 59

    MouseArea {
        id: mouseArea
        anchors.fill: parent
    }

    Rectangle {
        id: rectangle1
        x: 0
        y: 16
        width: 136
        height: 59
        color: "#000000"
        radius: 23
        border.color: "#ffffff"
        border.width: 0
    }

    Rectangle {
        id: rectangle
        color: "#6804ae"
        radius: 23
        border.color: "#ffffff"
        border.width: 3
        anchors.fill: parent
    }

    Text {
        id: text1
        x: 31
        y: 12
        color: "#dedede"
        text: qsTr("Save")
        font.pixelSize: 30
        renderType: Text.NativeRendering
        font.styleName: "Bold Italic"
        font.family: "Verdana"
    }
}
