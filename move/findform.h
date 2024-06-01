#ifndef FINDFORM_H
#define FINDFORM_H

#include <QWidget>
#include "movelabel.h"

namespace Ui {
class FindForm;
}

class FindForm : public QWidget
{
    Q_OBJECT

public:
    explicit FindForm(QMap<int, QVector<QString> > filmTable, QWidget *parent = nullptr);
    ~FindForm();

private slots:
    void on_le_find_textChanged(const QString &arg1);

private:
    Ui::FindForm *ui;
    void updateFilmList(const QString &subStr = "");
    QMap<int, QVector<QString>> filmTable{};
};

#endif // FINDFORM_H
