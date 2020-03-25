#include <QtPlugin>

class PluginInterface
{
public:
    virtual ~PluginInterface() = default;
    virtual void init(void) = 0;
};

#define PluginInterface_iid "org.example.PluginInterface"

Q_DECLARE_INTERFACE(PluginInterface, PluginInterface_iid)
