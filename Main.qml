import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Window {
    id: root
    width: 1200
    height: 800
    visible: true
    title: "Muscle Viewer"
    color: "#111111"

    RowLayout {
        anchors.fill: parent
        spacing: 0

        BodyView {
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        InfoPanel {
            Layout.preferredWidth: 340
            Layout.fillHeight: true
        }
    }

    Column {
        spacing: 8
        width: 240
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.margins: 16

        TextField {
            placeholderText: "Search muscle..."
            onTextChanged: app.setMuscleSearchQuery(text)
        }

        ListView {
            width: parent.width
            height: 200
            model: app.muscleResults

            delegate: Rectangle {
                width: parent.width
                height: 32
                color: "transparent"

                Text {
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    anchors.leftMargin: 8
                    text: modelData
                    color: "white"
                }

                MouseArea {
                    anchors.fill: parent
                    hoverEnabled: true
                    cursorShape: Qt.PointingHandCursor
                    onClicked: app.selectMuscle(modelData)
                }
            }
        }
    }
}
