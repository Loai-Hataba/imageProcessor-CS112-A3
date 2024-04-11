import QtQuick 2.15

Item {
    id: myLoad_button
    width: 136
    height: 59

    Rectangle {
        id: rectangle1
        x: 0
        y: 16
        width: 136
        height: 59
        visible: true
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
        color: "#ffffff"
        text: qsTr("Load")
        font.pixelSize: 30
        //renderType: Text.NativeRendering
        font.styleName: "Bold Italic"
        font.family: "Verdana"
    }
    MouseArea {
            id: mouseArea
            anchors.fill: parent
            onClicked: {
                console.log("Load Button clicked!")
            }
    }
}
