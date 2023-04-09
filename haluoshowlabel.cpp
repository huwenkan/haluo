#include "haluoshowlabel.h"

//显示haluo
HaluoShowLabel::HaluoShowLabel(QWidget *parent) : QLabel(parent)
{
    //初始化动态切换图片
    //绿色
    for (int i=0; i<8; i++) {
        QString path=QString(":/haluo_static/demo0%1.png").arg(i+1);
        haluoStaticPixmap[i]=new QPixmap(path);
    }
    for (int i=0; i<8; i++) {
        QString path=QString(":/haluo_touch/demo0%1.png").arg(i+1);
        haluoTouchPixmap[i]=new QPixmap(path);
    }
    //黑色
    for (int i=0; i<8; i++) {
        QString path=QString(":/haluo_static_black/demo%1.png").arg(i+1);
        haluoStaticBlackPixmap[i]=new QPixmap(path);
    }
    for (int i=0; i<8; i++) {
        QString path=QString(":/haluo_touch_black/demo%1.png").arg(i+1);
        haluoTouchBlackPixmap[i]=new QPixmap(path);
    }
    //粉色
    for (int i=0; i<8; i++) {
        QString path=QString(":/haluo_static_pink/demo%1.png").arg(i+1);
        haluoStaticPinkPixmap[i]=new QPixmap(path);
    }
    for (int i=0; i<8; i++) {
        QString path=QString(":/haluo_touch_pink/demo%1.png").arg(i+1);
        haluoTouchPinkPixmap[i]=new QPixmap(path);
    }
    //黄色
    for (int i=0; i<8; i++) {
        QString path=QString(":/haluo_static_yellow/demo%1.png").arg(i+1);
        haluoStaticYellowPixmap[i]=new QPixmap(path);
    }
    for (int i=0; i<8; i++) {
        QString path=QString(":/haluo_touch_yellow/demo%1.png").arg(i+1);
        haluoTouchYellowPixmap[i]=new QPixmap(path);
    }

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
