#include <QApplication>
#include <QDir>
#include <QPluginLoader>
#include <PluginIf.h>

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

    loadPlugin();

    return app.exec();
}
