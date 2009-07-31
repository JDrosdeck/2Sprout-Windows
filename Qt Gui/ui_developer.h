/********************************************************************************
** Form generated from reading ui file 'developer.ui'
**
** Created: Mon Jul 27 12:53:44 2009
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_DEVELOPER_H
#define UI_DEVELOPER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Developer
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QGroupBox *groupBox;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;

    void setupUi(QDialog *Developer)
    {
        if (Developer->objectName().isEmpty())
            Developer->setObjectName(QString::fromUtf8("Developer"));
        Developer->resize(401, 118);
        Developer->setMinimumSize(QSize(401, 118));
        Developer->setMaximumSize(QSize(401, 118));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/key_add.png"), QSize(), QIcon::Normal, QIcon::Off);
        Developer->setWindowIcon(icon);
        pushButton = new QPushButton(Developer);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(300, 80, 91, 32));
        pushButton_2 = new QPushButton(Developer);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(210, 80, 91, 32));
        groupBox = new QGroupBox(Developer);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 0, 381, 80));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 40, 91, 17));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(110, 40, 261, 22));
        label_2 = new QLabel(Developer);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(15, 87, 181, 17));
        QFont font;
        font.setPointSize(9);
        label_2->setFont(font);

        retranslateUi(Developer);

        QMetaObject::connectSlotsByName(Developer);
    } // setupUi

    void retranslateUi(QDialog *Developer)
    {
        Developer->setWindowTitle(QApplication::translate("Developer", "Developer Key", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Developer", "OK", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Developer", "Cancel", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Developer", "Key", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Developer", "Developer Key", 0, QApplication::UnicodeUTF8));
        label_2->setText(QString());
        Q_UNUSED(Developer);
    } // retranslateUi

};

namespace Ui {
    class Developer: public Ui_Developer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVELOPER_H
