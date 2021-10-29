#ifndef CONFIGURE_RECEIVER_VIEW_H
#define CONFIGURE_RECEIVER_VIEW_H

#include <QWidget>

namespace Ui {
class ConfigureReceiverView;
}

class ConfigureReceiverView : public QWidget
{
  Q_OBJECT

public:
  explicit ConfigureReceiverView(QWidget *parent = nullptr);
  ~ConfigureReceiverView();

private:
  Ui::ConfigureReceiverView *ui;
};

#endif // CONFIGURE_RECEIVER_VIEW_H
