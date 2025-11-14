#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "rotationfiltersink.h"
#include "appconfig.h"
#include <QDir>
#include <QFileInfo>
#include <QQuickItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_mediaPlayer(new QMediaPlayer(this))
{
    ui->setupUi(this);

    m_mediaPlayer->setVideoOutput(ui->videoWidget);
    m_mediaPlayer->setSource(AppConfig::instance()->videoSource());
    m_mediaPlayer->play();

    QVideoSink *originalSink(ui->videoWidget->videoSink());
    RotationFilterSink *filterSink = new RotationFilterSink(originalSink, this);
    filterSink->setRotation(QtVideo::Rotation::Clockwise90);
    m_mediaPlayer->setVideoSink(filterSink);

    QMetaObject::invokeMethod(ui->quickWidget->rootObject(), "play", Qt::QueuedConnection, QVariant(false));
}

MainWindow::~MainWindow()
{
    delete ui;
}
