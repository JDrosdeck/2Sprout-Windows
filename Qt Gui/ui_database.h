/********************************************************************************
** Form generated from reading ui file 'database.ui'
**
** Created: Mon Jul 27 13:19:29 2009
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_DATABASE_H
#define UI_DATABASE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Database
{
public:
    QGroupBox *groupBox_2;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout_2;
    QLabel *label_8;
    QComboBox *comboBox_2;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_9;
    QSpacerItem *horizontalSpacer;
    QLabel *label_13;
    QSpinBox *spinBox;
    QLabel *label_10;
    QLineEdit *lineEdit_6;
    QLabel *label_11;
    QLineEdit *lineEdit_7;
    QLabel *label_12;
    QLineEdit *lineEdit_8;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label;

    void setupUi(QDialog *Database)
    {
        if (Database->objectName().isEmpty())
            Database->setObjectName(QString::fromUtf8("Database"));
        Database->resize(474, 253);
        Database->setMinimumSize(QSize(0, 0));
        Database->setMaximumSize(QSize(474, 253));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/database_connect.png"), QSize(), QIcon::Normal, QIcon::Off);
        Database->setWindowIcon(icon);
        groupBox_2 = new QGroupBox(Database);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(19, 9, 431, 201));
        formLayoutWidget = new QWidget(groupBox_2);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 30, 411, 171));
        formLayout_2 = new QFormLayout(formLayoutWidget);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(formLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_8);

        comboBox_2 = new QComboBox(formLayoutWidget);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, comboBox_2);

        label_9 = new QLabel(formLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_9);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEdit_9 = new QLineEdit(formLayoutWidget);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_9->sizePolicy().hasHeightForWidth());
        lineEdit_9->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(lineEdit_9);

        horizontalSpacer = new QSpacerItem(30, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_13 = new QLabel(formLayoutWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy1);
        label_13->setMinimumSize(QSize(0, 0));

        horizontalLayout->addWidget(label_13);

        spinBox = new QSpinBox(formLayoutWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(spinBox->sizePolicy().hasHeightForWidth());
        spinBox->setSizePolicy(sizePolicy2);
        spinBox->setMinimumSize(QSize(30, 0));
        spinBox->setBaseSize(QSize(30, 0));
        spinBox->setMinimum(1025);
        spinBox->setMaximum(49150);
        spinBox->setValue(5432);

        horizontalLayout->addWidget(spinBox);


        formLayout_2->setLayout(2, QFormLayout::FieldRole, horizontalLayout);

        label_10 = new QLabel(formLayoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_10);

        lineEdit_6 = new QLineEdit(formLayoutWidget);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        sizePolicy.setHeightForWidth(lineEdit_6->sizePolicy().hasHeightForWidth());
        lineEdit_6->setSizePolicy(sizePolicy);
        lineEdit_6->setMinimumSize(QSize(50, 0));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, lineEdit_6);

        label_11 = new QLabel(formLayoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_11);

        lineEdit_7 = new QLineEdit(formLayoutWidget);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        sizePolicy.setHeightForWidth(lineEdit_7->sizePolicy().hasHeightForWidth());
        lineEdit_7->setSizePolicy(sizePolicy);

        formLayout_2->setWidget(4, QFormLayout::FieldRole, lineEdit_7);

        label_12 = new QLabel(formLayoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        formLayout_2->setWidget(5, QFormLayout::LabelRole, label_12);

        lineEdit_8 = new QLineEdit(formLayoutWidget);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));
        sizePolicy.setHeightForWidth(lineEdit_8->sizePolicy().hasHeightForWidth());
        lineEdit_8->setSizePolicy(sizePolicy);

        formLayout_2->setWidget(5, QFormLayout::FieldRole, lineEdit_8);

        pushButton_2 = new QPushButton(Database);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(370, 210, 81, 32));
        pushButton_2->setAutoFillBackground(true);
        pushButton_3 = new QPushButton(Database);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(280, 210, 81, 32));
        label = new QLabel(Database);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 220, 221, 17));
        QFont font;
        font.setPointSize(9);
        label->setFont(font);

        retranslateUi(Database);

        QMetaObject::connectSlotsByName(Database);
    } // setupUi

    void retranslateUi(QDialog *Database)
    {
        Database->setWindowTitle(QApplication::translate("Database", "Database", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("Database", "Databases", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Database", "Engine", 0, QApplication::UnicodeUTF8));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("Database", "PostgreSQL", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Database", "MySQL", 0, QApplication::UnicodeUTF8)
        );
        label_9->setText(QApplication::translate("Database", "Server Host", 0, QApplication::UnicodeUTF8));
        lineEdit_9->setText(QApplication::translate("Database", "localhost", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("Database", "Port", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("Database", "Username", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("Database", "Password", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("Database", "Database Name", 0, QApplication::UnicodeUTF8));
        lineEdit_8->setText(QApplication::translate("Database", "twosprout", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Database", "OK", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("Database", "Cancel", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        Q_UNUSED(Database);
    } // retranslateUi

};

namespace Ui {
    class Database: public Ui_Database {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATABASE_H
