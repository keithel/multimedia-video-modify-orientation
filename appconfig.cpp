#include "appconfig.h"
#include <QtCore/QCoreApplication>
#include <QFileInfo>
#include <QDir>
#include <QCommandLineParser>
#include <QUrl>
#include <QDebug>

QFileInfo findFileInAncestors(const QString& fileName)
{
    QFileInfo filePath(fileName);
    if (filePath.exists())
        return filePath;

    QDir dir(QDir::current());
    do {
        filePath = QFileInfo(dir, fileName);
        if (filePath.exists())
            return filePath;
    }
    while (dir.cdUp());
    return QFileInfo();
}

AppConfig::AppConfig(QObject *parent)
    : QObject{parent}
{
    // I do know that QCoreApplication is around, as this is a QML singleton created by the qml
    // engine, which requires that the application be created before it is instantiated.
    qApp->arguments();

    QCommandLineParser parser;
    parser.addPositionalArgument("source", "a video source filepath or url");
    if(!parser.parse(qApp->arguments())) {
        qFatal() << "Failed to read command line arguments. aborting";
    }

    const QStringList args = parser.positionalArguments();
    if (args.length() > 0)
        m_videoSourcePath = args[0];

    QFileInfo sourceFI = findFileInAncestors(m_videoSourcePath);
    if (sourceFI.exists())
        m_videoSourcePath = sourceFI.absoluteFilePath();
    QUrl sourceUrl = QUrl::fromUserInput(m_videoSourcePath, QString(), QUrl::AssumeLocalFile);
    m_videoSource = sourceUrl.isValid() ? sourceUrl : QUrl::fromLocalFile(m_videoSourcePath);

    qDebug() << "videoSource:" << m_videoSource;
}

AppConfig *AppConfig::instance() {
    if (s_singletonInstance == nullptr)
        s_singletonInstance = new AppConfig(qApp);
    return s_singletonInstance;
}

AppConfig *AppConfig::create(QQmlEngine *, QJSEngine *engine)
{
    if (s_singletonInstance == nullptr)
        instance();

    Q_ASSERT(s_singletonInstance);
    Q_ASSERT(engine->thread() == s_singletonInstance->thread());

    QJSEngine::setObjectOwnership(s_singletonInstance, QJSEngine::CppOwnership);
    return s_singletonInstance;
}

QUrl AppConfig::videoSource() const
{
    return m_videoSource;
}

void AppConfig::setVideoSource(const QUrl &source)
{
    if (m_videoSource != source) {
        m_videoSource = source;
        emit videoSourceChanged();
    }
}
