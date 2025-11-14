#pragma once

#include <QObject>
#include <QQmlEngine>

class AppConfig : public QObject
{
    Q_OBJECT
    QML_SINGLETON
    QML_ELEMENT

    Q_PROPERTY(QUrl videoSource READ videoSource WRITE setVideoSource NOTIFY videoSourceChanged)

public:
    explicit AppConfig(QObject *parent);
    ~AppConfig() = default;

    static AppConfig *instance();
    static AppConfig *create(QQmlEngine *, QJSEngine *engine);

    QUrl videoSource() const;
    void setVideoSource(const QUrl &source);

signals:
    void videoSourceChanged();

private:
    QString m_videoSourcePath = "big_buck_bunny_1080p_h264.mov";
    QUrl m_videoSource;

    inline static AppConfig * s_singletonInstance = nullptr;
};
