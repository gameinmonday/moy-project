/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *ac_find;
    QAction *ac_exit;
    QAction *ac_rating;
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QGridLayout *gr_randomFilm;
    QHBoxLayout *horizontalLayout;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(550, 1000);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(550, 1000));
        ac_find = new QAction(MainWindow);
        ac_find->setObjectName("ac_find");
        ac_exit = new QAction(MainWindow);
        ac_exit->setObjectName("ac_exit");
        ac_exit->setCheckable(true);
        ac_exit->setChecked(false);
        ac_exit->setEnabled(false);
        ac_exit->setIconVisibleInMenu(true);
        ac_exit->setShortcutVisibleInContextMenu(true);
        ac_rating = new QAction(MainWindow);
        ac_rating->setObjectName("ac_rating");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        gr_randomFilm = new QGridLayout();
        gr_randomFilm->setObjectName("gr_randomFilm");

        gridLayout->addLayout(gr_randomFilm, 1, 0, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");

        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 2);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 550, 24));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(ac_find);
        menu->addAction(ac_rating);
        menu->addAction(ac_exit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        ac_find->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        ac_exit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
#if QT_CONFIG(statustip)
        ac_exit->setStatusTip(QCoreApplication::translate("MainWindow", "Exit", nullptr));
#endif // QT_CONFIG(statustip)
        ac_rating->setText(QCoreApplication::translate("MainWindow", "Watched Films", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
