#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>

extern QString dbtype;
extern QString dbhost;
extern QString dbuser;
extern QString dbpass;
extern QString dbdefault;
extern int dbport;


extern bool enableUPNP;
extern bool manualPort;
extern int sproutPort;

extern QString apiKey;

namespace Ui
{
    class MainWindowClass;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
void MainWindow::writeFile();







private:
    Ui::MainWindowClass *ui;


private slots:

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_actionDeveloper_Key_triggered();
    void on_actionDatabase_triggered();
    void on_actionNetwork_triggered();
    void readSTDOut();
    void readFromStdout();

};

#endif // MAINWINDOW_H
