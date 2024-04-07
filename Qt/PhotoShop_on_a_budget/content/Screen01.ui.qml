

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
        height: 713
        color: "#888888"
        radius: 27

        Image {
            id: image
            x: 0
            y: 8
            width: 1363
            height: 705
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
                    id: filter_button
                }

                Filter_button {
                    id: filter_button1
                }

                Filter_button {
                    id: filter_button2
                }

                Filter_button {
                    id: filter_button3
                }

                Filter_button {
                    id: filter_button4
                }

                Filter_button {
                    id: filter_button5
                }

                Filter_button {
                    id: filter_button6
                }

                Filter_button {
                    id: filter_button7
                }

                Filter_button {
                    id: filter_button8
                }

                Filter_button {
                    id: filter_button9
                }

                Filter_button {
                    id: filter_button10
                }

                Filter_button {
                    id: filter_button11
                }

                Filter_button {
                    id: filter_button12
                }

                Filter_button {
                    id: filter_button13
                }

                Filter_button {
                    id: filter_button14
                }

                Filter_button {
                    id: filter_button15
                }

                Filter_button {
                    id: filter_button16
                }

                Filter_button {
                    id: filter_button17
                }

                Filter_button {
                    id: filter_button18
                }

                Filter_button {
                    id: filter_button19
                }
            }
        }
    }
}