#ifndef UBLOXRECEIVERVIEW_H
#define UBLOXRECEIVERVIEW_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class UbloxReceiverView; }
QT_END_NAMESPACE

class UbloxReceiverView : public QWidget
{
    Q_OBJECT

public:
    UbloxReceiverView(QWidget *parent = nullptr);
    ~UbloxReceiverView();
    enum class ReceiverStatus { ACTIVE, INACTIVE, STARTING, NOT_DETECTED };
    void setReceiverStatus(ReceiverStatus status);

signals:
    void coldStartClicked();
    void warmStartClicked();
    void hotStartClicked();

private:
    Ui::UbloxReceiverView *ui;
};
#endif // UBLOXRECEIVERVIEW_H
