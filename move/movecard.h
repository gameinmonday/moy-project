#ifndef MOVECARD_H
#define MOVECARD_H

#include <QWidget>
#include <QLabel>
#include <QDir>
#include <QTableWidget>
#include <QHeaderView>
#include "movelabel.h"

namespace Ui {
class MoveCard;
}

class ResizeTableWidget: public QTableWidget
{
    Q_OBJECT
public:
    ResizeTableWidget(QWidget *parent = nullptr):QTableWidget(parent)
    {
        horizontalHeader()->setVisible(false);
        verticalHeader()->setVisible(false);
        setColumnCount(2);
        setRowCount(12);
        setStyleSheet("QTableWidget {border: 2px outset red;}");
        setSelectionMode(QAbstractItemView::NoSelection);
    }
protected:
    void resizeEvent(QResizeEvent *event) override
    {
        for(int colIndex = 0; colIndex < columnCount(); colIndex++)
        {
            if(!colIndex)
                setColumnWidth(colIndex, 120);
            else
                setColumnWidth(colIndex, width()-130);
        }
        for(int rowIndex = 0; rowIndex < rowCount(); rowIndex++)
        {
            setRowHeight(rowIndex, height()/rowCount()-1);
        }
    }
};

class MoveCard : public QWidget
{
    Q_OBJECT

public:
    explicit MoveCard(QVector<QString> topicVector, QVector<QString> attrVector, QWidget *parent = nullptr);
    ~MoveCard();

private:
    Ui::MoveCard *ui;
    QLabel *moveName;
    QLabel *moveDescription;
    MoveLabel *mv{};
    ResizeTableWidget *tw{};
    QVector<QString> attrVector{};
    int currPicNum = 2;

    QPixmap createPixmap();

private slots:
    void nextPic();
};

#endif // MOVECARD_H
