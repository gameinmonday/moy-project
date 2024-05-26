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
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButton;
    QLabel *l_mainFilm;
    QLineEdit *le_find;
    QGridLayout *gr_randomFilm;
    QLabel *l_film3;
    QLabel *l_film4;
    QLabel *label_7;
    QLabel *label_6;
    QLabel *label_2;
    QLabel *l_film2;
    QLabel *label;
    QLabel *label_8;
    QLabel *l_film1;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_12;
    QLabel *label_11;
    QLabel *label_10;
    QLabel *label_9;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1065, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        toolButton = new QToolButton(centralwidget);
        toolButton->setObjectName("toolButton");

        horizontalLayout->addWidget(toolButton);


        gridLayout->addLayout(horizontalLayout, 0, 3, 1, 1);

        l_mainFilm = new QLabel(centralwidget);
        l_mainFilm->setObjectName("l_mainFilm");

        gridLayout->addWidget(l_mainFilm, 1, 0, 1, 4);

        le_find = new QLineEdit(centralwidget);
        le_find->setObjectName("le_find");

        gridLayout->addWidget(le_find, 0, 1, 1, 2);

        gr_randomFilm = new QGridLayout();
        gr_randomFilm->setObjectName("gr_randomFilm");
        l_film3 = new QLabel(centralwidget);
        l_film3->setObjectName("l_film3");

        gr_randomFilm->addWidget(l_film3, 0, 2, 1, 1);

        l_film4 = new QLabel(centralwidget);
        l_film4->setObjectName("l_film4");

        gr_randomFilm->addWidget(l_film4, 0, 3, 1, 1);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");

        gr_randomFilm->addWidget(label_7, 2, 1, 1, 1);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");

        gr_randomFilm->addWidget(label_6, 2, 2, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        gr_randomFilm->addWidget(label_2, 1, 3, 1, 1);

        l_film2 = new QLabel(centralwidget);
        l_film2->setObjectName("l_film2");

        gr_randomFilm->addWidget(l_film2, 0, 1, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName("label");

        gr_randomFilm->addWidget(label, 1, 2, 1, 1);

        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");

        gr_randomFilm->addWidget(label_8, 2, 0, 1, 1);

        l_film1 = new QLabel(centralwidget);
        l_film1->setObjectName("l_film1");

        gr_randomFilm->addWidget(l_film1, 0, 0, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");

        gr_randomFilm->addWidget(label_4, 1, 0, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");

        gr_randomFilm->addWidget(label_3, 1, 1, 1, 1);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");

        gr_randomFilm->addWidget(label_5, 2, 3, 1, 1);

        label_12 = new QLabel(centralwidget);
        label_12->setObjectName("label_12");

        gr_randomFilm->addWidget(label_12, 3, 0, 1, 1);

        label_11 = new QLabel(centralwidget);
        label_11->setObjectName("label_11");

        gr_randomFilm->addWidget(label_11, 3, 1, 1, 1);

        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");

        gr_randomFilm->addWidget(label_10, 3, 2, 1, 1);

        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");

        gr_randomFilm->addWidget(label_9, 3, 3, 1, 1);


        gridLayout->addLayout(gr_randomFilm, 2, 0, 1, 4);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1065, 16));
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
        toolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        l_mainFilm->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        l_film3->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        l_film4->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        l_film2->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        l_film1->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
