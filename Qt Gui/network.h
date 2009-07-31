#ifndef NETWORK_H
#define NETWORK_H

#include <QtGui/QDialog>

namespace Ui {
    class Network;
}

class Network : public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(Network)
public:
    explicit Network(QWidget *parent = 0);
    virtual ~Network();

protected:
    virtual void changeEvent(QEvent *e);

private:
    Ui::Network *m_ui;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // NETWORK_H
