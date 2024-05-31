#ifndef MOVECARD_H
#define MOVECARD_H

#include <QWidget>
#include <QLabel>
#include <QDir>
#include "movelabel.h"

namespace Ui {
class MoveCard;
}

class MoveCard : public QWidget
{
    Q_OBJECT

public:
    explicit MoveCard(QVector<QString> attrVector, QWidget *parent = nullptr);
    ~MoveCard();

private:
    Ui::MoveCard *ui;
    QLabel *moveName;
    QLabel *moveDescription;
    MoveLabel *mv;

    QVector<QString> attrVector{};

    QPixmap createPixmap();
};

#endif // MOVECARD_H
