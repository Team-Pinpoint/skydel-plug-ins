#include "ublox_receiver_view.h"

#include "ui_ublox_receiver_view.h"

UbloxReceiverView::UbloxReceiverView(QWidget* parent) : QWidget(parent), ui(new Ui::UbloxReceiverView)
{
  ui->setupUi(this);

  this->startReceiverView = new StartReceiverView();
  this->connectReceiverView = new ConnectReceiverView();
  this->constellationSelectionView = new ConstellationSelectionView();

  connect(ui->connectReceiverButton, &QPushButton::clicked, [this] {
    this->connectReceiverView->show();
    this->connectReceiverView->move(this->geometry().width(), this->geometry().height());
  });
}

UbloxReceiverView::~UbloxReceiverView()
{
  delete ui;
}
