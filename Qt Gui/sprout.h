#ifndef SPROUT_H
#define SPROUT_H

#include <QtGui/QMainWindow>

namespace Ui
{
    class sproutClass;
}

class sprout : public QMainWindow
{
    Q_OBJECT

public:
    sprout(QWidget *parent = 0);
    ~sprout();

private:
    Ui::sproutClass *ui;

private slots:
    void readFromStdout();
    void readSTDOut();
    void on_pushButton_5_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void writeFile();
    void on_pushButton_6_clicked();
    void on_pushButton_3_clicked();
};

#endif // SPROUT_H
