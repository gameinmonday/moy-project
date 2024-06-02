/********************************************************************************
** Form generated from reading UI file 'findform.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDFORM_H
#define UI_FINDFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FindForm
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QTableWidget *tw_filmList;
    QListWidget *lw_actor;
    QLineEdit *le_find;
    QListWidget *lw_year;
    QLabel *label;
    QLabel *label_2;
    QListWidget *lw_genre;

    void setupUi(QWidget *FindForm)
    {
        if (FindForm->objectName().isEmpty())
            FindForm->setObjectName("FindForm");
        FindForm->resize(400, 371);
        gridLayout_2 = new QGridLayout(FindForm);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        label_3 = new QLabel(FindForm);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 5, 0, 1, 1);

        tw_filmList = new QTableWidget(FindForm);
        if (tw_filmList->columnCount() < 3)
            tw_filmList->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tw_filmList->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tw_filmList->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tw_filmList->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tw_filmList->setObjectName("tw_filmList");
        tw_filmList->setSelectionMode(QAbstractItemView::SingleSelection);
        tw_filmList->setSelectionBehavior(QAbstractItemView::SelectRows);
        tw_filmList->verticalHeader()->setVisible(true);

        gridLayout->addWidget(tw_filmList, 1, 1, 6, 1);

        lw_actor = new QListWidget(FindForm);
        new QListWidgetItem(lw_actor);
        lw_actor->setObjectName("lw_actor");
        lw_actor->setMaximumSize(QSize(200, 16777215));

        gridLayout->addWidget(lw_actor, 6, 0, 1, 1);

        le_find = new QLineEdit(FindForm);
        le_find->setObjectName("le_find");

        gridLayout->addWidget(le_find, 0, 1, 1, 1);

        lw_year = new QListWidget(FindForm);
        new QListWidgetItem(lw_year);
        lw_year->setObjectName("lw_year");
        lw_year->setMaximumSize(QSize(200, 16777215));

        gridLayout->addWidget(lw_year, 4, 0, 1, 1);

        label = new QLabel(FindForm);
        label->setObjectName("label");

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_2 = new QLabel(FindForm);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        lw_genre = new QListWidget(FindForm);
        new QListWidgetItem(lw_genre);
        lw_genre->setObjectName("lw_genre");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lw_genre->sizePolicy().hasHeightForWidth());
        lw_genre->setSizePolicy(sizePolicy);
        lw_genre->setMaximumSize(QSize(200, 16777215));

        gridLayout->addWidget(lw_genre, 2, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(FindForm);

        QMetaObject::connectSlotsByName(FindForm);
    } // setupUi

    void retranslateUi(QWidget *FindForm)
    {
        FindForm->setWindowTitle(QCoreApplication::translate("FindForm", "Form", nullptr));
        label_3->setText(QCoreApplication::translate("FindForm", "Actor:", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tw_filmList->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("FindForm", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tw_filmList->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("FindForm", "Poster", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tw_filmList->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("FindForm", "Year", nullptr));

        const bool __sortingEnabled = lw_actor->isSortingEnabled();
        lw_actor->setSortingEnabled(false);
        lw_actor->setSortingEnabled(__sortingEnabled);


        const bool __sortingEnabled1 = lw_year->isSortingEnabled();
        lw_year->setSortingEnabled(false);
        lw_year->setSortingEnabled(__sortingEnabled1);

        label->setText(QCoreApplication::translate("FindForm", "Genre:", nullptr));
        label_2->setText(QCoreApplication::translate("FindForm", "Year:", nullptr));

        const bool __sortingEnabled2 = lw_genre->isSortingEnabled();
        lw_genre->setSortingEnabled(false);
        lw_genre->setSortingEnabled(__sortingEnabled2);

    } // retranslateUi

};

namespace Ui {
    class FindForm: public Ui_FindForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDFORM_H
