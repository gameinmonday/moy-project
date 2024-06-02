#ifndef FINDFORM_H
#define FINDFORM_H

#include <QWidget>
#include <QListWidgetItem>
#include "movelabel.h"
#include "movecard.h"

namespace Ui {
class FindForm;
}

class FindForm : public QWidget
{
    Q_OBJECT

public:
    explicit FindForm(QMap<int, QVector<QString> > filmTable, QVector<QString> topicVector, QWidget *parent = nullptr);
    ~FindForm();

private slots:
    void on_le_find_textChanged(const QString &arg1);

    void on_lw_genre_itemClicked(QListWidgetItem *item);

    void on_lw_year_itemClicked(QListWidgetItem *item);

    void on_lw_actor_itemClicked(QListWidgetItem *item);

private:
    Ui::FindForm *ui;
    void updateFilmList(const QString &subStr = "");
    QMap<int, QVector<QString>> filmTable{};

    void unique(QVector<QString> &vector);
    void split(QVector<QString> &vector);


    QVector<QString> topicVector{};

    QString filterGenre{};
    QString filterYear{};
    QString filterActor{};
};

#endif // FINDFORM_H
