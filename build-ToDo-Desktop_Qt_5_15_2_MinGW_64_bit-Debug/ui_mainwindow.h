/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *startPage;
    QGridLayout *gridLayout;
    QPushButton *startPageButton;
    QCalendarWidget *calendarWidget;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_2;
    QWidget *toDOWidget;
    QVBoxLayout *verticalLayout_3;
    QWidget *toDo;
    QVBoxLayout *verticalLayout_5;
    QWidget *spacer;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer;
    QLineEdit *toDolineEdit;
    QPushButton *addNewToDoButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setStyleSheet(QString::fromUtf8("*{\n"
"background-color:white;\n"
"color:black;\n"
"font-size:20px;\n"
"}\n"
"QWidget{\n"
"background-color:#525252;\n"
"}\n"
"QPushButton{\n"
"	background-color:#64f273\n"
"}\n"
"QPushButton::hover{\n"
"	background-color:#64f200\n"
"}"));
        startPage = new QWidget();
        startPage->setObjectName(QString::fromUtf8("startPage"));
        gridLayout = new QGridLayout(startPage);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        startPageButton = new QPushButton(startPage);
        startPageButton->setObjectName(QString::fromUtf8("startPageButton"));

        gridLayout->addWidget(startPageButton, 1, 0, 1, 1);

        calendarWidget = new QCalendarWidget(startPage);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setStyleSheet(QString::fromUtf8("color:#43f343;\n"
"background-color:#333;"));
        calendarWidget->setGridVisible(true);
        calendarWidget->setSelectionMode(QCalendarWidget::SingleSelection);
        calendarWidget->setHorizontalHeaderFormat(QCalendarWidget::ShortDayNames);
        calendarWidget->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
        calendarWidget->setNavigationBarVisible(true);
        calendarWidget->setDateEditEnabled(true);

        gridLayout->addWidget(calendarWidget, 0, 0, 1, 1);

        stackedWidget->addWidget(startPage);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        verticalLayout_2 = new QVBoxLayout(page_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        toDOWidget = new QWidget(page_2);
        toDOWidget->setObjectName(QString::fromUtf8("toDOWidget"));
        verticalLayout_3 = new QVBoxLayout(toDOWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        toDo = new QWidget(toDOWidget);
        toDo->setObjectName(QString::fromUtf8("toDo"));
        verticalLayout_5 = new QVBoxLayout(toDo);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));

        verticalLayout_3->addWidget(toDo);

        spacer = new QWidget(toDOWidget);
        spacer->setObjectName(QString::fromUtf8("spacer"));
        verticalLayout_4 = new QVBoxLayout(spacer);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 455, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        verticalLayout_3->addWidget(spacer);


        verticalLayout_2->addWidget(toDOWidget);

        toDolineEdit = new QLineEdit(page_2);
        toDolineEdit->setObjectName(QString::fromUtf8("toDolineEdit"));

        verticalLayout_2->addWidget(toDolineEdit);

        addNewToDoButton = new QPushButton(page_2);
        addNewToDoButton->setObjectName(QString::fromUtf8("addNewToDoButton"));

        verticalLayout_2->addWidget(addNewToDoButton);

        stackedWidget->addWidget(page_2);

        verticalLayout->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        startPageButton->setText(QCoreApplication::translate("MainWindow", "Poka\305\274 wszystko", nullptr));
        addNewToDoButton->setText(QCoreApplication::translate("MainWindow", "Dodaj nowe", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
