#include "menuwidget.h"

//菜单窗口模块
MenuWidget::MenuWidget(QWidget *parent) : QWidget(parent)
{
    QLabel *label = new QLabel(this);
    label->setFixedSize(200,300);
    label->show();

    QPushButton *button1 = new QPushButton("记事本", label);
    button1->setGeometry(0,0,100,100);
    connect(button1,&QPushButton::clicked,[&](){
        if(!noteWidget->noteFlag)
        {
            noteWidget->noteFlag = true;
            noteWidget->show();
            musicWidget->musicFlag = false;
            musicWidget->close();
        }
        else
        {
            noteWidget->noteFlag = false;
            noteWidget->close();
        }
    });
    //音乐
    QPushButton *button2 = new QPushButton("音乐", label);
    button2->setGeometry(100,0,100,100);
    connect(button2,&QPushButton::clicked,[&](){
        if(!musicWidget->musicFlag)
        {
            musicWidget->musicFlag = true;
            musicWidget->show();
            noteWidget->noteFlag=false;
            noteWidget->close();
        }
        else
        {
            musicWidget->musicFlag = false;
            musicWidget->close();
        }
    });
    //更换皮肤
    QPushButton *button3 = new QPushButton("皮肤", label);
    button3->setGeometry(0,100,100,100);
    connect(button3,&QPushButton::clicked,[&](){
        if(!skinFlag){
            haluoShow->skinWidget->show();
            skinFlag = true;
        } else {
            haluoShow->skinWidget->close();
            skinFlag = false;
        }
    });
    //退出
    QPushButton *button4 = new QPushButton("退出", label);
    button4->setGeometry(100,100,100,100);
    connect(button4, &QPushButton::clicked, app, &QApplication::quit);
    //合体
    QPushButton *button5 = new QPushButton("合体", label);
    button5->setGeometry(0,200,100,100);
    connect(button5, &QPushButton::clicked, app, &QApplication::quit);
    //关闭菜单
    QPushButton *button6 = new QPushButton("关闭", label);
    button6->setGeometry(100,200,100,100);
    connect(button6, &QPushButton::clicked, [](){
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
    });

    this->setGeometry(50,0,200,300);
    this->setStyleSheet("background-color: rgba(130, 200, 250, 0.5);");
    //默认关闭
    close();
}
