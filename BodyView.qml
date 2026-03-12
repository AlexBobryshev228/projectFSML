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
    Repeater {
        model: regionModel
        delegate: Clickablemusclesnorm {
            imageItem: bodyImage
            muscleId: model.id
            nx: model.nx
            ny: model.ny
            nw: model.nw
            nh: model.nh
        }
    }
}
