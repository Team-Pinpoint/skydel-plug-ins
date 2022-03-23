#ifndef UBLOXRECEIVERVIEW_H
#define UBLOXRECEIVERVIEW_H

#include <QWidget>

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

signals:
  void connectReceiver(int baudRate);
  void disconnectReceiver();
  void startClicked(ReceiverStartType startType);

private:
  Ui::UbloxReceiverView* m_ui;
  ReceiverStatus m_receiverStatus;
  ReceiverStartType m_selectedStartType;
  void m_startTypeIndexChanged(int index);
  void m_connectReceiverClicked();
};
#endif // UBLOXRECEIVERVIEW_H
