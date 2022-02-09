#include "ublox_receiver_plugin.h"

#include "createReceiverCommand.h"
#include "receiver_enums.h"
#include "startCommands.h"
#include "ublox.h"
#include "ublox_receiver_view.h"
#include "command.h"
#include <boost/thread.hpp>

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
    // TODO: port is currently hardcoded... need to put code into CreateUbloxReceiver.cpp to find port
    m_skydelNotifier->notify("Connecting to the Ublox receiver");
    CreateUbloxReceiverCommand command(9600, "/dev/ttyACM0");
    ubloxReceiver = command.execute();
    view->startReceiverView->setReceiverStatus(ReceiverStatus::INACTIVE);
  });

  connect(view->startReceiverView, &StartReceiverView::startClicked, [this](ReceiverStartType startType) {
    view->startReceiverView->setReceiverStatus(ReceiverStatus::STARTING);
    switch (startType)
    {
      case ReceiverStartType::HOT:
      {
        m_skydelNotifier->notify("Hot starting the Ublox receiver");
        new boost::thread([this]()
        {
          ReceiverHotStartCommand command(this->ubloxReceiver);
          command.execute();
          this->view->startReceiverView->setReceiverStatus(ReceiverStatus::ACTIVE);
        });
        break;
      }
      case ReceiverStartType::WARM:
      {
        m_skydelNotifier->notify("Warm starting the Ublox receiver");
        new boost::thread([this]()
        {
          ReceiverWarmStartCommand command(this->ubloxReceiver);
          command.execute();
          this->view->startReceiverView->setReceiverStatus(ReceiverStatus::ACTIVE);
        });
        break;
      }
      default: // By default, run a cold start
      {
        m_skydelNotifier->notify("Cold starting the Ublox receiver");
        new boost::thread([this]()
        {
          ReceiverColdStartCommand command(this->ubloxReceiver);
          command.execute();
          this->view->startReceiverView->setReceiverStatus(ReceiverStatus::ACTIVE);
        });
        break;
      }
    }
  });

  // TODO: add a disconnect butten which calls ubloxReceiver.Disconnect();

  // TODO: could start a thread which goes into a while loop and keeps checking the status of
  // the ubloxReceiver and updating the frontend status (need to add something to ublox.h)

  return view;
}
