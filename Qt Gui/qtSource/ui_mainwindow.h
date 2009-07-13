/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Wed Jul 1 18:03:52 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QAction *actionNetwork;
    QAction *actionDatabase;
    QAction *actionOnline_Help;
    QAction *actionAbout;
    QAction *actionDeveloper_Key;
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QTextEdit *textEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QMenuBar *menuBar;
    QMenu *menuSetUp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QString::fromUtf8("MainWindowClass"));
        MainWindowClass->resize(474, 392);
        MainWindowClass->setMinimumSize(QSize(474, 392));
        MainWindowClass->setMaximumSize(QSize(474, 392));
        actionNetwork = new QAction(MainWindowClass);
        actionNetwork->setObjectName(QString::fromUtf8("actionNetwork"));
        QIcon icon;
        icon.addPixmap(QPixmap(QString::fromUtf8(":/icons/bullet_wrench.png")), QIcon::Normal, QIcon::Off);
        actionNetwork->setIcon(icon);
        actionDatabase = new QAction(MainWindowClass);
        actionDatabase->setObjectName(QString::fromUtf8("actionDatabase"));
        QIcon icon1;
        icon1.addPixmap(QPixmap(QString::fromUtf8(":/icons/database_connect.png")), QIcon::Normal, QIcon::Off);
        actionDatabase->setIcon(icon1);
        actionOnline_Help = new QAction(MainWindowClass);
        actionOnline_Help->setObjectName(QString::fromUtf8("actionOnline_Help"));
        actionAbout = new QAction(MainWindowClass);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionDeveloper_Key = new QAction(MainWindowClass);
        actionDeveloper_Key->setObjectName(QString::fromUtf8("actionDeveloper_Key"));
        QIcon icon2;
        icon2.addPixmap(QPixmap(QString::fromUtf8(":/icons/key_add.png")), QIcon::Normal, QIcon::Off);
        actionDeveloper_Key->setIcon(icon2);
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 0, 451, 301));
        groupBox->setMaximumSize(QSize(451, 301));
        textEdit = new QTextEdit(groupBox);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 30, 431, 261));
        textEdit->setStyleSheet(QString::fromUtf8("QTextEdit { \n"
"border-width: 5px; \n"
"border-style: inset; \n"
"border-color: #535353; \n"
"border-radius: 9px; \n"
"background: #ffffff; \n"
"color: #000000; \n"
"}"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(260, 310, 91, 32));
        QIcon icon3;
        icon3.addPixmap(QPixmap(QString::fromUtf8(":/icons/control_play_blue.png")), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon3);
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(360, 310, 91, 32));
        QIcon icon4;
        icon4.addPixmap(QPixmap(QString::fromUtf8(":/icons/control_pause_blue.png")), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon4);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 320, 211, 17));
        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 474, 22));
        menuSetUp = new QMenu(menuBar);
        menuSetUp->setObjectName(QString::fromUtf8("menuSetUp"));
        MainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindowClass->setStatusBar(statusBar);

        menuBar->addAction(menuSetUp->menuAction());
        menuSetUp->addAction(actionNetwork);
        menuSetUp->addAction(actionDatabase);
        menuSetUp->addSeparator();
        menuSetUp->addAction(actionDeveloper_Key);

        retranslateUi(MainWindowClass);

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "2Sprout", 0, QApplication::UnicodeUTF8));
        actionNetwork->setText(QApplication::translate("MainWindowClass", "Network", 0, QApplication::UnicodeUTF8));
        actionNetwork->setShortcut(QApplication::translate("MainWindowClass", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        actionDatabase->setText(QApplication::translate("MainWindowClass", "Database", 0, QApplication::UnicodeUTF8));
        actionDatabase->setShortcut(QApplication::translate("MainWindowClass", "Ctrl+D", 0, QApplication::UnicodeUTF8));
        actionOnline_Help->setText(QApplication::translate("MainWindowClass", "Online Help", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindowClass", "About", 0, QApplication::UnicodeUTF8));
        actionDeveloper_Key->setText(QApplication::translate("MainWindowClass", "Developer Key", 0, QApplication::UnicodeUTF8));
        actionDeveloper_Key->setShortcut(QApplication::translate("MainWindowClass", "Ctrl+K", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindowClass", "2sprout Status", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindowClass", "Start", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWindowClass", "Pause", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        menuSetUp->setTitle(QApplication::translate("MainWindowClass", "Setup", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
