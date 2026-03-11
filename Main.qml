import QtQuick
import QtQuick.Controls

ApplicationWindow {
    visible: true
    width: 1200
    height: 800
    title: "Muscle Viewer"

    Component.onCompleted: {
        console.log("IMAGE STATUS:", img.status, img.source)
    }
    Image {
        id: img
        anchors.fill: parent
        source: "qrc:/qt/qml/ProjectFSML/assets2/body.png"
    }
}
