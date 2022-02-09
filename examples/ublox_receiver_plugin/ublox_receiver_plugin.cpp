#include "ublox_receiver_plugin.h"

#include <boost/thread.hpp>

#include "command.h"
#include "createReceiverCommand.h"
#include "receiver_enums.h"
#include "startCommand.h"
#include "ublox.h"
#include "ublox_receiver_view.h"

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

  connect(view->connectReceiverView, &ConnectReceiverView::connectReceiver, [this]() {
    m_skydelNotifier->notify("Connecting to the Ublox receiver");
    // TODO: port is currently hardcoded... need to put code into CreateUbloxReceiver.cpp to find a port
    // with a ublox receiver. Also need to change the ui (should ask for the baud rate but not the port) 
    CreateUbloxReceiverCommand command(9600, "/dev/ttyACM0");
    ubloxReceiver = command.execute();
    view->startReceiverView->setReceiverStatus(ReceiverStatus::INACTIVE);
  });

  connect(view->startReceiverView, &StartReceiverView::startClicked, [this](ReceiverStartType startType) {
    view->startReceiverView->setReceiverStatus(ReceiverStatus::STARTING);
    m_skydelNotifier->notify("Starting the Ublox receiver");
    new boost::thread([this, startType]() {
      ReceiverStartCommand command(this->ubloxReceiver);
      command.execute(startType);
      this->view->startReceiverView->setReceiverStatus(ReceiverStatus::ACTIVE);
    });
  });

  // TODO: add a disconnect butten which calls ubloxReceiver.Disconnect();

  // TODO: could start a thread which goes into a while loop and keeps checking the status of
  // the ubloxReceiver and updating the frontend status (need to add something to ublox.h)

  return view;
}
