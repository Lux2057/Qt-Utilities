import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Dialogs 1.3
import QtMultimedia 5.15

import CppControls 1.0

Window {
    id: root

    width: 640
    maximumWidth: 640
    minimumWidth: 640
    height: 480
    maximumHeight: 480
    minimumHeight: 480
    visible: true

    Column {
        id: recurrentCounterColumn

        leftPadding: 5
        topPadding: 5

        spacing: 5

        RecurrentCounter {
            id: recurrentCounter
        }

        Row {
            id: counter1Row

            spacing: 5

            Row {
                id: counter1Display

                anchors.verticalCenter: parent.verticalCenter

                spacing: 3

                Text {
                    id: counter1Label

                    text: "Counter1:"
                }

                Text {
                    id: counter1

                    text: recurrentCounter.counter1
                }
            }

            Button {
                id: start1Button

                height: 30

                text: "Start"

                visible: !recurrentCounter.isRunning1

                onClicked: recurrentCounter.start1()
            }

            Button {
                id: stop1Button

                height: 30

                text: "Stop"

                visible: recurrentCounter.isRunning1

                onClicked: recurrentCounter.stop1()
            }
        }

        Row {
            id: counter2Row

            spacing: 5

            Row {
                id: counter2Display

                anchors.verticalCenter: parent.verticalCenter

                spacing: 3

                Text {
                    id: counter2Label

                    text: "Counter2:"
                }

                Text {
                    id: counter2

                    text: recurrentCounter.counter2
                }
            }

            Button {
                id: start2Button

                height: 30

                text: "Start"

                visible: !recurrentCounter.isRunning2

                onClicked: recurrentCounter.start2()
            }

            Button {
                id: stop2Button

                height: 30

                text: "Stop"

                visible: recurrentCounter.isRunning2

                onClicked: recurrentCounter.stop2()
            }
        }

        Button {
            id: requestStop

            height: 30

            text: "Request stop"

            onClicked: recurrentCounter.requestStop()
        }
    }
}
