#ifndef DEVELOPER_H
#define DEVELOPER_H

#include <QtGui/QDialog>

namespace Ui {
    class Developer;
}

class Developer : public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(Developer)
public:
    explicit Developer(QWidget *parent = 0);
    virtual ~Developer();

protected:
    virtual void changeEvent(QEvent *e);

private:
    Ui::Developer *m_ui;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // DEVELOPER_H
