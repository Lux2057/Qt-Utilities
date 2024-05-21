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
            id: counterDisplay

            spacing: 3

            Text {
                id: counterLabel

                text: "Counter:"
            }

            Text {
                id: counter

                text: recurrentCounter.counter
            }
        }

        Button {
            id: startButton

            height: 30

            text: "Start"

            visible: !recurrentCounter.isRunning

            onClicked: recurrentCounter.start()
        }

        Button {
            id: stopButton

            height: 30

            text: "Stop"

            visible: recurrentCounter.isRunning

            onClicked: recurrentCounter.stop()
        }
    }
}
