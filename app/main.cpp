#include <PluginIf.h>
#include <QApplication>
#include <QDir>
#include <QPluginLoader>
#include <QQuickView>
#include <QDirIterator>

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

int main(int argc, char* argv[])
{
    QGuiApplication app(argc, argv);
    QQuickView viewer;

    loadPlugin();

    viewer.setSource(QUrl("qrc:/main.qml"));
    viewer.show();

    // TEMP: enumerate all files in resource system: //RHV REMOVE
    QDirIterator it(":", QDirIterator::Subdirectories);
    while (it.hasNext()) {
        qDebug() << it.next();
    }


    return app.exec();
}
