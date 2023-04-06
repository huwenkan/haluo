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
    skinWidget->setGeometry(0,200,150,50);
    skinLabel = new QLabel(skinWidget);
    skinLabel->resize(150,50);
    QPushButton *button1 = new QPushButton("绿色", skinLabel);
    button1->setStyleSheet("background-color: rgba(0, 255, 0, 0.3)");
    button1->setGeometry(0,0,75,50);
    connect(button1,&QPushButton::clicked,[&](){
        for (int i=0; i<8; i++) {
            haluoShwoLabel->staticShowPixmap[i] = haluoShwoLabel->haluoStaticPixmap[i];
            haluoShwoLabel->touchShowPixmap[i] = haluoShwoLabel->haluoTouchPixmap[i];
        }
        skinWidget->close();
    });
    QPushButton *button2 = new QPushButton("黑色", skinLabel);
    button2->setStyleSheet("background-color: rgba(0, 0, 0, 0.3)");
    button2->setGeometry(75,0,75,50);
    connect(button2,&QPushButton::clicked,[&](){
        for (int i=0; i<8; i++) {
            haluoShwoLabel->staticShowPixmap[i] = haluoShwoLabel->haluoStaticBlackPixmap[i];
            haluoShwoLabel->touchShowPixmap[i] = haluoShwoLabel->haluoTouchBlackPixmap[i];
        }
        skinWidget->close();
    });
    skinLabel->show();
    skinWidget->close();
}

HaluoShow::~HaluoShow()
{
    delete ui;
}
