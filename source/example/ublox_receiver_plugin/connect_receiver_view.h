#ifndef CONNECT_RECEIVER_VIEW_H
#define CONNECT_RECEIVER_VIEW_H

#include <QWidget>

namespace Ui {
class ConnectReceiverView;
}

class ConnectReceiverView : public QWidget
{
  Q_OBJECT

public:
  explicit ConnectReceiverView(QWidget *parent = nullptr);
  ~ConnectReceiverView();

signals:
  void connectReceiver();

private:
  Ui::ConnectReceiverView *ui;
};

#endif // CONNECT_RECEIVER_VIEW_H
