import QtQuick 2.15
import QtQuick.Controls 2.15

Rectangle {
    id: image_screen
    width: 1363
    height: 713
    color: "#888888"
    radius: 27

    Image {
        id: image
        x: 0
        y: 0
        width: 1363
        height: 713
        source: "qrc:/qtquickplugin/images/template_image.png"
        fillMode: Image.PreserveAspectFit
    }
}

