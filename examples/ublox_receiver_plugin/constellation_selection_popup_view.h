#ifndef CONSTELLATION_SELECTION_POPUP_VIEW_H
#define CONSTELLATION_SELECTION_POPUP_VIEW_H

#include <QWidget>

#include <set>

#include "receiver_enums.h"

namespace Ui
{
class ConstellationSelectionPopupView;
}

class ConstellationSelectionPopupView : public QWidget
{
  Q_OBJECT

public:
  explicit ConstellationSelectionPopupView(QWidget* parent = nullptr);
  ~ConstellationSelectionPopupView();

signals:
  void updateConstellations(std::set<Constellation> constellations);

private:
  Ui::ConstellationSelectionPopupView* m_ui;
  void m_submitConstellationsClicked();
};

#endif // CONSTELLATION_SELECTION_POPUP_VIEW_H
