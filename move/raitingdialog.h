#ifndef RAITINGDIALOG_H
#define RAITINGDIALOG_H

#include <QDialog>
#include <QDir>
#include <QSettings>
#include "movelabel.h"

namespace Ui {
class RaitingDialog;
}

class RaitingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RaitingDialog(QMap<int, QVector<QString> > filmTable, QWidget *parent = nullptr);
    ~RaitingDialog();

private slots:

private:
    Ui::RaitingDialog *ui;
    MoveLabel *mv{};
    QSettings *settings{};

protected:
    void resizeEvent(QResizeEvent *event) override;
};

#endif // RAITINGDIALOG_H
