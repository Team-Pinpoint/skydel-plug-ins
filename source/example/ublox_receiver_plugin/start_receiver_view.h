#ifndef START_RECEIVER_VIEW_H
#define START_RECEIVER_VIEW_H

#include <QWidget>

namespace Ui {
class StartReceiverView;
}

class StartReceiverView : public QWidget
{
  Q_OBJECT

public:
  explicit StartReceiverView(QWidget *parent = nullptr);
  ~StartReceiverView();
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
  Ui::StartReceiverView *ui;
  ReceiverStatus receiverStatus;
  ReceiverStartType selectedStartType;
};

#endif // START_RECEIVER_VIEW_H
