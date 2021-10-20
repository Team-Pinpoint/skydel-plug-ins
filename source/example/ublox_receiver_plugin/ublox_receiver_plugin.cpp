#include "ublox_receiver_plugin.h"

#include "ublox_receiver_view.h"

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

    connect(view, &UbloxReceiverView::coldStartClicked, [view]() {
        view->setReceiverStatus(UbloxReceiverView::ReceiverStatus::STARTING);
    });

    connect(view, &UbloxReceiverView::warmStartClicked, [view]() {
        view->setReceiverStatus(UbloxReceiverView::ReceiverStatus::STARTING);
    });

    connect(view, &UbloxReceiverView::hotStartClicked, [view]() {
        view->setReceiverStatus(UbloxReceiverView::ReceiverStatus::STARTING);
    });

    return view;
}
