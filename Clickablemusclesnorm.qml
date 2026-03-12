import QtQuick

Item {
    id: root
    property Item imageItem
    property string muscleId: ""
    property real nx: 0
    property real ny: 0
    property real nw: 0.1
    property real nh: 0.1
    property bool alwaysVisible: true

    readonly property bool isSelected: app.selectedMuscleId === muscleId
    readonly property bool isHover: mouse.containsMouse

    function ox() { return (imageItem.width  - imageItem.paintedWidth)  / 2 }
    function oy() { return (imageItem.height - imageItem.paintedHeight) / 2 }

    x: imageItem.x + ox() + nx * imageItem.paintedWidth
    y: imageItem.y + oy() + ny * imageItem.paintedHeight
    width:  nw * imageItem.paintedWidth
    height: nh * imageItem.paintedHeight

    Rectangle {
        anchors.fill: parent
        radius: 10
        color: isSelected ? "#66ff6b6b"
             : isHover    ? "#FFB74D00"
             : (alwaysVisible ? "#55ff9800" : "#00000000")
        border.color: isSelected ? "#ff4040"
                   : isHover    ? "#FFE600"
                   : (alwaysVisible ? "#FFB74D" : "#00000000")
        border.width: isSelected ? 3 : (isHover ? 2 : 1)
    }

    MouseArea {
        id: mouse
        anchors.fill: parent
        hoverEnabled: true
        cursorShape: Qt.PointingHandCursor
        onClicked: app.selectMuscle(root.muscleId)
    }
}
