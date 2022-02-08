#include "ublox_receiver_view.h"

#include "ui_ublox_receiver_view.h"
#include "receiver_enums.h"

UbloxReceiverView::UbloxReceiverView(QWidget* parent) : QWidget(parent), ui(new Ui::UbloxReceiverView)
{
  ui->setupUi(this);

  this->startReceiverView = ui->startReceiverView;
  this->connectReceiverView = new ConnectReceiverView();

  connect(ui->connectReceiverButton, &QPushButton::clicked, [this] {
    this->connectReceiverView->show();
    this->connectReceiverView->move(this->geometry().width(), this->geometry().height());
  });
}

UbloxReceiverView::~UbloxReceiverView()
{
  delete ui;
}
