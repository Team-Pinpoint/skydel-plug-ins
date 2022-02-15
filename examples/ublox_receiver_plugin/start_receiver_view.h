#ifndef START_RECEIVER_VIEW_H
#define START_RECEIVER_VIEW_H

#include <QWidget>

#include "receiver_enums.h"

namespace Ui
{
class StartReceiverView;
}

class StartReceiverView : public QWidget
{
  Q_OBJECT

public:
  explicit StartReceiverView(QWidget* parent = nullptr);
  ~StartReceiverView();
  void setReceiverStatus(ReceiverStatus status);

signals:
  void startClicked(ReceiverStartType startType);

private:
  Ui::StartReceiverView* ui;
  ReceiverStatus receiverStatus;
  ReceiverStartType selectedStartType;
};

#endif // START_RECEIVER_VIEW_H
