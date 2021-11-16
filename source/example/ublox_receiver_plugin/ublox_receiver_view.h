#ifndef UBLOXRECEIVERVIEW_H
#define UBLOXRECEIVERVIEW_H

#include <QWidget>

#include "connect_receiver_view.h"
#include "constellation_selection_view.h"
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
  StartReceiverView* startReceiverView;
  ConnectReceiverView* connectReceiverView;
  ConstellationSelectionView* constellationSelectionView;

private:
  Ui::UbloxReceiverView* ui;
};
#endif // UBLOXRECEIVERVIEW_H
