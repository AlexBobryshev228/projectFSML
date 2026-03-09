import QtQuick
import QtQuick.Controls

ApplicationWindow {
    visible: true
    visibility: Window.FullScreen   //changed by fedya (настоящий полноэкранный режим)
    title: "Muscle Viewer"

    Image {
        anchors.fill: parent
        source: "qrc:/assets/Силуэты-мышц-человека-на-черном-фоне.svg"

        fillMode: Image.Stretch   //changed by fedya
    }
}
