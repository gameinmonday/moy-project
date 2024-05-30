#include "movelabel.h"

MoveLabel::MoveLabel(QString fileName, QWidget *parent)
    : QLabel(parent),
    filename(fileName)
{

}

void MoveLabel::mousePressEvent(QMouseEvent *ev)
{
    qDebug() << "click";
    emit click();
}
