#ifndef ROTATIONFILTERSINK_H
#define ROTATIONFILTERSINK_H

#include <QVideoSink>
#include <QVideoFrame>

class RotationFilterSink : public QVideoSink
{
    Q_OBJECT
public:
    explicit RotationFilterSink(QVideoSink *downstreamSink, QObject *parent = nullptr);

    void setRotation(QtVideo::Rotation rotation);

private slots:
    void processFrame(const QVideoFrame &frame);

private:
    QVideoSink *m_downstreamSink = nullptr;
    QtVideo::Rotation m_rotationOffset = QtVideo::Rotation::None;
};

#endif // ROTATIONFILTERSINK_H
