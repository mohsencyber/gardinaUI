import QtQuick 2.0
import QtQuick.VirtualKeyboard 2.4



Item {
    width: 300; height: 200

Rectangle {
    TextInput {
        id: textInput
        x: 38
        y: 28
        width: 245
        height: 20
        text: qsTr("Text Input")
        font.pixelSize: 12
    }

    Text {
        id: element
        x: 8
        y: 28
        text: qsTr("Text")
        font.pixelSize: 12
    }

}
}
