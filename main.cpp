#include "haluo.h"

#include <QApplication>
#include <QTextCodec>

QApplication *app;

int main(int argc, char *argv[])
{
    app = new QApplication(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));//设置字符编码

    // 创建系统托盘图标
    QSystemTrayIcon *trayIcon = new QSystemTrayIcon();
    trayIcon->setIcon(QIcon(":/ico/haluo_blue.png"));
    trayIcon->setVisible(true);

    // 创建托盘图标菜单
    QMenu *trayIconMenu = new QMenu();
    QAction *quitAction = new QAction("退出");
    QObject::connect(quitAction, &QAction::triggered, app, &QApplication::quit);
    trayIconMenu->addAction(quitAction);
    trayIcon->setContextMenu(trayIconMenu);

    // 将应用程序最小化至系统托盘
    QObject::connect(app, &QApplication::aboutToQuit, [=](){
        trayIcon->hide();
        delete trayIcon;
    });
    QObject::connect(trayIcon, &QSystemTrayIcon::activated, [=](QSystemTrayIcon::ActivationReason reason){
        if (reason == QSystemTrayIcon::Trigger) {
            // 恢复应用程序窗口
        }
    });

    haluo w;
    w.hide();
    w.show();
    return app->exec();
}
