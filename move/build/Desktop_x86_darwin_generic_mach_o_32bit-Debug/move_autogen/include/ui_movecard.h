/********************************************************************************
** Form generated from reading UI file 'movecard.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOVECARD_H
#define UI_MOVECARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MoveCard
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;

    void setupUi(QWidget *MoveCard)
    {
        if (MoveCard->objectName().isEmpty())
            MoveCard->setObjectName("MoveCard");
        MoveCard->resize(674, 457);
        gridLayout_2 = new QGridLayout(MoveCard);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");

        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(MoveCard);

        QMetaObject::connectSlotsByName(MoveCard);
    } // setupUi

    void retranslateUi(QWidget *MoveCard)
    {
        MoveCard->setWindowTitle(QCoreApplication::translate("MoveCard", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MoveCard: public Ui_MoveCard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOVECARD_H
