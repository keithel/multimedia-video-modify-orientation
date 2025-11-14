#include "qvideowidgetdesignerplugin.h"
#include <QtMultimediaWidgets/QVideoWidget>
#include <QDir>
#include <QStringList>

using namespace Qt::StringLiterals;

static constexpr auto toolTipC = "A widget for displaying video, from the Qt Multimedia module."_L1;

QVideoWidgetDesignerPlugin::QVideoWidgetDesignerPlugin(QObject *parent)
    : QObject(parent)
{
}

QString QVideoWidgetDesignerPlugin::name() const
{
    return u"QVideoWidget"_s;
}

QString QVideoWidgetDesignerPlugin::group() const
{
    return u"Display Widgets"_s;
}

QString QVideoWidgetDesignerPlugin::toolTip() const
{
    return toolTipC;
}

QString QVideoWidgetDesignerPlugin::whatsThis() const
{
    return toolTipC;
}

QString QVideoWidgetDesignerPlugin::includeFile() const
{
    return u"<QtMultimediaWidgets/QVideoWidget>"_s;
}

QIcon QVideoWidgetDesignerPlugin::icon() const
{
    return QIcon(u":/images/qvideowidget.png"_s);
}

QWidget *QVideoWidgetDesignerPlugin::createWidget(QWidget *parent)
{
    return new QVideoWidget(parent);
}

void QVideoWidgetDesignerPlugin::initialize(QDesignerFormEditorInterface *)
{
    if (m_initialized)
        return;

    m_initialized = true;
}

QString QVideoWidgetDesignerPlugin::domXml() const
{
    return QStringLiteral(R"(
<ui language="c++">
    <widget class="QVideoWidget" name="videoWidget">
        <property name="geometry">
            <rect>
                <x>0</x>
                <y>0</y>
                <width>300</width>
                <height>200</height>
            </rect>
        </property>
    </widget>
</ui>
)"  );
}
