#include "ublox_receiver_view.h"

#include <string.h>

#include <QStringList>

#include "receiver_enums.h"
#include "ui_ublox_receiver_view.h"

UbloxReceiverView::UbloxReceiverView(QWidget* parent) :
  QWidget(parent),
  m_ui(new Ui::UbloxReceiverView),
  m_receiverStatus(ReceiverStatus::NOT_CONNECTED),
  m_selectedStartType(ReceiverStartType::NONE)
{
  m_ui->setupUi(this);

  setReceiverStatus(ReceiverStatus::NOT_CONNECTED);

  connect(m_ui->startButton, &QPushButton::clicked, [this] { emit startClicked(m_selectedStartType); });

  connect(m_ui->startTypeSelect,
          qOverload<int>(&QComboBox::currentIndexChanged),
          this,
          &UbloxReceiverView::startTypeIndexChanged);

  connect(m_ui->connectReceiverButton, &QPushButton::clicked, this, &UbloxReceiverView::connectReceiverClicked);

  connect(m_ui->updateConstellationsButton, &QPushButton::clicked, this, &UbloxReceiverView::updateConstellations);
}

UbloxReceiverView::~UbloxReceiverView()
{
  delete m_ui;
}

void UbloxReceiverView::setReceiverStatus(ReceiverStatus status)
{
  if (m_receiverStatus == status)
  {
    return;
  }
  m_receiverStatus = status;

  // Handling NOT_CONNECTED status seperatly
  if (status == ReceiverStatus::NOT_CONNECTED)
  {
    m_ui->connectReceiverButton->setText("Connect");
    m_ui->baudRateSelect->setEnabled(true);
    m_ui->receiverStatusLabel->setText("[Not Connected]");
    m_ui->startButton->setEnabled(false);
    m_ui->updateConstellationsButton->setEnabled(false);
    return;
  }

  // Updating connect receiver button, baud rate input, update constellations button, and the start button
  m_ui->connectReceiverButton->setText("Disconnect");
  m_ui->baudRateSelect->setEnabled(false);
  m_ui->updateConstellationsButton->setEnabled(true);
  if (m_selectedStartType != ReceiverStartType::NONE)
  {
    m_ui->startButton->setEnabled(true);
  }

  // Updating the receiver status label
  switch (status)
  {
    case ReceiverStatus::FIX_1D:
      m_ui->receiverStatusLabel->setText("[1D Fix]");
      break;
    case ReceiverStatus::FIX_2D:
      m_ui->receiverStatusLabel->setText("[2D Fix]");
      break;
    case ReceiverStatus::FIX_3D:
      m_ui->receiverStatusLabel->setText("[3D Fix]");
      break;
    case ReceiverStatus::GPS_AND_DEAD_RECKONING:
      m_ui->receiverStatusLabel->setText("[GPS and Dead Reckoning]");
      break;
    case ReceiverStatus::TIME_ONLY:
      m_ui->receiverStatusLabel->setText("[Time Only]");
      break;
    default:
      m_ui->receiverStatusLabel->setText("[No Fix]");
      break;
  }
}

void UbloxReceiverView::displayPositionAndTime(char* position, char* time)
{
  strcat(time, "\t");
  strcat(time, position);
  m_ui->dataListWidget->addItem(time);
}

void UbloxReceiverView::setConstellations(QStringList constellationStrings)
{
  m_ui->constellationListWidget->clear();
  m_ui->constellationListWidget->addItems(QStringList(constellationStrings));
}

void UbloxReceiverView::startTypeIndexChanged(int index)
{
  m_selectedStartType = (ReceiverStartType)index;
  if (index == 0)
  {
    m_ui->startButton->setEnabled(false);
  }
  else if (m_receiverStatus != ReceiverStatus::NOT_CONNECTED)
  {
    m_ui->startButton->setEnabled(true);
  }
}

void UbloxReceiverView::connectReceiverClicked()
{
  if (m_receiverStatus == ReceiverStatus::NOT_CONNECTED)
  {
    int baudRate = m_ui->baudRateSelect->currentText().toInt();
    emit connectReceiver(baudRate);
    m_ui->dataListWidget->clear();
  }
  else
  {
    setConstellations({});
    emit disconnectReceiver();
  }
}
