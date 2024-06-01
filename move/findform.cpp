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
    updateFilmList();
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

        if(!filmName.contains(subStr.toLower()))
            continue;

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

