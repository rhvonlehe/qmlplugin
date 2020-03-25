#ifndef PLUGIN_H
#define PLUGIN_H

#include <PluginIf.h>
#include <QObject>

class Q_DECL_EXPORT Plugin : public QObject, PluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.example.PluginInterface")
    Q_INTERFACES(PluginInterface)
public:
    void init() override;

};

#endif // PLUGIN_H
