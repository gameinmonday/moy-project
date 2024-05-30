/********************************************************************************
** Form generated from reading UI file 'findform.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDFORM_H
#define UI_FINDFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FindForm
{
public:
    QGridLayout *gridLayout;
    QLineEdit *le_find;
    QTableWidget *tw_filmList;

    void setupUi(QWidget *FindForm)
    {
        if (FindForm->objectName().isEmpty())
            FindForm->setObjectName("FindForm");
        FindForm->resize(400, 300);
        gridLayout = new QGridLayout(FindForm);
        gridLayout->setObjectName("gridLayout");
        le_find = new QLineEdit(FindForm);
        le_find->setObjectName("le_find");

        gridLayout->addWidget(le_find, 0, 0, 1, 1);

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

        gridLayout->addWidget(tw_filmList, 1, 0, 1, 1);


        retranslateUi(FindForm);

        QMetaObject::connectSlotsByName(FindForm);
    } // setupUi

    void retranslateUi(QWidget *FindForm)
    {
        FindForm->setWindowTitle(QCoreApplication::translate("FindForm", "Form", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tw_filmList->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("FindForm", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\204\320\270\320\273\321\214\320\274\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tw_filmList->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("FindForm", "\320\220\321\204\320\270\321\210\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tw_filmList->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("FindForm", "\320\223\320\276\320\264 \320\262\321\213\320\277\321\203\321\201\320\272\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FindForm: public Ui_FindForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDFORM_H
