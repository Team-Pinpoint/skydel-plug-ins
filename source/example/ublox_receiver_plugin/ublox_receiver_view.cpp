#include "ublox_receiver_view.h"

#include "ui_ublox_receiver_view.h"

UbloxReceiverView::UbloxReceiverView(QWidget* parent) : QWidget(parent), ui(new Ui::UbloxReceiverView)
{
  ui->setupUi(this);

  setReceiverStatus(ReceiverStatus::INACTIVE);

  connect(ui->startButton, &QPushButton::clicked, [this] {
    ui->startButton->setEnabled(false);
    ui->startTypeSelect->setCurrentIndex(0);
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
    case ReceiverStatus::NOT_DETECTED:
      ui->receiverStatusLabel->setText("[Not Detected]");
      ui->startButton->setDisabled(true);
      break;
    case ReceiverStatus::STARTING:
      ui->receiverStatusLabel->setText("[Starting]");
      ui->startButton->setDisabled(true);
      break;
    case ReceiverStatus::INACTIVE:
      ui->receiverStatusLabel->setText("[Inactive]");
      if (this->selectedStartType != ReceiverStartType::NONE)
      {
        ui->startButton->setDisabled(false);
      }
      break;
    case ReceiverStatus::ACTIVE:
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
