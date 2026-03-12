import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
    visible: true
    width: 1200
    height: 800
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
}
