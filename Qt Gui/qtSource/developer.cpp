#include "developer.h"
#include "ui_developer.h"
#include "mainwindow.h"



Developer::Developer(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::Developer)
{

    m_ui->setupUi(this);
    if(apiKey.isNull() == false)
    {
        m_ui->lineEdit->setText(apiKey);
    }
}

Developer::~Developer()
{
    delete m_ui;
}

void Developer::changeEvent(QEvent *e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}





void Developer::on_pushButton_2_clicked()
{
    this->close();
}





void Developer::on_pushButton_clicked()
{
    bool keyOk = true;
    if(m_ui->lineEdit->text().isEmpty() == false)
    {
        int keyLength = m_ui->lineEdit->text().length();
        if(keyLength == 10)
        {
            int x;\
            for(x=0;x < keyLength; x++)
            {
                if((m_ui->lineEdit->text().at(x).isLetterOrNumber()) == false)
                {
                     keyOk = false;
                     m_ui->label_2->clear();
                     m_ui->label_2->setText("Improper API Character");
                }

            }
            if(keyOk == true)
            {
                apiKey.clear();
                apiKey = m_ui->lineEdit->text();
                this->close();
            }
        }
    else
    {
        m_ui->label_2->clear();
        m_ui->label_2->setText("Input proper API key");
    }
}
m_ui->label_2->clear();
m_ui->label_2->setText("Input proper API key");
}
