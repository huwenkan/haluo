#include "haluo.h"

#include <QApplication>

QApplication *app;

int main(int argc, char *argv[])
{
    app = new QApplication(argc, argv);
    haluo w;
    w.show();
    return app->exec();
}
