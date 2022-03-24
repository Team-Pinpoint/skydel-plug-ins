#include "constellation_selection_popup_view.h"

#include <set>

#include "receiver_enums.h"
#include "ui_constellation_selection_popup_view.h"

ConstellationSelectionPopupView::ConstellationSelectionPopupView(QWidget* parent) :
  QWidget(parent),
  m_ui(new Ui::ConstellationSelectionPopupView)
{

  m_ui->setupUi(this);

  connect(m_ui->submitConstellationsButton,
          &QPushButton::clicked,
          this,
          &ConstellationSelectionPopupView::m_submitConstellationsClicked);
}

ConstellationSelectionPopupView::~ConstellationSelectionPopupView()
{
  delete m_ui;
}

void ConstellationSelectionPopupView::m_submitConstellationsClicked()
{
  std::set<Constellation> constellations = {};
  if (m_ui->gpsCheckBox->isChecked())
  {
    constellations.insert(Constellation::GPS);
  }
  if (m_ui->glonassCheckBox->isChecked())
  {
    constellations.insert(Constellation::GLONASS);
  }
  if (m_ui->galileoCheckBox->isChecked())
  {
    constellations.insert(Constellation::GALILEO);
  }
  if (m_ui->beidouCheckBox->isChecked())
  {
    constellations.insert(Constellation::BEIDOU);
  }
  if (m_ui->sbasCheckBox->isChecked())
  {
    constellations.insert(Constellation::SBAS);
  }
  if (m_ui->qzssCheckBox->isChecked())
  {
    constellations.insert(Constellation::QZSS);
  }
  if (m_ui->navicCheckBox->isChecked())
  {
    constellations.insert(Constellation::NAVIC);
  }

  emit updateConstellations(constellations);
  for (QCheckBox* cb : findChildren<QCheckBox*>())
  {
    cb->setChecked(false);
  }

  hide();
}
