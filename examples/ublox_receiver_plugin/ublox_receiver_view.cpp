#include "ublox_receiver_view.h"

#include "receiver_enums.h"
#include "ui_ublox_receiver_view.h"

UbloxReceiverView::UbloxReceiverView(QWidget* parent) : QWidget(parent), ui(new Ui::UbloxReceiverView)
{
  ui->setupUi(this);

  selectedStartType = ReceiverStartType::NONE;
  setReceiverStatus(ReceiverStatus::NOT_CONNECTED);

  connect(ui->startButton, &QPushButton::clicked, [this] { emit startClicked(this->selectedStartType); });

  connect(ui->startTypeSelect, qOverload<int>(&QComboBox::currentIndexChanged), [this](int index) {
    this->selectedStartType = (ReceiverStartType)index;
    if (index == 0)
    {
      ui->startButton->setEnabled(false);
    }
    else if (receiverStatus != ReceiverStatus::NOT_CONNECTED)
    {
      ui->startButton->setEnabled(true);
    }
  });

  connect(ui->connectReceiverButton, &QPushButton::clicked, [this] {
    if (this->receiverStatus == ReceiverStatus::NOT_CONNECTED)
    {
      int baudRate = ui->baudRateSelect->currentText().toInt();
      emit connectReceiver(baudRate);
    }
    else
    {
      emit disconnectReceiver();
    }
  });
}

UbloxReceiverView::~UbloxReceiverView()
{
  delete ui;
}

void UbloxReceiverView::setReceiverStatus(ReceiverStatus status)
{
  if (this->receiverStatus == status)
  {
    return;
  }
  this->receiverStatus = status;

  // Handling NOT_CONNECTED status seperatly
  if (status == ReceiverStatus::NOT_CONNECTED)
  {
    ui->connectReceiverButton->setText("Connect");
    ui->baudRateSelect->setDisabled(false);
    ui->receiverStatusLabel->setText("[Not Connected]");
    ui->startButton->setDisabled(true);
    return;
  }

  // Updating connect receiver button, baud rate input, and the start button
  ui->connectReceiverButton->setText("Disconnect");
  ui->baudRateSelect->setDisabled(true);
  if (this->selectedStartType != ReceiverStartType::NONE)
  {
    ui->startButton->setDisabled(false);
  }

  // Updating the receiver status label
  switch (status)
  {
    case ReceiverStatus::FIX_1D:
      ui->receiverStatusLabel->setText("[1D Fix]");
      break;
    case ReceiverStatus::FIX_2D:
      ui->receiverStatusLabel->setText("[2D Fix]");
      break;
    case ReceiverStatus::FIX_3D:
      ui->receiverStatusLabel->setText("[3D Fix]");
      break;
    case ReceiverStatus::GPS_AND_DEAD_RECKONING:
      ui->receiverStatusLabel->setText("[GPS and Dead Reckoning]");
      break;
    case ReceiverStatus::TIME_ONLY:
      ui->receiverStatusLabel->setText("[Time Only]");
      break;
    default:
      ui->receiverStatusLabel->setText("[No Fix]");
      break;
  }
}
