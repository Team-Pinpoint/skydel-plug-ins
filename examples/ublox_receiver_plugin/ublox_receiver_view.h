#ifndef UBLOXRECEIVERVIEW_H
#define UBLOXRECEIVERVIEW_H

#include <QWidget>

#include <set>

#include "constellation_selection_popup_view.h"
#include "receiver_enums.h"

namespace Ui
{
class UbloxReceiverView;
}

class UbloxReceiverView : public QWidget
{
  Q_OBJECT

public:
  UbloxReceiverView(QWidget* parent = nullptr);
  ~UbloxReceiverView();
  void setReceiverStatus(ReceiverStatus status);
  void displayPositionAndTime(char* position, char* time);
  void updateConstellationsInView(std::set<Constellation> constellations);

signals:
  void connectReceiver(int baudRate);
  void disconnectReceiver();
  void startClicked(ReceiverStartType startType);
  void updateConstellationsInBackend(std::set<Constellation> constellations);

private:
  Ui::UbloxReceiverView* m_ui;
  ConstellationSelectionPopupView* m_constellationSelectionPopupView;
  ReceiverStatus m_receiverStatus;
  ReceiverStartType m_selectedStartType;
  void m_startTypeIndexChanged(int index);
  void m_connectReceiverClicked();
};
#endif // UBLOXRECEIVERVIEW_H
