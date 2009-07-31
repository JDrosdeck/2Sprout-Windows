/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Thu Jul 30 19:30:57 2009
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
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextEdit>
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
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_2;
    QGroupBox *groupBox;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QMenu *menuSetUp;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QString::fromUtf8("MainWindowClass"));
        MainWindowClass->resize(501, 330);
        MainWindowClass->setMinimumSize(QSize(501, 330));
        MainWindowClass->setMaximumSize(QSize(501, 330));
        QIcon icon;
        icon.addPixmap(QPixmap(QString::fromUtf8(":/icons/2sprout.png")), QIcon::Normal, QIcon::Off);
        MainWindowClass->setWindowIcon(icon);
        actionNetwork = new QAction(MainWindowClass);
        actionNetwork->setObjectName(QString::fromUtf8("actionNetwork"));
        QIcon icon1;
        icon1.addPixmap(QPixmap(QString::fromUtf8(":/icons/bullet_wrench.png")), QIcon::Normal, QIcon::Off);
        actionNetwork->setIcon(icon1);
        actionDatabase = new QAction(MainWindowClass);
        actionDatabase->setObjectName(QString::fromUtf8("actionDatabase"));
        QIcon icon2;
        icon2.addPixmap(QPixmap(QString::fromUtf8(":/icons/database_connect.png")), QIcon::Normal, QIcon::Off);
        actionDatabase->setIcon(icon2);
        actionOnline_Help = new QAction(MainWindowClass);
        actionOnline_Help->setObjectName(QString::fromUtf8("actionOnline_Help"));
        actionAbout = new QAction(MainWindowClass);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionDeveloper_Key = new QAction(MainWindowClass);
        actionDeveloper_Key->setObjectName(QString::fromUtf8("actionDeveloper_Key"));
        QIcon icon3;
        icon3.addPixmap(QPixmap(QString::fromUtf8(":/icons/key_add.png")), QIcon::Normal, QIcon::Off);
        actionDeveloper_Key->setIcon(icon3);
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 270, 481, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setMargin(11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(horizontalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QIcon icon4;
        icon4.addPixmap(QPixmap(QString::fromUtf8(":/icons/control_play_blue.png")), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon4);

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton_2 = new QPushButton(horizontalLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        QIcon icon5;
        icon5.addPixmap(QPixmap(QString::fromUtf8(":/icons/control_pause_blue.png")), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon5);

        horizontalLayout->addWidget(pushButton_2);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 0, 481, 261));
        groupBox->setMaximumSize(QSize(481, 261));
        textEdit = new QTextEdit(groupBox);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 30, 461, 221));
        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 501, 19));
        menuSetUp = new QMenu(menuBar);
        menuSetUp->setObjectName(QString::fromUtf8("menuSetUp"));
        MainWindowClass->setMenuBar(menuBar);

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
        pushButton->setText(QApplication::translate("MainWindowClass", "Start", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWindowClass", "Pause", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindowClass", "Status", 0, QApplication::UnicodeUTF8));
        menuSetUp->setTitle(QApplication::translate("MainWindowClass", "Setup", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
