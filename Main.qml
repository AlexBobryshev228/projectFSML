import QtQuick
import QtQuick.Controls

ApplicationWindow {
    visible: true
    width: 800
    height: 500
    title: "UI check"

    Column {
        anchors.centerIn: parent
        spacing: 10

        Text { text: "Muscles"; font.pixelSize: 30 }

        Button {
            text: "Biceps"
            onClicked: app.selectMuscle("biceps")
        }

        Button {
            text: "Chest"
            onClicked: app.selectMuscle("chest")
        }
        Text { text: "Name: " + app.muscleName }
        Text { text: "Desc: " + app.muscleDescription; width: 500; wrapMode: Text.WordWrap }

        ListView {
            width: 500
            height: 200
            model: app.exercises
            delegate: Text { text: "- " + modelData }
        }
    }
}
