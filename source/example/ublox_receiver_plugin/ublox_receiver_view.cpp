#include "ublox_receiver_view.h"
#include "ui_ublox_receiver_view.h"

UbloxReceiverView::UbloxReceiverView(QWidget *parent) : QWidget(parent), ui(new Ui::UbloxReceiverView)
{
    ui->setupUi(this);

    setReceiverStatus(ReceiverStatus::INACTIVE);

    connect(ui->coldStartButton, &QPushButton::clicked, this, &UbloxReceiverView::coldStartClicked);
    connect(ui->warmStartButton, &QPushButton::clicked, this, &UbloxReceiverView::warmStartClicked);
    connect(ui->hotStartButton, &QPushButton::clicked, this, &UbloxReceiverView::hotStartClicked);
}

UbloxReceiverView::~UbloxReceiverView() { delete ui; }

void UbloxReceiverView::setReceiverStatus(ReceiverStatus status)
{
    switch(status) {
        case ReceiverStatus::NOT_DETECTED :
            ui->receiverStatusLabel->setText("Not Detected");
            ui->receiverStatusLabel->setStyleSheet("QLabel {color : black; }");
            ui->coldStartButton->setDisabled(true);
            ui->warmStartButton->setDisabled(true);
            ui->hotStartButton->setDisabled(true);
            break;
        case ReceiverStatus::STARTING :
            ui->receiverStatusLabel->setText("Starting");
            ui->receiverStatusLabel->setStyleSheet("QLabel {color : olive; }");
            ui->coldStartButton->setDisabled(true);
            ui->warmStartButton->setDisabled(true);
            ui->hotStartButton->setDisabled(true);
            break;
        case ReceiverStatus::INACTIVE :
            ui->receiverStatusLabel->setText("Inactive");
            ui->receiverStatusLabel->setStyleSheet("QLabel {color : red; }");
            ui->coldStartButton->setDisabled(false);
            ui->warmStartButton->setDisabled(false);
            ui->hotStartButton->setDisabled(false);
            break;
        case ReceiverStatus::ACTIVE :
            ui->receiverStatusLabel->setText("Active");
            ui->receiverStatusLabel->setStyleSheet("QLabel {color : green; }");
            ui->coldStartButton->setDisabled(false);
            ui->warmStartButton->setDisabled(false);
            ui->hotStartButton->setDisabled(false);
            break;
        default :
            break;
    }
}
