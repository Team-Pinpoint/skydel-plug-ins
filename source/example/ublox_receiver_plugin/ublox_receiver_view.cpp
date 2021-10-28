#include "ublox_receiver_view.h"

#include "ui_ublox_receiver_view.h"

UbloxReceiverView::UbloxReceiverView(QWidget* parent) : QWidget(parent), ui(new Ui::UbloxReceiverView)
{
  ui->setupUi(this);

  this->startReceiverView = new StartReceiverView();
}

UbloxReceiverView::~UbloxReceiverView()
{
  delete ui;
}
