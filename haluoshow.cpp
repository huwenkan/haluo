#include "haluoshow.h"
#include "ui_haluoshow.h"

HaluoShowLabel *haluoShwoLabel;

//皮肤窗口
HaluoShow::HaluoShow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HaluoShow)
{
    ui->setupUi(this);
    haluoShwoLabel = new HaluoShowLabel(this);
    setGeometry(0,0,800,200);

    //皮肤按钮窗口,默认关闭
    skinWidget = new QWidget(this);
    skinWidget->setGeometry(0,0,50,200);
    skinLabel = new QLabel(skinWidget);
    skinLabel->setGeometry(0,0,50,200);

    QPushButton *button1 = new QPushButton("绿色", skinLabel);
    button1->setStyleSheet("background-color: rgba(0, 255, 0, 0.5);");
    button1->setGeometry(0,0,50,50);
    connect(button1,&QPushButton::clicked,[&](){
        for (int i=0; i<8; i++) {
            haluoShwoLabel->staticShowPixmap[i] = haluoShwoLabel->haluoStaticPixmap[i];
            haluoShwoLabel->touchShowPixmap[i] = haluoShwoLabel->haluoTouchPixmap[i];
        }
        menuWidget->setStyleSheet("background-color: rgba(0, 255, 0, 0.5);");
        //选中皮肤后关闭窗口，并将标志位设置为false
        menuWidget->skinFlag = false;
        skinWidget->close();
        //菜单总窗口关闭
        menuWidget->close();
        menuWidget->menuWidgetFlag=false;
        //音乐窗口关闭
        musicWidget->close();
        musicWidget->musicFlag=false;
    });
    QPushButton *button2 = new QPushButton("黑色", skinLabel);
    button2->setStyleSheet("background-color: rgba(0, 0, 0, 0.5);");
    button2->setGeometry(0,50,50,50);
    connect(button2,&QPushButton::clicked,[&](){
        for (int i=0; i<8; i++) {
            haluoShwoLabel->staticShowPixmap[i] = haluoShwoLabel->haluoStaticBlackPixmap[i];
            haluoShwoLabel->touchShowPixmap[i] = haluoShwoLabel->haluoTouchBlackPixmap[i];
        }
        menuWidget->setStyleSheet("background-color: rgba(0, 0, 0, 0.5);");
        //选中皮肤后关闭窗口，并将标志位设置为false
        menuWidget->skinFlag = false;
        skinWidget->close();
        //菜单总窗口关闭
        menuWidget->close();
        menuWidget->menuWidgetFlag=false;
        //音乐窗口关闭
        musicWidget->close();
        musicWidget->musicFlag=false;
    });
    QPushButton *button3 = new QPushButton("粉色", skinLabel);
    button3->setStyleSheet("background-color: rgba(255, 192, 203, 0.5);");
    button3->setGeometry(0,100,50,50);
    connect(button3,&QPushButton::clicked,[&](){
        for (int i=0; i<8; i++) {
            haluoShwoLabel->staticShowPixmap[i] = haluoShwoLabel->haluoStaticPinkPixmap[i];
            haluoShwoLabel->touchShowPixmap[i] = haluoShwoLabel->haluoTouchPinkPixmap[i];
        }
        menuWidget->setStyleSheet("background-color: rgba(255, 192, 203, 0.5);");
        //选中皮肤后关闭窗口，并将标志位设置为false
        menuWidget->skinFlag = false;
        skinWidget->close();
        //菜单总窗口关闭
        menuWidget->close();
        menuWidget->menuWidgetFlag=false;
        //音乐窗口关闭
        musicWidget->close();
        musicWidget->musicFlag=false;
    });
    QPushButton *button4 = new QPushButton("黄色", skinLabel);
    button4->setStyleSheet("background-color: rgba(255, 255, 0, 0.5);");
    button4->setGeometry(0,150,50,50);
    connect(button4,&QPushButton::clicked,[&](){
        for (int i=0; i<8; i++) {
            haluoShwoLabel->staticShowPixmap[i] = haluoShwoLabel->haluoStaticYellowPixmap[i];
            haluoShwoLabel->touchShowPixmap[i] = haluoShwoLabel->haluoTouchYellowPixmap[i];
        }
        menuWidget->setStyleSheet("background-color: rgba(255, 255, 0, 0.5);");
        //选中皮肤后关闭窗口，并将标志位设置为false
        menuWidget->skinFlag = false;
        skinWidget->close();
        //菜单总窗口关闭
        menuWidget->close();
        menuWidget->menuWidgetFlag=false;
        //音乐窗口关闭
        musicWidget->close();
        musicWidget->musicFlag=false;
    });
    skinLabel->show();
    skinWidget->close();
}

HaluoShow::~HaluoShow()
{
    delete ui;
}
