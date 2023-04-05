#include "haluo.h"
#include "ui_haluo.h"

haluo::haluo(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::haluo)
{
    ui->setupUi(this);
    //设置无边框
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_TranslucentBackground);
    haluoShow = new HaluoShow(this);
    resize(800,800);
}

haluo::~haluo()
{
    delete ui;
}
//设置鼠标可拖动
void haluo::mousePressEvent(QMouseEvent *event)
{
    //判断菜单窗口未打开
   if (event->button() == Qt::LeftButton && !childWidgetFlag) {
       dragPosition = event->globalPos() - frameGeometry().topLeft();
       event->accept();
   }
}

void haluo::mouseMoveEvent(QMouseEvent *event)
{
    //判断菜单窗口未打开
    if (event->buttons() & Qt::LeftButton && !childWidgetFlag) {
        move(event->globalPos() - dragPosition);
        event->accept();
    }
}

void haluo::mouseReleaseEvent(QMouseEvent *event)
{
    //判断菜单窗口未打开
    if (event->button() == Qt::LeftButton && !childWidgetFlag) {
        dragPosition = QPoint();
        event->accept();
    }
}
//双击出现菜单窗口
void haluo::mouseDoubleClickEvent(QMouseEvent *event)
{
    // 弹出另一个QWidget
    if(!childWidgetFlag){
        if(menuWidget == nullptr)
        {
            menuWidget = new MenuWidget(this);
        }
        else
        {
            menuWidget->show();
        }
         childWidgetFlag = true;
    }else {
         childWidgetFlag = false;
         menuWidget->close();
    }
}
