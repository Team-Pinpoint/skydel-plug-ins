#ifndef UBLOXRECEIVERVIEW_H
#define UBLOXRECEIVERVIEW_H

#include <QStringList>
#include <QWidget>

#include <set>

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
  void setConstellations(QStringList constellationStrings);

signals:
  void connectReceiver(int baudRate);
  void disconnectReceiver();
  void startClicked(ReceiverStartType startType);
  void updateConstellations();

private:
  Ui::UbloxReceiverView* m_ui;
  ReceiverStatus m_receiverStatus;
  ReceiverStartType m_selectedStartType;
  void startTypeIndexChanged(int index);
  void connectReceiverClicked();
};
#endif // UBLOXRECEIVERVIEW_H
