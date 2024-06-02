#include "movelabel.h"

MoveLabel::MoveLabel(QWidget *parent)
    : QLabel(parent)
{

}

void MoveLabel::drawPixmap(QPixmap p_pix)
{
    pix = p_pix;

    setPixmap(pix);
}

void MoveLabel::setMoveName(QString p_moveName)
{
    moveName = p_moveName;
}

void MoveLabel::mousePressEvent(QMouseEvent *ev)
{
    emit click();
}

// void MoveLabel::resizeEvent(QResizeEvent *)
// {
//     setPixmap(pix.scaled(width(), height()));
// }
