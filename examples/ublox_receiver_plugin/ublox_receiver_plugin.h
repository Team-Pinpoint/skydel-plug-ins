#ifndef UBLOX_RECEIVER_PLUGIN_H
#define UBLOX_RECEIVER_PLUGIN_H

#include "receiver_enums.h"
#include "skydel_plug_ins/skydel_core_interface.h"
#include "skydel_plug_ins/skydel_plugin.h"
#include "ublox.h"
#include "ublox_receiver_view.h"

using namespace ublox;

// Plugin implementation
class UbloxReceiverPlugin : public QObject, public SkydelCoreInterface
{
  Q_OBJECT

public:
  // SkydelCoreInterface
  inline void setLogPath(const QString&) override {}
  inline void setNotifier(SkydelNotifierInterface* notifier) override { m_skydelNotifier = notifier; }
  void setConfiguration(const QString& version, const QJsonObject& configuration) override;
  QJsonObject getConfiguration() const override;
  QWidget* createUI() override;
  inline void initialize() override {}

signals:
  void configurationChanged();

private:
  SkydelNotifierInterface* m_skydelNotifier;
  UbloxReceiverView* view;
  Ublox* ubloxReceiver;
};

// Required boilerplate
class UbloxReceiverPluginFactory : public QObject, public SkydelPlugin<UbloxReceiverPlugin>
{
  Q_OBJECT
  Q_PLUGIN_METADATA(IID "UbloxReceiverPlugin" FILE "ublox_receiver_plugin.json")
  Q_INTERFACES(SkydelPluginBase)
};

#endif // UBLOX_RECEIVER_PLUGIN_H
