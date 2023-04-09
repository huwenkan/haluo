#include "haluoshow.h"
#include "ui_haluoshow.h"

HaluoShowLabel *haluoShwoLabel;

HaluoShow::HaluoShow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HaluoShow)
{
    ui->setupUi(this);
    haluoShwoLabel = new HaluoShowLabel(this);
    resize(400,350);

    //皮肤按钮窗口,默认关闭
    skinWidget = new QWidget(this);
    skinWidget->setGeometry(0,200,300,50);
    skinLabel = new QLabel(skinWidget);
    skinLabel->resize(300,50);
    QPushButton *button1 = new QPushButton("绿色", skinLabel);
    button1->setStyleSheet("background-color: rgba(0, 255, 0, 0.5)");
    button1->setGeometry(0,0,75,50);
    connect(button1,&QPushButton::clicked,[&](){
        for (int i=0; i<8; i++) {
            haluoShwoLabel->staticShowPixmap[i] = haluoShwoLabel->haluoStaticPixmap[i];
            haluoShwoLabel->touchShowPixmap[i] = haluoShwoLabel->haluoTouchPixmap[i];
        }
        //选中皮肤后关闭窗口，并将标志位设置为false
        menuWidget->skinFlag = false;
        skinWidget->close();
        //菜单总窗口关闭
        menuWidget->close();
        //音乐窗口关闭
//        musicWidget->close();
    });
    QPushButton *button2 = new QPushButton("黑色", skinLabel);
    button2->setStyleSheet("background-color: rgba(0, 0, 0, 0.5)");
    button2->setGeometry(75,0,75,50);
    connect(button2,&QPushButton::clicked,[&](){
        for (int i=0; i<8; i++) {
            haluoShwoLabel->staticShowPixmap[i] = haluoShwoLabel->haluoStaticBlackPixmap[i];
            haluoShwoLabel->touchShowPixmap[i] = haluoShwoLabel->haluoTouchBlackPixmap[i];
        }
        //选中皮肤后关闭窗口，并将标志位设置为false
        menuWidget->skinFlag = false;
        skinWidget->close();
        //菜单总窗口关闭
        menuWidget->close();
        //音乐窗口关闭
//        musicWidget->close();
    });
    QPushButton *button3 = new QPushButton("粉色", skinLabel);
    button3->setStyleSheet("background-color: rgba(255, 192, 203, 0.5)");
    button3->setGeometry(150,0,75,50);
    connect(button3,&QPushButton::clicked,[&](){
        for (int i=0; i<8; i++) {
            haluoShwoLabel->staticShowPixmap[i] = haluoShwoLabel->haluoStaticPinkPixmap[i];
            haluoShwoLabel->touchShowPixmap[i] = haluoShwoLabel->haluoTouchPinkPixmap[i];
        }
        //选中皮肤后关闭窗口，并将标志位设置为false
        menuWidget->skinFlag = false;
        skinWidget->close();
        //菜单总窗口关闭
        menuWidget->close();
        //音乐窗口关闭
//        musicWidget->close();
    });
    QPushButton *button4 = new QPushButton("黄色", skinLabel);
    button4->setStyleSheet("background-color: rgba(255, 255, 0, 0.5)");
    button4->setGeometry(225,0,75,50);
    connect(button4,&QPushButton::clicked,[&](){
        for (int i=0; i<8; i++) {
            haluoShwoLabel->staticShowPixmap[i] = haluoShwoLabel->haluoStaticYellowPixmap[i];
            haluoShwoLabel->touchShowPixmap[i] = haluoShwoLabel->haluoTouchYellowPixmap[i];
        }
        //选中皮肤后关闭窗口，并将标志位设置为false
        menuWidget->skinFlag = false;
        skinWidget->close();
        //菜单总窗口关闭
        menuWidget->close();
        //音乐窗口关闭
//        musicWidget->close();
    });
    skinLabel->show();
    skinWidget->close();
}

HaluoShow::~HaluoShow()
{
    delete ui;
}
