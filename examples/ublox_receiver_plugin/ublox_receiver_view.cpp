#include "ublox_receiver_view.h"

#include "receiver_enums.h"
#include "ui_ublox_receiver_view.h"

UbloxReceiverView::UbloxReceiverView(QWidget* parent) : QWidget(parent), ui(new Ui::UbloxReceiverView)
{
  ui->setupUi(this);

  selectedStartType = ReceiverStartType::NONE;
  setReceiverStatus(ReceiverStatus::NOT_CONNECTED);

  connect(ui->startButton, &QPushButton::clicked, [this] {
    ui->startButton->setEnabled(false);
    emit startClicked(this->selectedStartType);
  });

  connect(ui->startTypeSelect, qOverload<int>(&QComboBox::currentIndexChanged), [this](int index) {
    this->selectedStartType = (ReceiverStartType)index;
    if (index == 0)
    {
      ui->startButton->setEnabled(false);
    }
    else if (receiverStatus == ReceiverStatus::ACTIVE || receiverStatus == ReceiverStatus::INACTIVE)
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
  this->receiverStatus = status;
  switch (status)
  {
    case ReceiverStatus::NOT_CONNECTED:
      ui->connectReceiverButton->setText("Connect");
      ui->baudRateSelect->setDisabled(false);
      ui->receiverStatusLabel->setText("[Not Connected]");
      ui->startButton->setDisabled(true);
      break;
    case ReceiverStatus::STARTING:
      ui->connectReceiverButton->setText("Disconnect");
      ui->baudRateSelect->setDisabled(true);
      ui->receiverStatusLabel->setText("[Starting]");
      ui->startButton->setDisabled(true);
      break;
    case ReceiverStatus::INACTIVE:
      ui->connectReceiverButton->setText("Disconnect");
      ui->baudRateSelect->setDisabled(true);
      ui->receiverStatusLabel->setText("[Inactive]");
      if (this->selectedStartType != ReceiverStartType::NONE)
      {
        ui->startButton->setDisabled(false);
      }
      break;
    case ReceiverStatus::ACTIVE:
      ui->connectReceiverButton->setText("Disconnect");
      ui->baudRateSelect->setDisabled(true);
      ui->receiverStatusLabel->setText("[Active]");
      if (this->selectedStartType != ReceiverStartType::NONE)
      {
        ui->startButton->setDisabled(false);
      }
      break;
    default:
      break;
  }
}
