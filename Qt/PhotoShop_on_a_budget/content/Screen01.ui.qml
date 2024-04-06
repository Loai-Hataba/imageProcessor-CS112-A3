

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
    height: Constants.height
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
        id: rectangle
        x: 375
        y: 172
        width: 1363
        height: 693
        color: "#888888"
        radius: 27

        ScrollView {
            id: scrollView
            x: 200
            y: 8
            width: 312
            height: 677
            focusPolicy: Qt.WheelFocus
            contentHeight: 1
            contentWidth: 1
            clip: true

            Button {
                id: button22
                x: 19
                y: 34
                text: qsTr("Filter")
                transformOrigin: Item.Center
                layer.smooth: false
                highlighted: false
                font.family: "Verdana"
                flat: false
            }

            Button {
                id: button23
                x: 183
                y: 34
                text: qsTr("Filter")
                transformOrigin: Item.Center
                layer.smooth: false
                highlighted: false
                font.family: "Verdana"
                flat: false
            }

            Button {
                id: button24
                x: 19
                y: 87
                text: qsTr("Filter")
                transformOrigin: Item.Center
                layer.smooth: false
                highlighted: false
                font.family: "Verdana"
                flat: false
            }

            Button {
                id: button25
                x: 183
                y: 87
                text: qsTr("Filter")
                transformOrigin: Item.Center
                layer.smooth: false
                highlighted: false
                font.family: "Verdana"
                flat: false
            }

            Button {
                id: button26
                x: 19
                y: 148
                text: qsTr("Filter")
                transformOrigin: Item.Center
                layer.smooth: false
                highlighted: false
                font.family: "Verdana"
                flat: false
            }

            Button {
                id: button27
                x: 183
                y: 148
                text: qsTr("Filter")
                transformOrigin: Item.Center
                layer.smooth: false
                highlighted: false
                font.family: "Verdana"
                flat: false
            }

            Button {
                id: button28
                x: 19
                y: 201
                text: qsTr("Filter")
                transformOrigin: Item.Center
                layer.smooth: false
                highlighted: false
                font.family: "Verdana"
                flat: false
            }

            Button {
                id: button29
                x: 183
                y: 201
                text: qsTr("Filter")
                transformOrigin: Item.Center
                layer.smooth: false
                highlighted: false
                font.family: "Verdana"
                flat: false
            }

            Button {
                id: button30
                x: 19
                y: 258
                text: qsTr("Filter")
                transformOrigin: Item.Center
                layer.smooth: false
                highlighted: false
                font.family: "Verdana"
                flat: false
            }

            Button {
                id: button31
                x: 183
                y: 258
                text: qsTr("Filter")
                transformOrigin: Item.Center
                layer.smooth: false
                highlighted: false
                font.family: "Verdana"
                flat: false
            }

            Button {
                id: button32
                x: 19
                y: 311
                text: qsTr("Filter")
                transformOrigin: Item.Center
                layer.smooth: false
                highlighted: false
                font.family: "Verdana"
                flat: false
            }

            Button {
                id: button33
                x: 183
                y: 311
                text: qsTr("Filter")
                transformOrigin: Item.Center
                layer.smooth: false
                highlighted: false
                font.family: "Verdana"
                flat: false
            }

            Button {
                id: button34
                x: 19
                y: 372
                text: qsTr("Filter")
                transformOrigin: Item.Center
                layer.smooth: false
                highlighted: false
                font.family: "Verdana"
                flat: false
            }

            Button {
                id: button35
                x: 183
                y: 372
                text: qsTr("Filter")
                transformOrigin: Item.Center
                layer.smooth: false
                highlighted: false
                font.family: "Verdana"
                flat: false
            }

            Button {
                id: button36
                x: 19
                y: 425
                text: qsTr("Filter")
                transformOrigin: Item.Center
                layer.smooth: false
                highlighted: false
                font.family: "Verdana"
                flat: false
            }

            Button {
                id: button37
                x: 183
                y: 425
                text: qsTr("Filter")
                transformOrigin: Item.Center
                layer.smooth: false
                highlighted: false
                font.family: "Verdana"
                flat: false
            }

            Button {
                id: button38
                x: 19
                y: 488
                text: qsTr("Filter")
                transformOrigin: Item.Center
                layer.smooth: false
                highlighted: false
                font.family: "Verdana"
                flat: false
            }

            Button {
                id: button39
                x: 183
                y: 488
                text: qsTr("Filter")
                transformOrigin: Item.Center
                layer.smooth: false
                highlighted: false
                font.family: "Verdana"
                flat: false
            }

            Button {
                id: button40
                x: 19
                y: 541
                text: qsTr("Filter")
                transformOrigin: Item.Center
                layer.smooth: false
                highlighted: false
                font.family: "Verdana"
                flat: false
            }

            Button {
                id: button41
                x: 183
                y: 541
                text: qsTr("Filter")
                transformOrigin: Item.Center
                layer.smooth: false
                highlighted: false
                font.family: "Verdana"
                flat: false
            }

            Button {
                id: button42
                x: 19
                y: 602
                text: qsTr("Filter")
                transformOrigin: Item.Center
                layer.smooth: false
                highlighted: false
                font.family: "Verdana"
                flat: false
            }

            Button {
                id: button43
                x: 183
                y: 602
                text: qsTr("Filter")
                transformOrigin: Item.Center
                layer.smooth: false
                highlighted: false
                font.family: "Verdana"
                flat: false
            }

            Button {
                id: button44
                x: 19
                y: 655
                text: qsTr("Filter")
                transformOrigin: Item.Center
                layer.smooth: false
                highlighted: false
                font.family: "Verdana"
                flat: false
            }

            Button {
                id: button45
                x: 183
                y: 655
                text: qsTr("Filter")
                transformOrigin: Item.Center
                layer.smooth: false
                highlighted: false
                font.family: "Verdana"
                flat: false
            }

            Button {
                id: button46
                x: 19
                y: 743
                text: qsTr("Filter")
                clip: false
                transformOrigin: Item.Center
                layer.smooth: false
                highlighted: false
                font.family: "Verdana"
                flat: false
            }

            Button {
                id: button47
                x: 183
                y: 743
                text: qsTr("Filter")
                clip: false
                transformOrigin: Item.Center
                layer.smooth: false
                highlighted: false
                font.family: "Verdana"
                flat: false
            }

            Button {
                id: button48
                x: 19
                y: 796
                text: qsTr("Filter")
                clip: false
                transformOrigin: Item.Center
                layer.smooth: false
                highlighted: false
                font.family: "Verdana"
                flat: false
            }

            Button {
                id: button49
                x: 183
                y: 796
                text: qsTr("Filter")
                clip: false
                transformOrigin: Item.Center
                layer.smooth: false
                highlighted: false
                font.family: "Verdana"
                flat: false
            }

            Button {
                id: button50
                x: 19
                y: 857
                text: qsTr("Filter")
                clip: false
                transformOrigin: Item.Center
                layer.smooth: false
                highlighted: false
                font.family: "Verdana"
                flat: false
            }

            Button {
                id: button51
                x: 183
                y: 857
                text: qsTr("Filter")
                clip: false
                transformOrigin: Item.Center
                layer.smooth: false
                highlighted: false
                font.family: "Verdana"
                flat: false
            }

            Button {
                id: button52
                x: 19
                y: 910
                text: qsTr("Filter")
                clip: false
                transformOrigin: Item.Center
                layer.smooth: false
                highlighted: false
                font.family: "Verdana"
                flat: false
            }

            Button {
                id: button53
                x: 183
                y: 910
                text: qsTr("Filter")
                clip: false
                transformOrigin: Item.Center
                layer.smooth: false
                highlighted: false
                font.family: "Verdana"
                flat: false
            }
        }
    }

    Rectangle {
        id: filters_menu
        x: 40
        y: 172
        width: 296
        height: 693
        color: "#545252"
        radius: 21
        clip: true

        Grid {
            id: grid
            x: 1
            y: 0
            width: 295
            height: 693
        }

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

        Button {
            id: button
            x: 16
            y: 82
            text: qsTr("Filter")
            transformOrigin: Item.Center
            layer.smooth: false
            highlighted: false
            flat: false
            font.family: "Verdana"
        }

        Button {
            id: button1
            x: 180
            y: 82
            text: qsTr("Filter")
            transformOrigin: Item.Center
            layer.smooth: false
            highlighted: false
            font.family: "Verdana"
            flat: false
        }

        Button {
            id: button2
            x: 16
            y: 135
            text: qsTr("Filter")
            transformOrigin: Item.Center
            layer.smooth: false
            highlighted: false
            font.family: "Verdana"
            flat: false
        }

        Button {
            id: button3
            x: 180
            y: 135
            text: qsTr("Filter")
            transformOrigin: Item.Center
            layer.smooth: false
            highlighted: false
            font.family: "Verdana"
            flat: false
        }

        Button {
            id: button4
            x: 16
            y: 196
            text: qsTr("Filter")
            transformOrigin: Item.Center
            layer.smooth: false
            highlighted: false
            font.family: "Verdana"
            flat: false
        }

        Button {
            id: button5
            x: 180
            y: 196
            text: qsTr("Filter")
            transformOrigin: Item.Center
            layer.smooth: false
            highlighted: false
            font.family: "Verdana"
            flat: false
        }

        Button {
            id: button6
            x: 16
            y: 249
            text: qsTr("Filter")
            transformOrigin: Item.Center
            layer.smooth: false
            highlighted: false
            font.family: "Verdana"
            flat: false
        }

        Button {
            id: button7
            x: 180
            y: 249
            text: qsTr("Filter")
            transformOrigin: Item.Center
            layer.smooth: false
            highlighted: false
            font.family: "Verdana"
            flat: false
        }

        Button {
            id: button8
            x: 16
            y: 306
            text: qsTr("Filter")
            transformOrigin: Item.Center
            layer.smooth: false
            highlighted: false
            font.family: "Verdana"
            flat: false
        }

        Button {
            id: button9
            x: 180
            y: 306
            text: qsTr("Filter")
            transformOrigin: Item.Center
            layer.smooth: false
            highlighted: false
            font.family: "Verdana"
            flat: false
        }

        Button {
            id: button10
            x: 16
            y: 359
            text: qsTr("Filter")
            transformOrigin: Item.Center
            layer.smooth: false
            highlighted: false
            font.family: "Verdana"
            flat: false
        }

        Button {
            id: button11
            x: 180
            y: 359
            text: qsTr("Filter")
            transformOrigin: Item.Center
            layer.smooth: false
            highlighted: false
            font.family: "Verdana"
            flat: false
        }

        Button {
            id: button12
            x: 16
            y: 420
            text: qsTr("Filter")
            transformOrigin: Item.Center
            layer.smooth: false
            highlighted: false
            font.family: "Verdana"
            flat: false
        }

        Button {
            id: button13
            x: 180
            y: 420
            text: qsTr("Filter")
            transformOrigin: Item.Center
            layer.smooth: false
            highlighted: false
            font.family: "Verdana"
            flat: false
        }

        Button {
            id: button14
            x: 16
            y: 473
            text: qsTr("Filter")
            transformOrigin: Item.Center
            layer.smooth: false
            highlighted: false
            font.family: "Verdana"
            flat: false
        }

        Button {
            id: button15
            x: 180
            y: 473
            text: qsTr("Filter")
            transformOrigin: Item.Center
            layer.smooth: false
            highlighted: false
            font.family: "Verdana"
            flat: false
        }

        Button {
            id: button16
            x: 16
            y: 533
            text: qsTr("Filter")
            transformOrigin: Item.Center
            layer.smooth: false
            highlighted: false
            font.family: "Verdana"
            flat: false
        }

        Button {
            id: button17
            x: 180
            y: 533
            text: qsTr("Filter")
            transformOrigin: Item.Center
            layer.smooth: false
            highlighted: false
            font.family: "Verdana"
            flat: false
        }

        Button {
            id: button18
            x: 16
            y: 586
            text: qsTr("Filter")
            transformOrigin: Item.Center
            layer.smooth: false
            highlighted: false
            font.family: "Verdana"
            flat: false
        }

        Button {
            id: button19
            x: 180
            y: 586
            text: qsTr("Filter")
            transformOrigin: Item.Center
            layer.smooth: false
            highlighted: false
            font.family: "Verdana"
            flat: false
        }
    }

}
