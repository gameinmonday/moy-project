#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <random>
#include <QRandomGenerator>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    mainFilm = new MoveLabel(this);
    ui->horizontalLayout->addWidget(mainFilm,0);

    QDir dir("./img/");
    imgPathList = dir.entryList();
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Выберите CSV файл"), "", tr("CSV (*.csv)"));

    readCsv(fileName);

    std::uniform_real_distribution<> dist(0,filmTable[1].count()-1);
    mainFilm->setText(filmTable[1][dist(*QRandomGenerator::global())]);
    mainFilm->setToolTip(mainFilm->text());



    dir.setPath("./img/"+mainFilm->text());
    fileList = dir.entryList();

    ff = new FindForm(filmTable);
    connect(mainFilm, &MoveLabel::click, this, [&](){
        if(fileList.count() <= currPicNum)
            currPicNum = 2;
        QPixmap pix("./img/"+mainFilm->toolTip()+"/"+fileList[currPicNum]);
        QSize pixSize = pix.size();
        QSize newSize{};
        if(pixSize.width() > pixSize.height())
        {
            newSize.setWidth(width());
            newSize.setHeight(((double)width()/pixSize.width())*pixSize.height());
        }
        else
        {
            newSize.setWidth((300.0/pixSize.height())*pixSize.width());
            newSize.setHeight(300);
        }

        mainFilm->setFixedSize(newSize);
        mainFilm->setAlignment(Qt::AlignCenter);
        mainFilm->setPixmap(pix.scaled(newSize,Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
        currPicNum++;
    });
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::processMoveMarix()
{
    int gridWidth = width();
    int gridHeight = 4*150;

    int rowCount = floor(gridHeight/150);
    int columnCount = floor(gridWidth/112);

    if(rowCount != ui->gr_randomFilm->rowCount() || columnCount != ui->gr_randomFilm->columnCount())
    {
        int widgetCount = ui->gr_randomFilm->count();
        for(int itemIndex = 0; itemIndex < widgetCount; itemIndex++)
        {
            QLayoutItem *li = ui->gr_randomFilm->itemAt(itemIndex);
            if(li)
                delete li->widget();
        }

        for(int iRow=0; iRow < rowCount; iRow++)
        {
            for(int iCol=0; iCol < columnCount; iCol++)
            {
                MoveLabel *mv = new MoveLabel(this);
                ui->gr_randomFilm->addWidget(mv, iRow, iCol);

                std::uniform_real_distribution<> dist(0,filmTable[1].count()-1);
                mv->setText(filmTable[1][dist(*QRandomGenerator::global())]);
                mv->setToolTip(mv->text());

                QDir dir("./img/"+mv->text());
                QStringList fileList = dir.entryList();

                QPixmap pix("./img/"+mv->text()+"/"+fileList[2]);
                if(pix.width() && pix.height())
                    mv->drawPixmap(pix.scaled(112,150));
                else
                    qDebug() << "Пустой рисунок" << "./img/"+mv->text()+"/"+fileList[2];

                connect(mv, &MoveLabel::click, this, [&](){
                    MoveLabel *mv = static_cast<MoveLabel*>(sender());
                    QString moveName = mv->toolTip();
                    int moveIndex = filmTable[1].indexOf(moveName);
                    QVector<QString> moveParams{};
                    moveParams << filmTable[0][moveIndex] << filmTable[1][moveIndex] << filmTable[2][moveIndex] << filmTable[3][moveIndex] <<
                        filmTable[4][moveIndex] << filmTable[5][moveIndex] << filmTable[6][moveIndex] << filmTable[7][moveIndex] << filmTable[8][moveIndex]
                               << filmTable[9][moveIndex] << filmTable[10][moveIndex] << filmTable[11][moveIndex]<<filmTable[12][moveIndex];
                    MoveCard *mc = new MoveCard(topicVector,moveParams);
                    mc->show();
                });
            }
        }
    }
}

QStringList MainWindow::split(QString str)
{
    QStringList result;

    int cIndex{};

    while(cIndex >= 0)
    {

        cIndex = str.indexOf(',');
        int qIndex = str.indexOf('"');
        if(qIndex < cIndex && qIndex != -1)
        {
            int qIndex2 = str.indexOf('"', cIndex+1);
            cIndex = str.indexOf(',', qIndex2);
            result.push_back(str.left(cIndex));
            str.remove(0, cIndex+1);
        }
        else
        {
            cIndex = str.indexOf(',');
            result.push_back(str.left(cIndex));
            str.remove(0, cIndex+1);
        }

    }

    return result;
}

void MainWindow::readCsv(QString fileAddress)
{
    QFile file(fileAddress);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox msgBox;
        msgBox.setText("Файл не открылся");
        msgBox.exec();
        exit(1);
    }

    int rowIndex {};
    while(!file.atEnd())
    {
        QByteArray line = file.readLine();
        QString strLine = QString::fromUtf8(line);
        QStringList lStr = split(strLine);

        if(!imgPathList.contains(lStr.at(1)) && rowIndex)
        {
            continue;
        }

        int colIndex{};

        for(auto item: lStr)
        {
            if(!rowIndex)
            {
                QVector<QString> v{};
                topicVector << item;
                filmTable.insert(colIndex++,v);
            }
            else
            {
                filmTable[colIndex++].push_back(item);
            }
        }
        rowIndex++;
    }
}

void MainWindow::resizeEvent(QResizeEvent *)
{
    processMoveMarix();
    int imageNum = 3;
    while(fileList.count() > imageNum)
    {
        QPixmap pix("./img/"+mainFilm->toolTip()+"/"+fileList[imageNum]);
        QSize pixSize = pix.size();


        if(pix.width())
        {
            if(!mainFilm->pixmap().width())
            {
                QSize newSize (width(), ((double)width()/pixSize.width())*pixSize.height());
                mainFilm->setFixedSize(newSize);
                mainFilm->setAlignment(Qt::AlignCenter);
                mainFilm->setPixmap(pix.scaled(newSize,Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
            }
            else
            {
                QSize newSize (width(), mainFilm->pixmap().height());
                mainFilm->setFixedSize(newSize);
                //mainFilm->setAlignment(Qt::AlignCenter);
            }
            break;
        }
        imageNum++;
    }
}




void MainWindow::on_toolButton_clicked()
{
    //mainFilm->setText("ГЛАВНЫЙ ФИЛЬМ");
}


void MainWindow::on_ac_find_triggered()
{
    ff->show();
}

