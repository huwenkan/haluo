#include "haluoshowlabel.h"
#include <QtDebug>
HaluoShowLabel::HaluoShowLabel(QWidget *parent) : QLabel(parent)
{
    //初始化动态切换图片
    for (int i=0; i<8; i++) {
        QString path=QString(":/haluo_static/demo0%1.png").arg(i+1);
        haluoStaticPixmap[i]=new QPixmap(path);
    }
    for (int i=0; i<8; i++) {
        QString path=QString(":/haluo_index/demo0%1.png").arg(i+1);
        haluoTouchPixmap[i]=new QPixmap(path);
    }
    //初始化定时器
    haluoStaticTimer = new QTimer();
    connect(haluoStaticTimer,&QTimer::timeout,[&](){
        if(haluoStaticNum>7){
            haluoStaticNum=0;
        }
        this->setPixmap(*haluoStaticPixmap[haluoStaticNum++]);
    });
    haluoStaticTimer->start(50);

    haluoTouchTimer= new QTimer();
    connect(haluoTouchTimer,&QTimer::timeout,[&](){
        if(haluoToucNum>7){
            haluoToucNum=0;
        }
        this->setPixmap(*haluoTouchPixmap[haluoToucNum++]);
    });

    setGeometry(200,0,haluoStaticPixmap[0]->width(),haluoStaticPixmap[0]->height());
}
//鼠标进入后切换动作
void HaluoShowLabel::enterEvent(QEvent *event)
{
        haluoStaticTimer->stop();
        haluoTouchTimer->start(50);
}
//鼠标离开后切换为默认状态
void HaluoShowLabel::leaveEvent(QEvent *event)
{
    haluoStaticTimer->start(50);
    haluoTouchTimer->stop();
}
