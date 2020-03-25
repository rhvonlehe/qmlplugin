#include <PluginIf.h>
#include <QApplication>
#include <QDir>
#include <QPluginLoader>
#include <QQuickView>

bool loadPlugin(void)
{
    QDir pluginsDir(QCoreApplication::applicationDirPath());
    pluginsDir.cdUp();
    pluginsDir.cd("plugin");

    QPluginLoader loader(pluginsDir.absoluteFilePath("plugin.dll"));

    QObject* pluginInst = loader.instance();
    if (pluginInst)
    {
        auto plugin = qobject_cast<PluginInterface*>(pluginInst);
        plugin->init();
        return true;
    }

    return false;
}

int main(int argv, char* args[])
{
    QApplication app(argv, args);
    QQuickView viewer;

    loadPlugin();

    viewer.setSource(QUrl("qrc:/main.qml"));
    viewer.show();

    return app.exec();
}
