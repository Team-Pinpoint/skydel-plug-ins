#include "ublox_receiver_plugin.h"

#include <boost/thread.hpp>

#include "command.h"
#include "createReceiverCommand.h"
#include "currentFixCommand.h"
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
    ubloxMutex.lock();
    m_skydelNotifier->notify("Connecting to the Ublox receiver");
    // TODO: port is currently hardcoded... need to put code into CreateUbloxReceiver.cpp to find the port
    if (!ubloxReceiver)
    {
      CreateUbloxReceiverCommand command(baudRate, "/dev/ttyACM0");
      ubloxReceiver = command.execute();
    }
    else if (!ubloxReceiver->IsConnected())
    {
      CreateUbloxReceiverCommand command(baudRate, "/dev/ttyACM0", ubloxReceiver);
      command.execute();
    }
    ubloxMutex.unlock();
  });

  connect(view, &UbloxReceiverView::disconnectReceiver, [this]() {
    ubloxMutex.lock();
    m_skydelNotifier->notify("Disconnecting from the Ublox receiver");
    ubloxReceiver->Disconnect();
    ubloxMutex.unlock();
  });

  connect(view, &UbloxReceiverView::startClicked, [this](ReceiverStartType startType) {
    ubloxMutex.lock();
    m_skydelNotifier->notify("Starting the Ublox receiver");
    ReceiverStartCommand command(this->ubloxReceiver);
    command.execute(startType);
    ubloxMutex.unlock();
  });

  boost::thread statusThread([this]() {
    while (true)
    {
      this->ubloxMutex.lock();
      ReceiverGetFixCommand command(this->ubloxReceiver);
      this->view->setReceiverStatus(command.execute());
      this->ubloxMutex.unlock();
      // check the status every 1 second
      usleep(1000000);
    }
  });
  statusThread.detach();

  return view;
}
