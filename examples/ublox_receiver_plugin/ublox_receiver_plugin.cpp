#include "ublox_receiver_plugin.h"

#include "createReceiverCommand.h"
#include "startCommands.h"
#include "ublox.h"
#include "ublox_receiver_view.h"
#include "receiver_enums.h"

using namespace ublox;

void UbloxReceiverPlugin::setConfiguration(const QString& version, const QJsonObject& configuration)
{
  emit configurationChanged();
}

QJsonObject UbloxReceiverPlugin::getConfiguration() const
{
  return {};
}

QWidget* UbloxReceiverPlugin::createUI()
{
  this->view = new UbloxReceiverView;

  connect(view->connectReceiverView,
          &ConnectReceiverView::connectReceiver, [this]() {
            // TODO: port is currently hardcoded... need to put code into CreateUbloxReceiver.cpp to find port
            bool result = ublox_receiver.Connect("/dev/ttyACM0", 9600);
            if (result)
            {
              m_skydelNotifier->notify("Successfully connected to the Ublox receiver");
              view->startReceiverView->setReceiverStatus(ReceiverStatus::INACTIVE);
            }
            else
            {
              m_skydelNotifier->notify("Failed to connect to the Ublox receiver");
            }
          });

  connect(view->startReceiverView,
          &StartReceiverView::startClicked, [this](ReceiverStartType startType) {
            switch (startType)
            {
              case ReceiverStartType::COLD:
              {
                m_skydelNotifier->notify("Cold starting the Ublox receiver");
                ReceiverColdStartCommand command(&ublox_receiver);
                command.execute();
                break;
              }
              case ReceiverStartType::WARM:
              {
                m_skydelNotifier->notify("Warm starting the Ublox receiver");
                ReceiverWarmStartCommand command(&ublox_receiver);
                command.execute();
                break;
              }
              case ReceiverStartType::HOT:
              {
                m_skydelNotifier->notify("Hot starting the Ublox receiver");
                ReceiverHotStartCommand command(&ublox_receiver);
                command.execute();
                break;
              }
              default:
                break;
            }
            view->startReceiverView->setReceiverStatus(ReceiverStatus::STARTING);
            // TODO: skydel is freezing up and needs a force quit after calling command.execute()
          });

  // TODO: Should we have the plugin call ublox_receiver.Disconnect(); when everything is destroyed?

  return view;
}
