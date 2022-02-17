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

  connect(view, &UbloxReceiverView::connectReceiver, [this](int baudRate) {
    m_skydelNotifier->notify("Connecting to the Ublox receiver");
    // TODO: port is currently hardcoded... need to put code into CreateUbloxReceiver.cpp to find a port
    // with a ublox receiver. Also need to change the ui (should ask for the baud rate but not the port)
    CreateUbloxReceiverCommand command(baudRate, "/dev/ttyACM0");
    ubloxReceiver = command.execute();
    view->setReceiverStatus(ReceiverStatus::INACTIVE);
  });

  connect(view, &UbloxReceiverView::disconnectReceiver, [this]() {
    m_skydelNotifier->notify("Disconnecting from the Ublox receiver");
    this->ubloxReceiver->Disconnect();
    view->setReceiverStatus(ReceiverStatus::NOT_CONNECTED);
  });

  connect(view, &UbloxReceiverView::startClicked, [this](ReceiverStartType startType) {
    view->setReceiverStatus(ReceiverStatus::STARTING);
    m_skydelNotifier->notify("Starting the Ublox receiver");
    boost::thread startThread([this, startType]() {
      ReceiverStartCommand command(this->ubloxReceiver);
      command.execute(startType);
      this->view->setReceiverStatus(ReceiverStatus::ACTIVE);
    });
    startThread.detach();
  });

  // TODO: could start a thread which goes into a while loop and keeps checking the status of
  // the ubloxReceiver and updating the frontend status (need to add something to ublox.h)

  return view;
}
