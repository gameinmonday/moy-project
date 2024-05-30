#include "movelabel.h"

MoveLabel::MoveLabel(QString fileName, QWidget *parent)
    : QLabel(parent),
    filename(fileName)
{

}

void MoveLabel::drawPixmap(QPixmap p_pix)
{
    pix = p_pix;
    setPixmap(pix.scaled(112,150));
}

void MoveLabel::mousePressEvent(QMouseEvent *ev)
{
    qDebug() << "click";
    emit click();
}

void MoveLabel::resizeEvent(QResizeEvent *)
{
    qDebug() << width() << height();
    setPixmap(pix.scaled(width(), height()));
}
