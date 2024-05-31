#include "movecard.h"
#include "ui_movecard.h"

MoveCard::MoveCard(QVector<QString> attrVector, QWidget *parent)
    : QWidget(parent),attrVector(attrVector)
    , ui(new Ui::MoveCard)
{
    ui->setupUi(this);

    mv = new MoveLabel(this);
    mv->drawPixmap(createPixmap());
    ui->gridLayout->addWidget(mv, 0,0);
}

MoveCard::~MoveCard()
{
    delete ui;
}

QPixmap MoveCard::createPixmap()
{
    QDir dir("./img/"+attrVector[1]);
    QStringList fileList = dir.entryList();

    QPixmap pix("./img/"+attrVector[1]+"/"+fileList[2]);
    return pix;
}
