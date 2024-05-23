/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *l_film1;
    QLabel *l_film3;
    QLabel *l_film2;
    QLabel *l_film4;
    QLineEdit *le_find;
    QLabel *l_mainFilm;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(664, 412);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        l_film1 = new QLabel(centralwidget);
        l_film1->setObjectName("l_film1");

        gridLayout->addWidget(l_film1, 2, 0, 1, 1);

        l_film3 = new QLabel(centralwidget);
        l_film3->setObjectName("l_film3");

        gridLayout->addWidget(l_film3, 2, 2, 1, 1);

        l_film2 = new QLabel(centralwidget);
        l_film2->setObjectName("l_film2");

        gridLayout->addWidget(l_film2, 2, 1, 1, 1);

        l_film4 = new QLabel(centralwidget);
        l_film4->setObjectName("l_film4");

        gridLayout->addWidget(l_film4, 2, 3, 1, 1);

        le_find = new QLineEdit(centralwidget);
        le_find->setObjectName("le_find");

        gridLayout->addWidget(le_find, 0, 1, 1, 2);

        l_mainFilm = new QLabel(centralwidget);
        l_mainFilm->setObjectName("l_mainFilm");

        gridLayout->addWidget(l_mainFilm, 1, 0, 1, 4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        toolButton = new QToolButton(centralwidget);
        toolButton->setObjectName("toolButton");

        horizontalLayout->addWidget(toolButton);


        gridLayout->addLayout(horizontalLayout, 0, 3, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 664, 16));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        l_film1->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        l_film3->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        l_film2->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        l_film4->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        l_mainFilm->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        toolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
