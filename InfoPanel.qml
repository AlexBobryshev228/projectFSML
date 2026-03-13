import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    color: "#1e1e1e"
    radius: 12
    border.color: "#333333"
    border.width: 1

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 16
        spacing: 12

        Label {
            text: "Muscle info"
            color: "white"
            font.pixelSize: 24
            font.bold: true
        }

        Rectangle {
            Layout.fillWidth: true
            Layout.preferredHeight: 1
            color: "#333333"
        }

        Label {
            text: app.muscleName
            color: "#f5f5f5"
            font.pixelSize: 20
            font.bold: true
            wrapMode: Text.WordWrap
            Layout.fillWidth: true
        }

        Label {
            text: app.muscleDescription
            color: "#d0d0d0"
            font.pixelSize: 15
            wrapMode: Text.WordWrap
            Layout.fillWidth: true
        }

        Label {
            text: "Exercises"
            color: "white"
            font.pixelSize: 18
            font.bold: true
            topPadding: 6
        }

        Rectangle {
            Layout.fillWidth: true
            Layout.preferredHeight: 140
            radius: 10
            color: "#2a2a2a"
            border.color: "#3a3a3a"

            ListView {
                anchors.fill: parent
                anchors.margins: 10
                model: app.exerciseList
                spacing: 6
                clip: true

                delegate: Rectangle {
                    width: ListView.view.width
                    height: 34
                    radius: 8
                    color: "#353535"

                    Text {
                        anchors.centerIn: parent
                        text: modelData
                        color: "white"
                        font.pixelSize: 14
                    }
                }
            }
        }

        Label {
            text: "Statistics"
            color: "white"
            font.pixelSize: 18
            font.bold: true
            topPadding: 8
        }

        Rectangle {
            Layout.fillWidth: true
            Layout.preferredHeight: 100
            radius: 10
            color: "#2a2a2a"
            border.color: "#3a3a3a"

            Column {
                anchors.fill: parent
                anchors.margins: 12
                spacing: 8

                Text {
                    text: "Total selections: " + app.totalSelections
                    color: "#f0f0f0"
                    font.pixelSize: 14
                }

                Text {
                    text: "Most viewed: " + app.mostPopularMuscle
                    color: "#f0f0f0"
                    font.pixelSize: 14
                }

                Text {
                    text: "Current muscle clicks: " + app.currentMuscleClicks
                    color: "#f0f0f0"
                    font.pixelSize: 14
                }
            }
        }

        Label {
            text: "Recent muscles"
            color: "white"
            font.pixelSize: 18
            font.bold: true
            topPadding: 8
        }

        Rectangle {
            Layout.fillWidth: true
            Layout.fillHeight: true
            radius: 10
            color: "#2a2a2a"
            border.color: "#3a3a3a"

            ListView {
                anchors.fill: parent
                anchors.margins: 10
                model: app.recentSelections
                spacing: 6
                clip: true

                delegate: Rectangle {
                    width: ListView.view.width
                    height: 34
                    radius: 8
                    color: "#353535"

                    Text {
                        anchors.centerIn: parent
                        text: modelData
                        color: "white"
                        font.pixelSize: 14
                    }
                }
            }
        }
    }
}
