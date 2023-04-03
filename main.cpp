#include "haluo.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    haluo w;
    w.show();
    return a.exec();
}
