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
  m_view = new UbloxReceiverView;

  connect(m_view, &UbloxReceiverView::connectReceiver, [this](int baudRate) { m_connectReceiver(baudRate); });

  connect(m_view, &UbloxReceiverView::disconnectReceiver, this, &UbloxReceiverPlugin::disconnectReceiver);

  connect(m_view, &UbloxReceiverView::startClicked, [this](ReceiverStartType startType) {
    m_startReceiver(startType);
  });

  boost::thread statusThread([this]() {
    while (true)
    {
      m_ubloxMutex.lock();
      ReceiverGetFixCommand command(m_ubloxReceiver);
      m_view->setReceiverStatus(command.execute());
      m_ubloxMutex.unlock();
      usleep(1000000); // check the status every 1 second
    }
  });
  statusThread.detach();

  return m_view;
}

void UbloxReceiverPlugin::m_connectReceiver(int baudRate)
{
  m_ubloxMutex.lock();
  m_skydelNotifier->notify("Connecting to the Ublox receiver");
  if (!m_ubloxReceiver)
  {
    CreateUbloxReceiverCommand command(baudRate);
    m_ubloxReceiver = command.execute();
  }
  else if (!m_ubloxReceiver->IsConnected())
  {
    CreateUbloxReceiverCommand command(baudRate, m_ubloxReceiver);
    command.execute();
  }
  m_ubloxMutex.unlock();
}

void UbloxReceiverPlugin::m_disconnectReceiver()
{
  m_ubloxMutex.lock();
  m_skydelNotifier->notify("Disconnecting from the Ublox receiver");
  m_ubloxReceiver->Disconnect();
  m_ubloxMutex.unlock();
}

void UbloxReceiverPlugin::m_startReceiver(ReceiverStartType startType)
{
  m_ubloxMutex.lock();
  m_skydelNotifier->notify("Starting the Ublox receiver");
  ReceiverStartCommand command(m_ubloxReceiver);
  command.execute(startType);
  m_ubloxMutex.unlock();
}
