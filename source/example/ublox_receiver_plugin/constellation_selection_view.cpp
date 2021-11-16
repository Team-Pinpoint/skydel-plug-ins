#include "constellation_selection_view.h"

#include <set>

#include "ui_constellation_selection_view.h"

ConstellationSelectionView::ConstellationSelectionView(QWidget* parent) :
  QWidget(parent),
  ui(new Ui::ConstellationSelectionView)
{
  ui->setupUi(this);

  this->selectedConstellations = {};

  connect(ui->gpsCheckBox, &QCheckBox::stateChanged, [this](int selected) {
    constellationClicked(Constellation::GPS, selected);
  });
  connect(ui->glonassCheckBox, &QCheckBox::stateChanged, [this](int selected) {
    constellationClicked(Constellation::GLONASS, selected);
  });
  connect(ui->galileoCheckBox, &QCheckBox::stateChanged, [this](int selected) {
    constellationClicked(Constellation::GALILEO, selected);
  });
  connect(ui->beidouCheckBox, &QCheckBox::stateChanged, [this](int selected) {
    constellationClicked(Constellation::BEIDOU, selected);
  });
  connect(ui->sbasCheckBox, &QCheckBox::stateChanged, [this](int selected) {
    constellationClicked(Constellation::SBAS, selected);
  });
  connect(ui->qzssCheckBox, &QCheckBox::stateChanged, [this](int selected) {
    constellationClicked(Constellation::QZSS, selected);
  });
  connect(ui->navicCheckBox, &QCheckBox::stateChanged, [this](int selected) {
    constellationClicked(Constellation::NAVIC, selected);
  });
  connect(ui->updateConstellationsButton, &QPushButton::clicked, [this] {
    ui->updateConstellationsButton->setEnabled(false);
    emit constellationsUpdated(this->selectedConstellations);
  });
}

ConstellationSelectionView::~ConstellationSelectionView()
{
  delete ui;
}

void ConstellationSelectionView::constellationClicked(Constellation constellation, int selected)
{
  if (selected)
  {
    this->selectedConstellations.insert(constellation);
  }
  else
  {
    this->selectedConstellations.extract(constellation);
  }
  ui->updateConstellationsButton->setEnabled(true);
}
