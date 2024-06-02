#include "movecard.h"
#include "ui_movecard.h"

MoveCard::MoveCard(QVector<QString> topicVector,QVector<QString> attrVector, QWidget *parent)
    : QWidget(parent),attrVector(attrVector)
    , ui(new Ui::MoveCard)
{
    ui->setupUi(this);

    settings = new QSettings("statictic", QSettings::IniFormat, this);
    setWindowModality(Qt::ApplicationModal);

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
                    QLabel *lb = new QLabel("<a href=\""+attrVector[attrIndex]+"\">Watch film</a>",this);
                    lb->setOpenExternalLinks(true);
                    tw->setCellWidget(rowIndex, colIndex, lb);
                }
            }
        }
    }
    int rowNum = tw->rowCount();
    tw->insertRow(rowNum);
    tw->setItem(rowNum,0, new QTableWidgetItem("Rating"));
    tw->item(rowNum, 0)->setForeground(QBrush(QColor(Qt::red)));

    QSpinBox *sb = new QSpinBox(tw);
    sb->setValue(settings->value(tw->item(1,1)->text()).toInt());
    connect(sb, &QSpinBox::textChanged, this, [&](QString txt){
        settings->setValue(tw->item(1,1)->text(), txt);
    });
    sb->setMaximum(10);
    sb->setMinimum(0);
    tw->setCellWidget(rowNum,1, sb);
    ui->gridLayout->addWidget(tw,0,1);
}

MoveCard::~MoveCard()
{
    delete ui;
}

QPixmap MoveCard::createPixmap()
{
    QDir dir("/Users/dmitrijlevankov/Desktop/move /img/"+attrVector[1]);
    QStringList fileList = dir.entryList();

    QPixmap pix("/Users/dmitrijlevankov/Desktop/move /img/"+attrVector[1]+"/"+fileList[currPicNum]);

    return pix;
}

void MoveCard::nextPic()
{
    currPicNum++;
    QDir dir("/Users/dmitrijlevankov/Desktop/move /img/"+attrVector[1]);
    QStringList fileList = dir.entryList();
    if(fileList.count() <= currPicNum)
        currPicNum = 2;
    QPixmap pix = createPixmap();
    QSize pixSize = pix.size();
    QSize newPixSize(336,((double)pixSize.height()/pixSize.width()) * 336);
    mv->drawPixmap(pix.scaled(newPixSize.width(),newPixSize.height(),Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    //mv->drawPixmap(createPixmap().scaled(112*3,150*3));
}
