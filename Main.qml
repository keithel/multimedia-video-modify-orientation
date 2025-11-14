import QtQuick
import QtQuick.Controls

ApplicationWindow {
    title: "Quick Video Orientation Test"
    width: 540
    height: 960
    visible: true

    onClosing: videoItem.stop();

    RotatedVideoItem {
        id: videoItem
        anchors.fill: parent
        Component.onCompleted: play(true);
    }
}
