#ifndef CONSTELLATION_SELECTION_VIEW_H
#define CONSTELLATION_SELECTION_VIEW_H

#include <QWidget>

#include <set>

namespace Ui
{
class ConstellationSelectionView;
}

class ConstellationSelectionView : public QWidget
{
  Q_OBJECT

public:
  explicit ConstellationSelectionView(QWidget* parent = nullptr);
  ~ConstellationSelectionView();
  enum class Constellation
  {
    GPS,
    GLONASS,
    GALILEO,
    BEIDOU,
    SBAS,
    QZSS,
    NAVIC
  };

signals:
  void constellationsUpdated(std::set<Constellation> constellations);

private:
  Ui::ConstellationSelectionView* ui;
  std::set<Constellation> selectedConstellations;
  void constellationClicked(Constellation constellation, int selected);
};

#endif // CONSTELLATION_SELECTION_VIEW_H
