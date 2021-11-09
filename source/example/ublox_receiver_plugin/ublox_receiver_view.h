#ifndef UBLOXRECEIVERVIEW_H
#define UBLOXRECEIVERVIEW_H

#include <QWidget>
#include "start_receiver_view.h"

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
  StartReceiverView *startReceiverView;

private:
  Ui::UbloxReceiverView* ui;
};
#endif // UBLOXRECEIVERVIEW_H
