/********************************************************************************
** Form generated from reading UI file 'raitingdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RAITINGDIALOG_H
#define UI_RAITINGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_RaitingDialog
{
public:
    QGridLayout *gridLayout;
    QTableWidget *tableWidget;

    void setupUi(QDialog *RaitingDialog)
    {
        if (RaitingDialog->objectName().isEmpty())
            RaitingDialog->setObjectName("RaitingDialog");
        RaitingDialog->resize(400, 300);
        gridLayout = new QGridLayout(RaitingDialog);
        gridLayout->setObjectName("gridLayout");
        tableWidget = new QTableWidget(RaitingDialog);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName("tableWidget");
        tableWidget->verticalHeader()->setVisible(false);

        gridLayout->addWidget(tableWidget, 0, 0, 1, 1);


        retranslateUi(RaitingDialog);

        QMetaObject::connectSlotsByName(RaitingDialog);
    } // setupUi

    void retranslateUi(QDialog *RaitingDialog)
    {
        RaitingDialog->setWindowTitle(QCoreApplication::translate("RaitingDialog", "Dialog", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem->setText(QCoreApplication::translate("RaitingDialog", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("RaitingDialog", "\320\240\320\265\320\271\321\202\320\270\320\275\320\263", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RaitingDialog: public Ui_RaitingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RAITINGDIALOG_H
