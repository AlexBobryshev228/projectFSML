import QtQuick
import QtQuick.Controls

ApplicationWindow {
    visible: true
    width: 800
    height: 500

    Row {
        anchors.fill: parent
        spacing: 16
        padding: 16

        Column {
            spacing: 8
            Button { text: "Biceps"; onClicked: app.selectMuscle("biceps") }
            Button { text: "Chest";  onClicked: app.selectMuscle("chest") }
            Text { text: "Selected: " + app.selectedMuscleId }
        }

        Column {
            spacing: 8
            Text { text: app.muscleName; font.pixelSize: 22 }
            Text { text: app.muscleDescription; width: 420; wrapMode: Text.WordWrap }

            ListView {
                width: 420
                height: 300
                model: app.exercises
                delegate: Text { text: "- " + modelData }
            }
        }
    }
}
