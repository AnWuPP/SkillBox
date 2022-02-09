import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    id: root
    visible: true
    minimumWidth: 640
    minimumHeight: 480
    title: qsTr("Hello World")

    Rectangle {
        id: scene
        anchors.fill: parent
        state: "InitialState"

        Rectangle {
            id: leftRect
            x: 100
            y: 200
            color: "lightgrey"
            width: 100
            height: 100
            border.color: "black"
            border.width: 3
            radius: 5
            
            Text {
               id: leftName
               anchors.centerIn: parent
               text: "move"
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    ball.x += 30
                    if(ball.x + ball.width >= rightRect.x)
                        scene.state = "InitialState"
                    else
                        scene.state = "OtherState"
                }
            }
        }

        Rectangle {
            id: rightRect
            x: 300
            y: 200
            color: "lightgrey"
            width: 100
            height: 100
            border.color: "black"
            border.width: 3
            radius: 5

            Text {
               id: rightName
               anchors.centerIn: parent
               text: "return"
            }

            MouseArea {
                anchors.fill: parent
                onClicked: scene.state = "InitialState"
            }
        }

        Rectangle {
            id: ball
            color: "darkgreen"
            x: leftRect.x + 5
            y: leftRect.y + 5
            width: leftRect.width - 10
            height: leftRect.height - 10
            radius: width / 2
        }

        states: [
            State {
                name: "OtherState"
                PropertyChanges {
                    target: ball
                    x: ball.x
                }
            },
            State {
                name: "InitialState"
                PropertyChanges {
                    target: ball
                    x: leftRect.x + 5
                }
            }
        ]

        transitions: [
            Transition {
                from: "OtherState"
                to: "InitialState"

                NumberAnimation {
                    properties: "x,y"
                    duration: 1000
                    easing.type: Easing.InOutExpo
                }
            }
        ]
    }
}
