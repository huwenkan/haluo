#include "haluo.h"

#include <QApplication>
#include <QTextCodec>

QApplication *app;

int main(int argc, char *argv[])
{
    app = new QApplication(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));//设置字符编码

    haluo w;
    w.show();
    return app->exec();
}
