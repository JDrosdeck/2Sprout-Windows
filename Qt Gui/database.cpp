#include "database.h"
#include "ui_database.h"
#include "mainwindow.h"

bool activateDB = false;

Database::Database(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::Database)
{
    m_ui->setupUi(this);
}

Database::~Database()
{
    delete m_ui;
}

void Database::changeEvent(QEvent *e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}


void Database::on_pushButton_3_clicked()
{
    this->close();
}

void Database::on_pushButton_2_clicked()
{


    if(!m_ui->lineEdit_6->text().isEmpty() && !m_ui->lineEdit_7->text().isEmpty() && !m_ui->lineEdit_8->text().isEmpty() && !m_ui->lineEdit_9->text().isEmpty())
    {
        if(m_ui->comboBox_2->currentIndex() == 0)
        {
            dbtype = "postgres";
        }
        else
        {
            dbtype = "mysql";
        }

        dbhost = m_ui->lineEdit_9->text();
        dbuser = m_ui->lineEdit_6->text();
        dbpass = m_ui->lineEdit_7->text();
        dbdefault = m_ui->lineEdit_8->text();
        dbport = atoi(m_ui->spinBox->text().toStdString().c_str());

        this->close();


    }
    else
    {
        m_ui->label->clear();
        m_ui->label->setText("Invalid Configuration");
    }

}
