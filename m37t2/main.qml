import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.15

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("TV")
    TextField {
        id: player
        readOnly: true
        placeholderText: qsTr("Playing cinema...")
        height: parent.height - 50
        width: parent.width
    }
    Button {
        id: play
        font.pixelSize: 30
        text: qsTr("▶")
        anchors.top: player.bottom
        anchors.topMargin: 2
        anchors.left: parent.left
        anchors.leftMargin: 30
        anchors.bottomMargin: 2
        height: 34
    }
    Button {
        id: pause
        font.pixelSize: 30
        text: qsTr("⏸️")
        anchors.top: player.bottom
        anchors.topMargin: 2
        anchors.left: play.right
        anchors.leftMargin: 20
        height: play.height
        anchors.bottomMargin: 2
    }
    Button {
        id: stop
        font.pixelSize: 30
        text: qsTr("⏹")
        anchors.top: player.bottom
        anchors.topMargin: 2
        anchors.left: pause.right
        anchors.leftMargin: 20
        height: play.height
        anchors.bottomMargin: 2
    }
    Button {
        id: prev
        font.pixelSize: 30
        text: qsTr("⏪️")
        anchors.top: player.bottom
        anchors.topMargin: 2
        anchors.left: stop.right
        anchors.leftMargin: 20
        height: play.height
        anchors.bottomMargin: 2
    }
    Button {
        id: next
        font.pixelSize: 30
        text: qsTr("⏩️")
        anchors.top: player.bottom
        anchors.topMargin: 2
        anchors.left: prev.right
        anchors.leftMargin: 20
        height: play.height
        anchors.bottomMargin: 2
    }
    ProgressBar {
        id: bar
        value: 0.5
        anchors.top: play.bottom
        anchors.topMargin: 4
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.leftMargin: 2
        anchors.rightMargin: 2
    }
}
