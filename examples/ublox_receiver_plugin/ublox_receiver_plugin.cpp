#include "ublox_receiver_plugin.h"

#include "ublox_receiver_view.h"

#include "ublox.h"
#include "createReceiverCommand.h"
#include "startCommands.h"

using namespace ublox;

void UbloxReceiverPlugin::setConfiguration(const QString& version, const QJsonObject& configuration)
{
  m_skydelNotifier->notify("UBLOX PLUGIN BUILT");
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

  m_skydelNotifier->notify("WE CONSTRUCTRED THE UBLOX RECEIVER");

  // Connect to Receiver
  bool result = my_gps.Connect("/dev/ttyACM0", 9600);

  m_skydelNotifier->notify("UBLOX CONNECTION WAS: ");
  m_skydelNotifier->notify(result ? "true" : "false");
/*
  // request position message
  my_gps.ConfigureMessageRate(0x01,0x03,1);

  m_skydelNotifier->notify("WE CONFIGD THE MSG RATE");


  ReceiverColdStartCommand coldstartcmd(&my_gps);
  coldstartcmd.execute();
*/
  my_gps.Disconnect();
  m_skydelNotifier->notify("UBLOX DISCONNECTED");


  return view;
}
