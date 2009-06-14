/********************************************************************************
** Form generated from reading ui file 'sprout.ui'
**
** Created: Tue Jun 9 15:20:05 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_SPROUT_H
#define UI_SPROUT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QStackedWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sproutClass
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGroupBox *groupBox;
    QTextEdit *textEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QWidget *page_2;
    QGroupBox *groupBox_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *comboBox;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QGroupBox *groupBox_3;
    QCheckBox *checkBox_2;
    QLineEdit *lineEdit_6;
    QCheckBox *checkBox_3;
    QGroupBox *groupBox_4;
    QTextEdit *textEdit_2;

    void setupUi(QMainWindow *sproutClass)
    {
        if (sproutClass->objectName().isEmpty())
            sproutClass->setObjectName(QString::fromUtf8("sproutClass"));
        sproutClass->setEnabled(true);
        sproutClass->resize(464, 473);
        sproutClass->setMinimumSize(QSize(464, 473));
        sproutClass->setMaximumSize(QSize(464, 473));
        QIcon icon;
        icon.addPixmap(QPixmap(QString::fromUtf8(":/icons/2sprout.png")), QIcon::Normal, QIcon::Off);
        sproutClass->setWindowIcon(icon);
        centralWidget = new QWidget(sproutClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setMinimumSize(QSize(464, 473));
        centralWidget->setMaximumSize(QSize(464, 473));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, -1, 471, 471));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        groupBox = new QGroupBox(page);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(9, 9, 451, 421));
        textEdit = new QTextEdit(groupBox);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(13, 29, 431, 381));
        textEdit->setStyleSheet(QString::fromUtf8("QTextEdit { \n"
"border-width: 5px; \n"
"border-style: inset; \n"
"border-color: #535353; \n"
"border-radius: 9px; \n"
"background: #ffffff; \n"
"color: #000000; \n"
"}"));
        pushButton = new QPushButton(page);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(230, 440, 113, 32));
        QIcon icon1;
        icon1.addPixmap(QPixmap(QString::fromUtf8("icons/started.png")), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);
        pushButton_2 = new QPushButton(page);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(340, 440, 113, 32));
        QIcon icon2;
        icon2.addPixmap(QPixmap(QString::fromUtf8("icons/stop.png")), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon2);
        pushButton_3 = new QPushButton(page);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 440, 121, 32));
        QIcon icon3;
        icon3.addPixmap(QPixmap(QString::fromUtf8("icons/sprites_09.png")), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon3);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        groupBox_2 = new QGroupBox(page_2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(19, 9, 431, 191));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 40, 111, 17));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 70, 111, 17));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 100, 101, 17));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(310, 70, 41, 17));
        comboBox = new QComboBox(groupBox_2);
        QIcon icon4;
        icon4.addPixmap(QPixmap(QString::fromUtf8(":/icons/db_add.png")), QIcon::Normal, QIcon::Off);
        comboBox->addItem(icon4, QString());
        comboBox->addItem(icon4, QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(130, 30, 161, 26));
        comboBox->setMinimumContentsLength(0);
        comboBox->setFrame(true);
        lineEdit = new QLineEdit(groupBox_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(130, 70, 161, 22));
        lineEdit->setStyleSheet(QString::fromUtf8(""));
        lineEdit_2 = new QLineEdit(groupBox_2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(130, 100, 161, 22));
        lineEdit_3 = new QLineEdit(groupBox_2);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(350, 70, 61, 22));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 130, 81, 17));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 160, 61, 17));
        lineEdit_4 = new QLineEdit(groupBox_2);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(130, 130, 161, 22));
        lineEdit_5 = new QLineEdit(groupBox_2);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(130, 160, 161, 22));
        pushButton_5 = new QPushButton(page_2);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(330, 440, 113, 32));
        QIcon icon5;
        icon5.addPixmap(QPixmap(QString::fromUtf8("icons/db_host.png")), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon5);
        pushButton_6 = new QPushButton(page_2);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(20, 440, 113, 32));
        pushButton_6->setIcon(icon3);
        groupBox_3 = new QGroupBox(page_2);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 320, 431, 111));
        checkBox_2 = new QCheckBox(groupBox_3);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(10, 30, 281, 21));
        lineEdit_6 = new QLineEdit(groupBox_3);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(70, 60, 113, 22));
        checkBox_3 = new QCheckBox(groupBox_3);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(10, 60, 51, 21));
        groupBox_4 = new QGroupBox(page_2);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(20, 200, 431, 121));
        textEdit_2 = new QTextEdit(groupBox_4);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(10, 30, 411, 80));
        textEdit_2->setStyleSheet(QString::fromUtf8("QTextEdit { \n"
"border-width: 3px; \n"
"border-style: inset; \n"
"border-color: #535353; \n"
"border-radius: 9px; \n"
"background: #ffffff; \n"
"color: #000000; \n"
"}"));
        stackedWidget->addWidget(page_2);
        sproutClass->setCentralWidget(centralWidget);

        retranslateUi(sproutClass);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(sproutClass);
    } // setupUi

    void retranslateUi(QMainWindow *sproutClass)
    {
        sproutClass->setWindowTitle(QApplication::translate("sproutClass", "2Sprout", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("sproutClass", "2sprout Status", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("sproutClass", "Start", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("sproutClass", "Stop", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("sproutClass", "Advanced", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("sproutClass", "Database", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("sproutClass", "Select Database:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("sproutClass", "Server Host:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("sproutClass", "Default DB:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("sproutClass", "Port:", 0, QApplication::UnicodeUTF8));
        comboBox->setItemText(0, QApplication::translate("sproutClass", "PostgreSQL", 0, QApplication::UnicodeUTF8));
        comboBox->setItemText(1, QApplication::translate("sproutClass", "MySQL", 0, QApplication::UnicodeUTF8));

        lineEdit->setText(QApplication::translate("sproutClass", "localhost", 0, QApplication::UnicodeUTF8));
        lineEdit_3->setText(QApplication::translate("sproutClass", "5432", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("sproutClass", "Username:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("sproutClass", "Password:", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("sproutClass", "Test", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("sproutClass", "Home", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("sproutClass", "Networking", 0, QApplication::UnicodeUTF8));
        checkBox_2->setText(QApplication::translate("sproutClass", "Enable automatic router port forwarding", 0, QApplication::UnicodeUTF8));
        lineEdit_6->setText(QApplication::translate("sproutClass", "4950", 0, QApplication::UnicodeUTF8));
        checkBox_3->setText(QApplication::translate("sproutClass", "Port", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("sproutClass", "DB Connection Status", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(sproutClass);
    } // retranslateUi

};

namespace Ui {
    class sproutClass: public Ui_sproutClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPROUT_H
