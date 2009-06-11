#include <QtGui/QApplication>
#include "sprout.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    sprout w;
    w.show();
    return a.exec();
}
