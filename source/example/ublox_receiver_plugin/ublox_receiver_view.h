#ifndef UBLOXRECEIVERVIEW_H
#define UBLOXRECEIVERVIEW_H

#include <QWidget>

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
  enum class ReceiverStatus
  {
    ACTIVE,
    INACTIVE,
    STARTING,
    NOT_DETECTED
  };
  enum class ReceiverStartType
  {
    NONE = 0,
    COLD = 1,
    WARM = 2,
    HOT = 3
  };

  void setReceiverStatus(ReceiverStatus status);

signals:
  void startClicked(ReceiverStartType startType);

private:
  Ui::UbloxReceiverView* ui;
  ReceiverStatus receiverStatus;
  ReceiverStartType selectedStartType;
};
#endif // UBLOXRECEIVERVIEW_H
