import QtQuick

Rectangle {
    color: "black"

    Image {
        id: bodyImage
        anchors.fill: parent
        anchors.margins: 20
        source: "qrc:/qt/qml/ProjectFSML/images/body.png"
        fillMode: Image.PreserveAspectFit
        smooth: true
    }
}
