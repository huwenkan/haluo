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
    resize(800,500);
    //设置无边框
//    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
//    setAttribute(Qt::WA_TranslucentBackground);
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
    //判断菜单窗口未打开
   if (event->button() == Qt::LeftButton) {
       dragPosition = event->globalPos() - frameGeometry().topLeft();
       event->accept();
   }
}
void haluo::mouseMoveEvent(QMouseEvent *event)
{
    //判断菜单窗口未打开
    if (event->buttons() & Qt::LeftButton) {
        move(event->globalPos() - dragPosition);
        event->accept();
    }
}
void haluo::mouseReleaseEvent(QMouseEvent *event)
{
    //判断菜单窗口未打开
    if (event->button() == Qt::LeftButton) {
        dragPosition = QPoint();
        event->accept();
    }
}
//双击出现菜单窗口
void haluo::mouseDoubleClickEvent(QMouseEvent *event)
{
    // 弹出另一个QWidget
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
