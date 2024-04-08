

/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/
import QtQuick 6.6
import QtQuick.Controls 6.6
import PhotoShop_on_a_budget
import QtQuick.Layouts
import QtQuick.Studio.Components

Rectangle {
    id: main_screen
    width: Constants.width
    height: 1050
    color: "#333333"
    radius: 0
    border.color: "#333333"

    Image {
        id: logo
        x: 0
        y: 0
        width: 369
        height: 186
        source: "images/Logo.png"
        fillMode: Image.PreserveAspectFit
    }

    Rectangle {
        id: image_screen
        x: 375
        y: 172
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

    Rectangle {
        id: filters_menu
        x: 40
        y: 172
        width: 296
        height: 706
        color: "#545252"
        radius: 21
        clip: true

        Rectangle {
            id: filter_menu_label
            x: -5
            y: 0
            width: 301
            height: 60
            color: "#383838"
            radius: 18

            Text {
                id: filter_menu_text
                x: 93
                y: 2
                color: "#ececec"
                text: qsTr("Filters")
                font.pixelSize: 44
                clip: false
                font.family: "Verdana"
            }
        }

        ScrollView {
            id: scrollView
            x: 0
            y: 73
            width: 296
            height: 632

            Grid {
                id: grid
                x: 0
                y: 0
                width: 296
                height: 633
                padding: 0
                bottomPadding: 0
                topPadding: 0
                rightPadding: 0
                clip: false
                leftPadding: 22
                rows: 10
                columns: 2
                spacing: 22

                Filter_button {
                    id: grayscale
                    buttonText: "Grayscale"
                }

                Filter_button {
                    id: bw
                    buttonText: "Black &White"
                }

                Filter_button {
                    id: inverted
                    buttonText: "Inverted"
                }

                Filter_button {
                    id: merge
                    buttonText: "Merge"
                }

                Filter_button {
                    id: flip
                    buttonText: "Flip"
                }

                Filter_button {
                    id: rotate
                    buttonText: "Rotate"
                }

                Filter_button {
                    id: darken_lighten
                    buttonText: "Darken-Lighten"
                }

                Filter_button {
                    id: crop
                    buttonText: "Crop"
                }

                Filter_button {
                    id: frame
                    buttonText: "Frame"
                }

                Filter_button {
                    id: edge
                    buttonText: "Edge"
                }

                Filter_button {
                    id: resize
                    buttonText: "Resize"
                }

                Filter_button {
                    id: blur
                    buttonText: "Blur"
                }

                Filter_button {
                    id: purple
                    buttonText: "Purple"
                }

                Filter_button {
                    id: ir
                    buttonText: "Infrared"
                }

                Filter_button {
                    id: tv
                    buttonText: "T.V"
                }

                Filter_button {
                    id: oil
                    buttonText: "Oil Painting"
                }

                Filter_button {
                    id: sepia
                    buttonText: "Sepia"
                }

                Filter_button {
                    id: pixelate
                    buttonText: "Pixelate"
                }

                Filter_button {
                    id: filter_button18
                    buttonText: ""
                }

                Filter_button {
                    id: filter_button19
                    buttonText: ""
                }
            }
        }
    }

    Save_button {
        id: save_button
        x: 40
        y: 922
    }

    MyMyLoad_button {
        id: myMyLoad_button
        x: 200
        y: 922
    }
}
