#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "database.h"
#include "ui_database.h"
#include "network.h"
#include "ui_network.h"
#include "developer.h"
#include "ui_developer.h"
#include <qfile.h>
#include <qtextstream.h>
#include <qprocess.h>

//External declarations for database dialog box
extern QString dbtype;
extern QString dbhost;
extern QString dbuser;
extern QString dbpass;
extern QString dbdefault;
extern int dbport;

//Extern declarations for networking dialog box
extern bool enableUPNP;
extern bool manualPort;
extern int sproutPort;

//External declaration for API Key
extern QString apiKey;

QString dbtype = "none";
QString dbhost = "";
QString dbuser = "";
QString dbpass = "";
QString dbdefault = "";
int dbport = 3306;

bool useDatabase = false;
bool enableUPNP = false;
bool manualPort = false;
int sproutPort = 4950;

QString apiKey = "";


//Declarations for running the client thread
QProcess *client;
bool processStarted = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindowClass)
{

    ui->setupUi(this);

    QFile f("client/2sprout.conf");
    if(!f.open(QFile::ReadOnly))
    {
         ui->textEdit->append("Could Not Read File");
    }
    QTextStream stream(&f);
    QString line;
    QString firstSub;
    QString secondSub;
    int foundPos;

    while(!stream.atEnd())
    {
        firstSub = "";
        secondSub = "";
        line = stream.readLine();
        if(line != "")
        {
            line = line.trimmed();

            //find the first occurance of an '=' sign
            foundPos = line.indexOf("=");

            if(foundPos != -1)
            {


                firstSub = line.left(foundPos);
                secondSub = line.right(line.length() - (foundPos + 1));

                firstSub = firstSub.trimmed();
                secondSub = secondSub.trimmed();

                if(firstSub == "usedb" && secondSub == "false")
                {
                    useDatabase = false;
                }
                else if(firstSub == "usedb" && secondSub == "true")
                {
                    useDatabase = true;
                }

                if(firstSub == "dbtype" && secondSub != "")
                {
                    dbtype = secondSub;

                }
                if(firstSub == "dbhost" && secondSub != "") //
                                        {
                        dbhost = secondSub;

                }
                if(firstSub == "dbport" && secondSub != "") //
                {
                        dbport = atoi(secondSub.toStdString().c_str());

                }
                if(firstSub == "dbname" && secondSub != "")
                {
                        dbdefault = secondSub;

                }
                if(firstSub == "dbuser" && secondSub != "")
                {
                        dbuser = secondSub;

                }
                if(firstSub == "dbpassword" && secondSub != "")
                {
                        dbpass = secondSub;

                }
                if(firstSub == "dbtable" && secondSub != "")
                {
                        //Keep open for now

                }
                if(firstSub == "dbcol" && secondSub != "")
                {
                        //Keep open for now

                }
                if(firstSub == "upnp" && secondSub != "")
                {
                    if(secondSub == "true")
                        enableUPNP = true;
                    else if(secondSub == "false")
                        enableUPNP = false;

                }
                if(firstSub == "apiKey" && secondSub != "")
                {
                        apiKey = secondSub;
                }
            }
        }
    }
    f.close();

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_actionNetwork_triggered()
{
    Network *net = new Network();
    net->show();
}

void MainWindow::on_actionDatabase_triggered()
{
    Database *db = new Database();
    db->show();
}

void MainWindow::on_actionDeveloper_Key_triggered()
{
    Developer *dev = new Developer();
    dev->show();

}

void MainWindow::writeFile()
{
    QFile f("client/2sprout.conf");
    if(f.open(QFile::WriteOnly))
    {
        QTextStream out(&f);


            out << "apiKey=" << apiKey << endl;

            if(enableUPNP == true)
            {
                out << "upnp=true" << endl;
            }
            else
            {
                out << "upnp=false" << endl;
            }
            if(useDatabase)
            {
                out << "usedb=true" << endl;
                out << "dbtype=" << dbtype << endl;
                out << "dbhost=" << dbhost << endl;
                out << "dbport=" << dbport << endl;
                out << "dbname=" << dbdefault << endl;
                out << "dbuser=" << dbuser << endl;
                out << "dbpassword=" << dbpass << endl;
                out << "dbtable=xmlFeed" << endl;
                out << "dbcol=xml_data" << endl;
            }
            else
            {
                out << "usedb=false" << endl;
                out << "dbtype=" << dbtype << endl;
                out << "dbhost=" << dbhost << endl;
                out << "dbport=" << dbport << endl;
                out << "dbname=" << dbdefault << endl;
                out << "dbuser=" << dbuser << endl;
                out << "dbpassword=" << dbpass << endl;
                out << "dbtable=xmlFeed" << endl;
                out << "dbcol=xml_data" << endl;
            }



    }
    else
    {
        ui->textEdit->append("Could Not Open File");
    }
}



void MainWindow::on_pushButton_clicked()
{
    if(apiKey.isEmpty() == false)
    {
        writeFile();

        //This will start the new process for 2sproutClient
        ui->textEdit->clear();
        client = new QProcess(this);

        QString portArg = "";
        QStringList args;
        if(sproutPort != 4950)
        {
            char Portbuffer[10];
            sprintf(Portbuffer, "%i", sproutPort);
            QString port = Portbuffer;
            portArg = port;

        }
        else
        {
            portArg = "4950";
        }

        printf("%s", portArg.toStdString().c_str());
        args.append("-p");
        args.append(portArg);

        args.append("-c");
        args.append("client/2sprout.conf");

        connect(client, SIGNAL(readyReadStandardOutput()),
                this, SLOT(readSTDOut()));

        client->start("client/SproutClient.exe",args);
        if(client->isOpen())
        {
            processStarted = true;
            ui->textEdit->append("Initializing 2Sprout Client...");
        }
        else
        {
         ui->textEdit->append("Client could not be started");
        }
    }
else
    {
ui->textEdit->clear();
ui->textEdit->setText("Please Input API Key");
}


}


void MainWindow::readSTDOut()
{
    QString standardOut;
    standardOut.clear();
    standardOut.append(client->readAllStandardOutput());
    ui->textEdit->append(standardOut);
}

void MainWindow::readFromStdout()
{
    QString standardOut;
    ui->textEdit->clear();
    standardOut.clear();
    standardOut.append(client->readAllStandardOutput());
    ui->textEdit->append(standardOut);
}

void MainWindow::on_pushButton_2_clicked()
{
    if(processStarted == true)
    {
        client->write("EXIT\n");
        //ui->textEdit->append("Client Stopped.");
        processStarted = false;
    }
}
