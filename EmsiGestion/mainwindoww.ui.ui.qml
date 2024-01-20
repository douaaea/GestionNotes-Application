/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/

import QtQuick 6.5
import QtQuick.Controls 6.5


Rectangle {
    width: Constants.width
    height: Constants.height
    opacity: 1
    color: "#ffffff"


    Text {
        width: 558
        height: 42
        text: qsTr("Ecole Marocaine des Sciences d'Ingenieur")
        font.pointSize: 29
        font.family: "Times New Roman"
        anchors.verticalCenterOffset: -282
        anchors.horizontalCenterOffset: -118
        anchors.centerIn: parent
    }

    Image {
        id: image
        x: 1403
        y: 128
        width: 163
        height: 158
        source: "../../../Downloads/logo.jpg"
        sourceSize.height: 206
        sourceSize.width: 219
        fillMode: Image.PreserveAspectFit
    }

    Rectangle {
        id: rectangle
        x: 519
        y: 452
        width: 374
        height: 325
        opacity: 1
        color: "#4ca2cd"
        border.width: 5

        TextInput {
            id: textInput
            x: 102
            y: 49
            width: 310
            height: 71
            text: " ETUDIANT"
            font.pixelSize: 28
            font.family: "Tahoma"
        }

        Button {
            id: button
            x: 73
            y: 156
            width: 218
            height: 95
            text: qsTr("INTERFACE ETUDIANT")
            layer.format: ShaderEffectSource.Alpha
            layer.effect: button
        }
    }

    Rectangle {
        id: rectangle1
        x: 1003
        y: 452
        width: 374
        height: 325
        opacity: 1
        color: "#4ca2cd"
        border.width: 5
        TextInput {
            id: textInput1
            x: 73
            y: 48
            width: 310
            height: 71
            text: "ADMINISTRATEUR"
            font.pixelSize: 28
            font.family: "Tahoma"
        }

        Button {
            id: button1
            x: 73
            y: 156
            width: 218
            height: 95
            text: qsTr("INTERFACE ADMINISTRATEUR")
            layer.format: ShaderEffectSource.Alpha
            layer.effect: button1
        }
    }
}
