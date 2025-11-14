#ifndef QVIDEOWIDGETDESIGNERPLUGIN_H
#define QVIDEOWIDGETDESIGNERPLUGIN_H

#include <QtUiPlugin/customwidget.h>

class QVideoWidgetDesignerPlugin : public QObject, public QDesignerCustomWidgetInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.Designer.CustomWidget" FILE "qvideowidget.json")
    Q_INTERFACES(QDesignerCustomWidgetInterface)

public:
    QVideoWidgetDesignerPlugin(QObject *parent = nullptr);

    QString name() const override;
    QString group() const override;
    QString toolTip() const override;
    QString whatsThis() const override;
    QString includeFile() const override;
    QIcon icon() const override;
    bool isContainer() const override { return false; }
    QWidget *createWidget(QWidget *parent) override;
    bool isInitialized() const override { return m_initialized; }
    void initialize(QDesignerFormEditorInterface *core) override;
    QString domXml() const override;

private:
    bool m_initialized = false;
};

#endif // QVIDEOWIDGETDESIGNERPLUGIN_H
