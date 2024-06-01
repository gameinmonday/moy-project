#include "movecard.h"
#include "ui_movecard.h"

MoveCard::MoveCard(QVector<QString> topicVector,QVector<QString> attrVector, QWidget *parent)
    : QWidget(parent),attrVector(attrVector)
    , ui(new Ui::MoveCard)
{
    ui->setupUi(this);

    setFixedWidth(800);
    setFixedHeight(800);

    mv = new MoveLabel(this);
    mv->setFixedWidth(280);
    mv->setStyleSheet("QLabel { background-color: yellow }");
    connect(mv, &MoveLabel::click, this, &MoveCard::nextPic);
    mv->drawPixmap(createPixmap());
    QPixmap pix = mv->pixmap();
    ui->gridLayout->addWidget(mv, 0,0);
    tw = new ResizeTableWidget(this);
    tw->setFixedWidth(500);

    int attrIndex{};
    int topicIndex{};

    for(int colIndex = 0; colIndex < tw->columnCount(); colIndex++)
    {
        for(int rowIndex = 0; rowIndex < tw->rowCount(); rowIndex++)
        {
            if (!colIndex){
                tw->setItem(rowIndex, colIndex, new QTableWidgetItem(topicVector[topicIndex++]));
                tw->item(rowIndex, colIndex)->setForeground(QBrush(QColor(Qt::red)));
                tw->item(rowIndex, colIndex)->setFlags(Qt::NoItemFlags);
            }
            else
            {
                tw->setItem(rowIndex, colIndex, new QTableWidgetItem(attrVector[attrIndex++]));
                tw->item(rowIndex, colIndex)->setFlags(Qt::NoItemFlags);
            }
        }
    }
    ui->gridLayout->addWidget(tw,0,1);

}

MoveCard::~MoveCard()
{
    delete ui;
}

QPixmap MoveCard::createPixmap()
{
    QDir dir("./img/"+attrVector[1]);
    QStringList fileList = dir.entryList();

    QPixmap pix("./img/"+attrVector[1]+"/"+fileList[currPicNum]);

    return pix;
}

void MoveCard::nextPic()
{
    currPicNum++;
    QDir dir("./img/"+attrVector[1]);
    QStringList fileList = dir.entryList();
    if(fileList.count() <= currPicNum)
        currPicNum = 2;
    mv->drawPixmap(createPixmap());
}
