#include "findform.h"
#include "ui_findform.h"
#include <QDir>
#include <algorithm>

FindForm::FindForm(QMap<int, QVector<QString>> filmTable, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FindForm)
    , filmTable(filmTable)
{
    ui->setupUi(this);
    setWindowTitle("Поиск фильма");
    setWindowModality(Qt::ApplicationModal);
    ui->tw_filmList->setColumnWidth(0,150);
    setFixedWidth(650);
    setFixedHeight(800);
    updateFilmList();

    QVector<QString> vGenre = filmTable[2];
    split(vGenre);
    vGenre.sort();
    unique(vGenre);
    ui->lw_genre->addItems(vGenre);
    QVector<QString> vYear = filmTable[6];
    vYear.sort();
    unique(vYear);
    ui->lw_year->addItems(vYear);
    QVector<QString> vActor = filmTable[5];
    split(vActor);
    vActor.sort();
    unique(vActor);
    ui->lw_actor->addItems(vActor);
}

void FindForm::unique(QVector<QString> &vector)
{
    QString lastElementV{};
    for(int gIndex = 0; gIndex < vector.count(); gIndex++ )
    {
        if(lastElementV != vector[gIndex]){
            lastElementV = vector[gIndex];
        }
        else
        {
            vector.remove(gIndex);
            gIndex--;
        }
    }
}

void FindForm::split(QVector<QString> &vector)
{
    QVector<QString> tmp{};
    for(int vIndex = 0; vIndex < vector.count(); vIndex++)
    {
        QString tmpStr = vector[vIndex];
        QChar ch_ = '"';
        tmpStr.removeIf([=](auto ch){return ch == ch_;});
        tmp << tmpStr.split(',');
    }
    vector = tmp;
}

FindForm::~FindForm()
{
    delete ui;
}

void FindForm::on_le_find_textChanged(const QString &arg1)
{
    updateFilmList(arg1);
}

void FindForm::updateFilmList(const QString &subStr)
{
    ui->tw_filmList->setRowCount(0);
    for(int filmIndex = 0; filmIndex < filmTable[0].count(); filmIndex++)
    {
        int newRowNum = ui->tw_filmList->rowCount();

        QString filmName = filmTable[1][filmIndex].toLower();

        if(filterYear.length())
            if(filmTable[6][filmIndex] != filterYear)
                continue;

        if(!filmName.contains(subStr.toLower()))
            continue;

        if(filterGenre.length())
        {
            QString tmpStr = filmTable[2][filmIndex];
            QChar ch_ = '"';
            tmpStr.removeIf([=](auto ch){return ch == ch_;});
            QStringList genre = tmpStr.split(',');
            if(!genre.contains(filterGenre))
                continue;
        }

        if(filterActor.length())
        {
            QString tmpStr = filmTable[5][filmIndex];
            QChar ch_ = '"';
            tmpStr.removeIf([=](auto ch){return ch == ch_;});
            QStringList actor = tmpStr.split(',');
            if(!actor.contains(filterActor))
                continue;
        }

        QDir dir("./img/"+filmTable[1][filmIndex]);
        QStringList fileList = dir.entryList();
        if(!fileList.count())
            continue;

        ui->tw_filmList->insertRow(newRowNum);
        ui->tw_filmList->setItem(newRowNum, 0, new QTableWidgetItem(filmTable[1][filmIndex]));

        MoveLabel *mv = new MoveLabel(ui->tw_filmList);

        QPixmap pix("./img/"+filmTable[1][filmIndex]+"/"+fileList[2]);
        if(pix.width() && pix.height()) {
            mv->drawPixmap(pix);
            ui->tw_filmList->setRowHeight(newRowNum, 150);
            ui->tw_filmList->setColumnWidth(1, 112);
        }
        ui->tw_filmList->setCellWidget(newRowNum, 1, mv);
        ui->tw_filmList->setItem(newRowNum, 2, new QTableWidgetItem(filmTable[6][filmIndex]));
    }
}



void FindForm::on_lw_genre_itemClicked(QListWidgetItem *item)
{
    filterGenre = item->text();
    updateFilmList();
}


void FindForm::on_lw_year_itemClicked(QListWidgetItem *item)
{
    filterYear = item->text();
    updateFilmList();
}


void FindForm::on_lw_actor_itemClicked(QListWidgetItem *item)
{
    filterActor = item->text();
    updateFilmList();
}

