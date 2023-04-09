#include "haluo.h"

#include <QApplication>
#include <QTextCodec>

QApplication *app;

int main(int argc, char *argv[])
{
    app = new QApplication(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    haluo w;
    w.show();
    return app->exec();
}
