import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    color: "#1c1c1c"
    border.color: "#333333"
    border.width: 1

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 20
        spacing: 14

        Label {
            text: "Информация"
            color: "white"
            font.pixelSize: 26
            font.bold: true
        }

        Rectangle {
            Layout.fillWidth: true
            Layout.preferredHeight: 1
            color: "#333333"
        }

        Label {
            text: app.muscleName === "" ? "Выбери мышцу" : app.muscleName
            color: "#f5f5f5"
            font.pixelSize: 22
            font.bold: true
            wrapMode: Text.WordWrap
            Layout.fillWidth: true
        }

        Label {
            text: app.muscleDescription === "" ? "Нажми на область на теле." : app.muscleDescription
            color: "#cfcfcf"
            font.pixelSize: 16
            wrapMode: Text.WordWrap
            Layout.fillWidth: true
        }

        Label {
            text: "Упражнения"
            color: "white"
            font.pixelSize: 18
            font.bold: true
            topPadding: 10
        }

        Rectangle {
            Layout.fillWidth: true
            Layout.preferredHeight: 150
            radius: 12
            color: "#252525"
            border.color: "#3a3a3a"

            ListView {
                anchors.fill: parent
                anchors.margins: 10
                model: app.exercises
                spacing: 8
                clip: true

                delegate: Rectangle {
                    width: ListView.view.width
                    height: 48
                    radius: 10
                    color: "#323232"

                    Text {
                        anchors.centerIn: parent
                        text: modelData
                        color: "white"
                        font.pixelSize: 15
                    }
                }
            }
        }

        Label {
            text: "Workout plan"
            color: "white"
            font.pixelSize: 18
            font.bold: true
            topPadding: 6
        }

        RowLayout {
            Layout.fillWidth: true
            spacing: 8

            Button {
                text: "Default"
                Layout.fillWidth: true
                onClicked: app.buildWorkoutPlan()
            }

            Button {
                text: "Strength"
                Layout.fillWidth: true
                onClicked: app.buildStrengthPlan()
            }

            Button {
                text: "Endurance"
                Layout.fillWidth: true
                onClicked: app.buildEndurancePlan()
            }
        }

        Label {
            text: app.workoutTitle
            color: "#f5f5f5"
            font.pixelSize: 18
            font.bold: true
            visible: app.workoutTitle.length > 0
            wrapMode: Text.WordWrap
            Layout.fillWidth: true
        }

        Rectangle {
            Layout.fillWidth: true
            Layout.fillHeight: true
            radius: 12
            color: "#252525"
            border.color: "#3a3a3a"

            ListView {
                anchors.fill: parent
                anchors.margins: 10
                model: app.workoutSteps
                spacing: 8
                clip: true

                delegate: Rectangle {
                    width: ListView.view.width
                    height: 48
                    radius: 10
                    color: "#323232"

                    Text {
                        anchors.centerIn: parent
                        text: modelData
                        color: "white"
                        font.pixelSize: 15
                        wrapMode: Text.WordWrap
                    }
                }
            }
        }
    }
}
