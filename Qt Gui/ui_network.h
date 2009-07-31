/********************************************************************************
** Form generated from reading ui file 'network.ui'
**
** Created: Mon Jul 27 13:20:40 2009
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_NETWORK_H
#define UI_NETWORK_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Network
{
public:
    QGroupBox *groupBox_3;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QSpinBox *spinBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;

    void setupUi(QDialog *Network)
    {
        if (Network->objectName().isEmpty())
            Network->setObjectName(QString::fromUtf8("Network"));
        Network->resize(410, 135);
        Network->setMinimumSize(QSize(410, 135));
        Network->setMaximumSize(QSize(410, 135));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/bullet_wrench.png"), QSize(), QIcon::Normal, QIcon::Off);
        Network->setWindowIcon(icon);
        groupBox_3 = new QGroupBox(Network);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 0, 391, 91));
        checkBox_2 = new QCheckBox(groupBox_3);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(10, 30, 321, 21));
        checkBox_3 = new QCheckBox(groupBox_3);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(10, 60, 241, 21));
        spinBox = new QSpinBox(groupBox_3);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(250, 60, 63, 25));
        spinBox->setMinimum(1025);
        spinBox->setMaximum(49521);
        spinBox->setValue(4950);
        pushButton = new QPushButton(Network);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(312, 100, 91, 32));
        pushButton_2 = new QPushButton(Network);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(220, 100, 91, 32));
        label = new QLabel(Network);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 110, 211, 17));
        QFont font;
        font.setPointSize(9);
        label->setFont(font);

        retranslateUi(Network);

        QMetaObject::connectSlotsByName(Network);
    } // setupUi

    void retranslateUi(QDialog *Network)
    {
        Network->setWindowTitle(QApplication::translate("Network", "Networking Preferences", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("Network", "Options", 0, QApplication::UnicodeUTF8));
        checkBox_2->setText(QApplication::translate("Network", "Enable automatic router port forwarding (UPnP)", 0, QApplication::UnicodeUTF8));
        checkBox_3->setText(QApplication::translate("Network", "Manually specify port to listen on", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Network", "OK", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Network", "Cancel", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        Q_UNUSED(Network);
    } // retranslateUi

};

namespace Ui {
    class Network: public Ui_Network {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NETWORK_H
