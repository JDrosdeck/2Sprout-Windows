#include "network.h"
#include "ui_network.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <ctype.h>


Network::Network(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::Network)
{
    m_ui->setupUi(this);
}

Network::~Network()
{
    delete m_ui;
}

void Network::changeEvent(QEvent *e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void Network::on_pushButton_2_clicked()
{
    this->close();
}

void Network::on_pushButton_clicked()
{
    if(m_ui->checkBox_2->isChecked())
    {
        enableUPNP = true;
    }
    else
    {
        enableUPNP = false;
    }

    if(m_ui->checkBox_3->isChecked())
    {
        manualPort = true;
        sproutPort = atoi(m_ui->spinBox->text().toStdString().c_str());
    }

        this->close();

}
