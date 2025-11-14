#include "rotationfiltersink.h"
#include <QDebug>
#include <QVideoFrame>

RotationFilterSink::RotationFilterSink(QVideoSink *downstreamSink, QObject *parent)
    : QVideoSink(parent)
    , m_downstreamSink(downstreamSink)
{
    if (!m_downstreamSink)
        qWarning() << "RotationFilterSink created with a nul downstream sink!";

    connect(this, &QVideoSink::videoFrameChanged, this, &RotationFilterSink::processFrame);
}

void RotationFilterSink::setRotation(QtVideo::Rotation rotation)
{
    m_rotationOffset = rotation;
}

void RotationFilterSink::processFrame(const QVideoFrame &frame)
{
    if (!m_downstreamSink)
        return;

    int originalRotation = static_cast<int>(frame.rotation());
    int rotationOffset = static_cast<int>(m_rotationOffset);
    QtVideo::Rotation finalRotation = static_cast<QtVideo::Rotation>(
        originalRotation + rotationOffset % 360
    );

    QVideoFrame frameCopy(frame);
    frameCopy.setRotation(finalRotation);

    m_downstreamSink->setVideoFrame(frameCopy);
}
