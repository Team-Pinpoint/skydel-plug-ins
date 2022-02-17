#ifndef UBLOXRECEIVERVIEW_H
#define UBLOXRECEIVERVIEW_H

#include <QWidget>

#include "receiver_enums.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
class UbloxReceiverView;
}
QT_END_NAMESPACE

class UbloxReceiverView : public QWidget
{
  Q_OBJECT

public:
  UbloxReceiverView(QWidget* parent = nullptr);
  ~UbloxReceiverView();
  void setReceiverStatus(ReceiverStatus status);

signals:
  void connectReceiver(int baudRate);
  void disconnectReceiver();
  void startClicked(ReceiverStartType startType);

private:
  Ui::UbloxReceiverView* ui;
  ReceiverStatus receiverStatus;
  ReceiverStartType selectedStartType;
};
#endif // UBLOXRECEIVERVIEW_H
