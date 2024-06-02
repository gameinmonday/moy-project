#include "raitingdialog.h"
#include "ui_raitingdialog.h"

RaitingDialog::RaitingDialog(QMap<int, QVector<QString>> filmTable, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RaitingDialog)
{
    ui->setupUi(this);
    setWindowTitle("Watched films");
    settings = new QSettings("statictic", QSettings::IniFormat, this);


    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection);

    for(int mIndex = 0; mIndex < filmTable[1].count(); mIndex++)
    {
        if(settings->contains(filmTable[1][mIndex]))
        {
            int newRow = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(newRow);

            mv = new MoveLabel(this);
            QDir dir("/Users/dmitrijlevankov/Desktop/move /img/"+filmTable[1][mIndex]);
            QStringList fileList = dir.entryList();
            QPixmap pix("/Users/dmitrijlevankov/Desktop/move /img/"+filmTable[1][mIndex]+"/"+fileList[2]);
            QSize pixSize = pix.size();
            mv->drawPixmap(pix.scaled(112,150,Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
            ui->tableWidget->setCellWidget(newRow, 0, mv);

            QTableWidgetItem *titleItem = new QTableWidgetItem(filmTable[1][mIndex]);
            titleItem->setFlags(titleItem->flags() & ~Qt::ItemIsSelectable & ~Qt::ItemIsEditable);
            ui->tableWidget->setItem(newRow, 1, titleItem);

            QTableWidgetItem *ratingItem = new QTableWidgetItem(settings->value(filmTable[1][mIndex]).toString());
            ratingItem->setFlags(ratingItem->flags() & ~Qt::ItemIsSelectable & ~Qt::ItemIsEditable);
            ui->tableWidget->setItem(newRow, 2, ratingItem);

            ui->tableWidget->setRowHeight(newRow, 150);
        }
    }
}

RaitingDialog::~RaitingDialog()
{
    delete ui;
}

void RaitingDialog::resizeEvent(QResizeEvent *event)
{
    double tbWidth = ui->tableWidget->width();
    ui->tableWidget->setColumnWidth(0, (tbWidth/10) * 3 - 5);
    ui->tableWidget->setColumnWidth(1, (tbWidth/10) * 5);
    ui->tableWidget->setColumnWidth(2, tbWidth / 5);
}
