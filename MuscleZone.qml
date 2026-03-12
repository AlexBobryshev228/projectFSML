import QtQuick

Rectangle {
    id: root

    property string muscleId: ""
    property real zoneX: 0
    property real zoneY: 0
    property real zoneW: 100
    property real zoneH: 100

    x: zoneX
    y: zoneY
    width: zoneW
    height: zoneH

    radius: Math.min(width, height) / 2
    color: app.selectedMuscleId === muscleId ? "#66ff6b6b" : "#4470c1ff"
    border.width: l
    border.color: "#88cfff"

    MouseArea {
        anchors.fill: parent
        hoverEnabled: true
        cursorShape: Qt.PointingHandCursor

        onClicked: {
            app.selectMuscle(root.muscleId)
        }

        onEntered: root.opacity = 0.8
        onExited: root.opacity = 1.0
    }
}
