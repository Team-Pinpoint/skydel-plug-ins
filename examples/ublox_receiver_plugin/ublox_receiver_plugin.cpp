#include "ublox_receiver_plugin.h"

#include <boost/thread.hpp>

#include <QStringList>

#include <set>

#include "command.h"
#include "createReceiverCommand.h"
#include "currentFixCommand.h"
#include "getEnabledConstellationsCommand.h"
#include "getPositionCommand.h"
#include "getTimeCommand.h"
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

  connect(m_view, &UbloxReceiverView::disconnectReceiver, this, &UbloxReceiverPlugin::m_disconnectReceiver);

  connect(m_view, &UbloxReceiverView::startClicked, [this](ReceiverStartType startType) {
    m_startReceiver(startType);
  });

  connect(m_view, &UbloxReceiverView::updateConstellationsInBackend, [this](std::set<Constellation> constellations) {
    // TODO: do this in a thread that dies when its complete
    // TODO: update constellations in backend
    // TODO: wait ~5sec
    m_getConstellations();
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

  boost::thread dataThread([this]() {
    while (true)
    {
      m_updateData();
      usleep(3000000); // update the data every 3 seconds
    }
  });
  dataThread.detach();

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
  m_getConstellations();
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

void UbloxReceiverPlugin::m_updateData()
{
  m_ubloxMutex.lock();

  m_skydelNotifier->notify("Retrieving Position from the Ublox receiver");
  GetPositionCommand positionCommand(m_ubloxReceiver);
  char* position = positionCommand.execute();

  m_skydelNotifier->notify("Retrieving UTC Time from the Ublox receiver");
  GetUTCTimeCommand timeCommand(m_ubloxReceiver);
  char* time = timeCommand.execute();

  if (time[0] != '\0' && position[0] != '\0')
  {
    m_view->displayPositionAndTime(position, time);
  }

  m_ubloxMutex.unlock();
}

void UbloxReceiverPlugin::m_getConstellations()
{
  m_ubloxMutex.lock();
  GetEnabledConstellationsCommand command(m_ubloxReceiver);
  std::set<Constellation> constellations = command.execute();
  QStringList constellationStrings;
  for (Constellation constellation : constellations)
  {
    switch (constellation)
    {
      case Constellation::GPS:
        constellationStrings.append("GPS");
        break;
      case Constellation::GLONASS:
        constellationStrings.append("GLONASS");
        break;
      case Constellation::GALILEO:
        constellationStrings.append("GALELIO");
        break;
      case Constellation::BEIDOU:
        constellationStrings.append("BEIDOU");
        break;
      case Constellation::SBAS:
        constellationStrings.append("SBAS");
        break;
      case Constellation::IMES:
        constellationStrings.append("IMES");
        break;
      case Constellation::QZSS:
        constellationStrings.append("QZSS");
        break;
      default:
        break;
    }
  }
  m_view->updateConstellationsInView(constellationStrings);
  m_ubloxMutex.unlock();
}
