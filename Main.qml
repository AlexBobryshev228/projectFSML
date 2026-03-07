import QtQuick
import QtQuick.Window

Window {
    id: root
    width: 900
    height: 650
    visible: true
    title: "Body prototype"

    Rectangle {
        anchors.fill: parent
        color: "#151515"
    }

    // Правая панель (просто чтобы видно было реакцию)
    Rectangle {
        id: panel
        width: 280
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        color: "#222"
        border.width: 1
        border.color: "#444"

        Column {
            anchors.fill: parent
            anchors.margins: 16
            spacing: 10

            Text {
                id: titleText
                text: "Выбери мышцу"
                color: "white"
                font.pixelSize: 20
                font.bold: true
            }

            Text {
                id: infoText
                text: "Нажми на зоны на теле слева."
                color: "#cfcfcf"
                wrapMode: Text.WordWrap
                font.pixelSize: 14
            }
        }
    }

    // Контейнер для тела (слева)
    Item {
        id: bodyArea
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.right: panel.left
        anchors.margins: 20
    }

    Item {
        id: human
        width: 260
        height: 520
        anchors.centerIn: bodyArea

        // ===== Голова =====
        Rectangle {
            width: 110
            height: 110
            radius: 55
            color: "#2b2b2b"
            border.width: 3
            border.color: "white"
            anchors.horizontalCenter: parent.horizontalCenter
            y: 20
        }

        // ===== Шея =====
        Rectangle {
            width: 40
            height: 24
            radius: 10
            color: "#2b2b2b"
            border.width: 3
            border.color: "white"
            anchors.horizontalCenter: parent.horizontalCenter
            y: 135
        }

        // ===== Торс =====
        Rectangle {
            id: torso
            width: 170
            height: 220
            radius: 38
            color: "#2b2b2b"
            border.width: 3
            border.color: "white"
            anchors.horizontalCenter: parent.horizontalCenter
            y: 160
        }

        // ===== Таз =====
        Rectangle {
            id: pelvis
            width: 150
            height: 72
            radius: 28
            color: "#2b2b2b"
            border.width: 3
            border.color: "white"
            anchors.horizontalCenter: parent.horizontalCenter
            y: torso.y + torso.height - 10
        }

        // ===== Руки (простые сегменты) =====
        // Левая рука
        Rectangle {
            width: 16; height: 140; radius: 8
            color: "white"; opacity: 0.85
            x: torso.x - 35
            y: torso.y + 35
            rotation: 35
            transformOrigin: Item.Top
        }
        Rectangle {
            width: 16; height: 120; radius: 8
            color: "white"; opacity: 0.85
            x: torso.x - 65
            y: torso.y + 145
            rotation: -20
            transformOrigin: Item.Top
        }

        // Правая рука
        Rectangle {
            width: 16; height: 140; radius: 8
            color: "white"; opacity: 0.85
            x: torso.x + torso.width + 19
            y: torso.y + 35
            rotation: -35
            transformOrigin: Item.Top
        }
        Rectangle {
            width: 16; height: 120; radius: 8
            color: "white"; opacity: 0.85
            x: torso.x + torso.width + 45
            y: torso.y + 145
            rotation: 20
            transformOrigin: Item.Top
        }

        // ===== Ноги =====
        Rectangle {
            width: 18; height: 170; radius: 9
            color: "white"; opacity: 0.9
            x: pelvis.x + 45
            y: pelvis.y + pelvis.height - 5
            rotation: 6
            transformOrigin: Item.Top
        }
        Rectangle {
            width: 18; height: 170; radius: 9
            color: "white"; opacity: 0.9
            x: pelvis.x + pelvis.width - 60
            y: pelvis.y + pelvis.height - 5
            rotation: -6
            transformOrigin: Item.Top
        }

        // ========= КЛИКАБЕЛЬНЫЕ ЗОНЫ (поверх тела) =========

        // Пресс
        Rectangle {
            id: absZone
            x: torso.x + 38
            y: torso.y + 105
            width: torso.width - 76
            height: 85
            radius: 18
            color: "transparent"
            border.width: 2
            border.color: "red"

            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                onEntered: absZone.border.color = "lime"
                onExited: absZone.border.color = "red"
                onClicked: {
                    titleText.text = "Пресс"
                    infoText.text = "Пример: скручивания, подъём ног, планка."
                    console.log("ABS clicked")
                }
            }
        }

        // Правый бицепс (пример)
        Rectangle {
            id: bicepsZone
            x: torso.x + torso.width + 24
            y: torso.y + 85
            width: 55
            height: 70
            radius: 14
            color: "transparent"
            border.width: 2
            border.color: "red"

            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                onEntered: bicepsZone.border.color = "lime"
                onExited: bicepsZone.border.color = "red"
                onClicked: {
                    titleText.text = "Бицепс"
                    infoText.text = "Пример: подъём штанги, подъём гантелей, молотки."
                    console.log("BICEPS clicked")
                }
            }
        }
    }
}
