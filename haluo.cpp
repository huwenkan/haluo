#include "haluo.h"
#include "ui_haluo.h"

HaluoShow *haluoShow;
MenuWidget *menuWidget;
MusicWidget *musicWidget;
NoteWidget *noteWidget;

haluo::haluo(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::haluo)
{
    ui->setupUi(this);
    resize(900,500);
    //设置无边框
    //强制退出会报错&&启动之后第一下点击会卡顿
    setWindowFlags(Qt::Tool | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_TranslucentBackground);

    haluoShow = new HaluoShow(this);

    //设置菜单窗口,默认关闭
    menuWidget = new MenuWidget(this);

    //创建音乐窗口
    musicWidget = new MusicWidget(this);

    //创建记事本窗口
    noteWidget = new NoteWidget(this);

}

haluo::~haluo()
{
    delete ui;
}
//设置鼠标可拖动
void haluo::mousePressEvent(QMouseEvent *event)
{
   if (event->button() == Qt::LeftButton) {
       dragPosition = event->globalPos() - frameGeometry().topLeft();
       event->accept();
   }
   //右键打开菜单窗口
   else if (event->button() == Qt::RightButton) {
       if(!menuWidget->menuWidgetFlag){
            menuWidget->show();
            menuWidget->menuWidgetFlag = true;
       }else {
            //功能总窗口
            menuWidget->menuWidgetFlag = false;
            menuWidget->close();
            //皮肤
            haluoShow->skinWidget->close();
            menuWidget->skinFlag = false;
            //音乐
            musicWidget->close();
            musicWidget->musicFlag = false;
            //记事本
            noteWidget->close();
            noteWidget->noteFlag = false;
       }
    }
}
void haluo::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
        move(event->globalPos() - dragPosition);
        event->accept();
    }
}
void haluo::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        dragPosition = QPoint();
        event->accept();
    }
}

