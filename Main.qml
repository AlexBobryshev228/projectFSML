import QtQuick
import QtQuick.Controls

ApplicationWindow {
    visible: true
    visibility: Window.FullScreen   //changed by fedya (настоящий полноэкранный режим)
    title: "Muscle Viewer"
    color: "red"

    Image {
        anchors.fill: parent
        source: "qrc:/assets/Силуэты-мышц-человека-на-черном-фоне.svg"

    }
}
