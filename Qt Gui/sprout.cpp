#include "sprout.h"
#include "ui_sprout.h"
#include <qfile.h>
#include <qtextstream.h>
#include <qprocess.h>

using namespace std;
QProcess *client;
bool processStarted = false;

sprout::sprout(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::sproutClass)
{
    ui->setupUi(this);
}

sprout::~sprout()
{
    delete ui;
}

void sprout::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_2);
}

void sprout::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page);
}


/*
 This is for the saved button on the advanced menu for the database
 */
void sprout::writeFile()
{
    QFile f("client/2sprout.conf");
    if(f.open(QFile::WriteOnly))
    {
        QTextStream out(&f);
        QString useUPNP = "false";
        QString useDB = "false";
        QString dbtype = "postgres";
        QString dbhost = "localhost";
        QString dbport = "5432";
        QString dbname = "test543";
        QString dbpass = "*********";
        QString dbtable = "t2adfasd";
        QString dbCol = "2342er";

        if(ui->checkBox_2->isChecked())
        {
            useUPNP = "true";
            out << "upnp=" << useUPNP << endl;
            ui->textEdit->append("Enabling UPNP Port Forwarding");

        }
        else
        {
            out << "upnp=" << useUPNP << endl;
            ui->textEdit->append("UPNP Disabled");

        }
        if(ui->lineEdit_4->text() != "" && ui->lineEdit_5->text() != "")
        {
            useDB = "true";
            out << "usedb=" << useDB << endl;
            if(ui->comboBox->currentIndex() == 0)
            {
                out << "dbtype=" << "postgres" << endl;

            }
            else
            {
                out << "dbtype=" << "mysql" << endl;

            }

            out << "dbhost=" << ui->lineEdit->text() << endl;
            out << "dbport=" << ui->lineEdit_3->text() << endl;
            out << "dbname=" << ui->lineEdit_2->text() << endl;
            out << "dbuser=" << ui->lineEdit_4->text() << endl;
            out << "dbpassword=" << ui->lineEdit_5->text() << endl;
            out << "dbtable=" << "xmlFeed" << endl;
            out << "dbcol=" << "xml_data" << endl;



        }
        else
        {
            out << "usedb=" << useDB << endl;
            out << "dbtype="  << endl;
            out << "dbhost="  << endl;
            out << "dbport="  << endl;
            out << "dbname="  << endl;
            out << "dbuser="  << endl;
            out << "dbpassword="  << endl;
            out << "dbtable=" << endl;
            out << "dbcol=" << endl;
        }
        //out << "upnp
    }
    else
    {
        ui->textEdit->append("Could Not Open File");
    }
}

void sprout::on_pushButton_clicked()
{
    writeFile();
    //This will start the new process for 2sproutClient
    ui->textEdit->clear();
    client = new QProcess(this);

    QString portNum = ui->lineEdit_6->text();
    QStringList args;
    if(portNum != "")
    {
        args.append("-p");
        args.append(portNum);
    }

      connect( client, SIGNAL(readyReadStandardOutput()),this, SLOT(readSTDOut()));
    client->start("client/SproutClient.exe",args);


    if(client->isOpen())
    {
        ui->textEdit->append("Client Sucessfully Started");
    }
    processStarted = true;
}

void sprout::on_pushButton_2_clicked()
{
    if(processStarted == true)
    {
        client->kill();
        ui->textEdit->append("Client Stopped.");
    }

}

void sprout::on_pushButton_5_clicked()
{
    writeFile();
    //This will start the new process for 2sproutClient
    QString hello;
    client = new QProcess(this);

    QString TestDBArg = "-d";
    QStringList args;

    args.append(TestDBArg);
    connect( client, SIGNAL(readyReadStandardOutput()),
            this, SLOT(readFromStdout()));

    client->start("client/SproutClient.exe", args);

    processStarted = true;

}

void sprout::readSTDOut()
{
    QString standardOut;
    standardOut.clear();
    standardOut.append(client->readAllStandardOutput());
    ui->textEdit->append(standardOut);
}

void sprout::readFromStdout()
{
    QString standardOut;
    ui->textEdit_2->clear();
    standardOut.clear();
    standardOut.append(client->readAllStandardOutput());
    ui->textEdit_2->append(standardOut);
}

