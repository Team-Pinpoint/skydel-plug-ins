#include "connect_receiver_view.h"
#include "ui_connect_receiver_view.h"

ConnectReceiverView::ConnectReceiverView(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::ConnectReceiverView)
{
  ui->setupUi(this);

  connect(ui->connectReceiverDialogButtons, &QDialogButtonBox::accepted, [this] {
    emit connectReceiver();
    this->hide();
  });

  connect(ui->connectReceiverDialogButtons, &QDialogButtonBox::rejected, [this] {
    this->hide();
  });
}

ConnectReceiverView::~ConnectReceiverView()
{
  delete ui;
}
