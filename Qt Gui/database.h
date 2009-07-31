#ifndef DATABASE_H
#define DATABASE_H

#include <QtGui/QDialog>

namespace Ui {
    class Database;
}

class Database : public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(Database)
public:
    explicit Database(QWidget *parent = 0);
    virtual ~Database();


protected:
    virtual void changeEvent(QEvent *e);

private:
    Ui::Database *m_ui;

private slots:

private slots:

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
};

#endif // DATABASE_H
