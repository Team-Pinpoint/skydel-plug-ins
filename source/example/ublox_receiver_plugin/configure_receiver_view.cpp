#include "configure_receiver_view.h"
#include "ui_configure_receiver_view.h"

ConfigureReceiverView::ConfigureReceiverView(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::ConfigureReceiverView)
{
  ui->setupUi(this);
}

ConfigureReceiverView::~ConfigureReceiverView()
{
  delete ui;
}
