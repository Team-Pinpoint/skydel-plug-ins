#include "ublox_receiver_plugin.h"

#include "ublox_receiver_view.h"

#include "ublox.h"
#include "createRecieverCommand.h"
#include "startCommands.h"

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
  auto view = new UbloxReceiverView;
  auto startReceiverView = view->startReceiverView;

  connect(startReceiverView,
          &StartReceiverView::startClicked,
          [startReceiverView](StartReceiverView::ReceiverStartType startType) {
            startReceiverView->setReceiverStatus(StartReceiverView::ReceiverStatus::STARTING);
          });


  Ublox my_gps;

  // Connect to Receiver
  bool result = my_gps.Connect("/dev/ttyACM0", 9600);

  // request position message
  my_gps.ConfigureMessageRate(0x01,0x03,1);

  my_gps.Disconnect();

  return view;
}
