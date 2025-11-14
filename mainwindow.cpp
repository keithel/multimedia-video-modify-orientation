#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "rotationfiltersink.h"
#include <QDir>
#include <QFileInfo>

QFileInfo findFileInAncestors(const QString& fileName)
{
    QDir dir(QDir::current());
    do {
        QFileInfo filePath(dir, fileName);
        if (filePath.exists())
            return filePath;
    }
    while (dir.cdUp());
    return QFileInfo();
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_mediaPlayer(new QMediaPlayer(this))
{
    ui->setupUi(this);

    m_mediaPlayer->setVideoOutput(ui->videoWidget);
    QFileInfo bigBuckBunnyFileInfo = findFileInAncestors("big_buck_bunny_1080p_h264.mov");
    if(bigBuckBunnyFileInfo.exists()) {
        m_mediaPlayer->setSource(QUrl::fromLocalFile(bigBuckBunnyFileInfo.absoluteFilePath()));
        m_mediaPlayer->play();
    }

    QVideoSink *originalSink(ui->videoWidget->videoSink());
    RotationFilterSink *filterSink = new RotationFilterSink(originalSink, this);
    filterSink->setRotation(QtVideo::Rotation::Clockwise90);
    m_mediaPlayer->setVideoSink(filterSink);
}

MainWindow::~MainWindow()
{
    delete ui;
}
