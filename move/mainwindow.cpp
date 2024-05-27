#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <random>
#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString fileName = QFileDialog::getOpenFileName(this,
                                            tr("Выберите CSV файл"), "", tr("CSV (*.csv)"));
    QFile file(fileName);
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




MainWindow::~MainWindow()
{
    delete ui;
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


void MainWindow::on_toolButton_clicked()
{
    ui->l_mainFilm->setText("ГЛАВНЫЙ ФИЛЬМ");
}

