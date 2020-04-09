#include <Plugin.h>
#include <QQmlEngine>

void Plugin::init(void)
{
    qmlRegisterSingletonType(QUrl("qrc:///MySingleton.qml"), "org.example.PluginInterface", 1, 0, "MySingleton");
}
