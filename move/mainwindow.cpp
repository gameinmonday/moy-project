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

    QDir dir("./img/");
    imgPathList = dir.entryList();
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Выберите CSV файл"), "", tr("CSV (*.csv)"));

    readCsv(fileName);

    std::uniform_real_distribution<> dist(0,filmTable[1].count()-1);
    ui->l_mainFilm->setText(filmTable[1][dist(*QRandomGenerator::global())]);

    dir.setPath("./img/"+ui->l_mainFilm->text());
    QStringList fileList = dir.entryList();

    QPixmap pix("./img/"+ui->l_mainFilm->text()+"/"+fileList[4]);
    ui->l_mainFilm->setPixmap(pix.scaled(500,200));



    //ui->toolButton->setIcon(QIcon(":/img/find.png"));
    connect(ui->toolButton, &QToolButton::clicked, this, [&](){

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
                MoveLabel *mv = new MoveLabel("",this);
                ui->gr_randomFilm->addWidget(mv, iRow, iCol);
                connect(mv, &MoveLabel::click, this, [&](){

                });
                std::uniform_real_distribution<> dist(0,filmTable[1].count()-1);
                mv->setText(filmTable[1][dist(*QRandomGenerator::global())]);
                mv->setToolTip(mv->text());

                QDir dir("./img/"+mv->text());
                QStringList fileList = dir.entryList();

                QPixmap pix("./img/"+mv->text()+"/"+fileList[2]);
                mv->drawPixmap(pix);
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

        if(!imgPathList.contains(lStr.at(1)))
        {
            continue;
        }

        int colIndex{};

        for(auto item: lStr)
        {
            if(!rowIndex)
            {
                QVector<QString> v{};
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
}




void MainWindow::on_toolButton_clicked()
{
    ui->l_mainFilm->setText("ГЛАВНЫЙ ФИЛЬМ");
}

