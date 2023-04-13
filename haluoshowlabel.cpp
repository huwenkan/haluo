#include "haluoshowlabel.h"

//显示haluo
HaluoShowLabel::HaluoShowLabel(QWidget *parent) : QLabel(parent)
{
    //初始化动态切换图片
    //绿色
    addPixmapList(haluoStaticPixmap,haluoTouchPixmap,":/haluo_static/demo0%1.png",":/haluo_touch/demo0%1.png",8,8);
    //黑色
    addPixmapList(haluoStaticBlackPixmap,haluoTouchBlackPixmap,":/haluo_static_black/demo%1.png",":/haluo_touch_black/demo%1.png",8,8);
    //粉色
    addPixmapList(haluoStaticPinkPixmap,haluoTouchPinkPixmap,":/haluo_static_pink/demo%1.png",":/haluo_touch_pink/demo%1.png",8,8);
    //黄色
    addPixmapList(haluoStaticYellowPixmap,haluoTouchYellowPixmap,":/haluo_static_yellow/demo%1.png",":/haluo_touch_yellow/demo%1.png",8,8);

    for (int i=0; i<8; i++) {
        staticShowPixmap[i]=haluoStaticPixmap[i];
        touchShowPixmap[i]=haluoTouchPixmap[i];
    }
    for (int i=0; i<8; i++) {
        staticShowPixmap[i]=haluoStaticPixmap[i];
        touchShowPixmap[i]=haluoTouchPixmap[i];
    }
    //初始化定时器
    haluoStaticTimer = new QTimer();
    connect(haluoStaticTimer,&QTimer::timeout,[&](){
        if(haluoStaticNum>7){
            haluoStaticNum=0;
        }
        this->setPixmap(*staticShowPixmap[haluoStaticNum++]);
    });
    haluoStaticTimer->start(50);

    haluoTouchTimer= new QTimer();
    connect(haluoTouchTimer,&QTimer::timeout,[&](){
        if(haluoTouchNum>7){
            haluoTouchNum=0;
        }
        this->setPixmap(*touchShowPixmap[haluoTouchNum++]);
    });

    setGeometry(250,0,haluoStaticPixmap[0]->width(),haluoStaticPixmap[0]->height());
}
//鼠标进入后切换动作
void HaluoShowLabel::enterEvent(QEvent *event)
{
        haluoStaticTimer->stop();
        haluoTouchTimer->start(35);
}
//鼠标离开后切换为默认状态
void HaluoShowLabel::leaveEvent(QEvent *event)
{
    haluoStaticTimer->start(50);
    haluoTouchTimer->stop();
}

void HaluoShowLabel::addPixmapList(QPixmap *staticPixmap[],QPixmap *touchPixmap[],QString staticPath,QString touchPath, int staticNum,int touchNum)
{
    for (int i=0; i<staticNum; i++) {
        QString path=staticPath.arg(i+1);
        staticPixmap[i]=new QPixmap(path);
    }
    for (int i=0; i<touchNum; i++) {
        QString path=touchPath.arg(i+1);
        touchPixmap[i]=new QPixmap(path);
    }
}
