import QtQuick
import QtQuick.Layouts
import QtMultimedia
import multimediaVideoModifyOrientation

Item {
    function stop() {
        player.stop();
    }
    function play(withAudio) {
        player.play();
        if (!withAudio)
            player.audioOutput = null
    }

    MediaPlayer {
        id: player
        source: AppConfig.videoSource
        videoOutput: videoOut
        audioOutput: AudioOutput {}
    }

    VideoOutput {
        id: videoOut
        rotation: 90
        x: -parent.width
        y: 0
        width: parent.height
        height: parent.width
        anchors.centerIn: parent
    }
}
