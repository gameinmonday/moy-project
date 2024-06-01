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
    connect(mv, &MoveLabel::click, this, &MoveCard::nextPic);
    QPixmap pix = createPixmap();
    QSize pixSize = pix.size();
    mv->drawPixmap(pix.scaled(336,(double)pixSize.height()/pixSize.width() * 336,Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    pix = mv->pixmap();
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
                if(attrIndex != 12)
                {
                    tw->setItem(rowIndex, colIndex, new QTableWidgetItem(attrVector[attrIndex++]));
                    tw->item(rowIndex, colIndex)->setFlags(Qt::NoItemFlags);
                }
                else if(attrIndex == 12)
                {
                    QLabel *lb = new QLabel("<a href=\""+attrVector[attrIndex]+"\"></a>",this);
                    lb->setTextFormat(Qt::RichText);
                    lb->setTextInteractionFlags(Qt::TextBrowserInteraction);
                    lb->setOpenExternalLinks(true);
                    tw->setItem(rowIndex, colIndex, new QTableWidgetItem(attrVector[attrIndex++]));
                }
            }
        }
    }
    ui->gridLayout->addWidget(tw,0,1);

    QLabel *lb = new QLabel("<a href=\"https://www.kinopoisk.cx/film/689066/\"></a>");
    // lb->setTextFormat(Qt::RichText);
    // lb->setTextInteractionFlags(Qt::TextBrowserInteraction);
    // lb->setOpenExternalLinks(true);
    ui->gridLayout->addWidget(lb,1,1);

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
    QPixmap pix = createPixmap();
    QSize pixSize = pix.size();
    QSize newPixSize(336,((double)pixSize.height()/pixSize.width()) * 336);
    mv->drawPixmap(pix.scaled(newPixSize.width(),newPixSize.height(),Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    //mv->drawPixmap(createPixmap().scaled(112*3,150*3));
}
