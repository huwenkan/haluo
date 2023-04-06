#include "menuwidget.h"

MenuWidget::MenuWidget(QWidget *parent) : QWidget(parent)
{
    QLabel *label = new QLabel(this);
    label->setFixedSize(200,200);
    label->show();

    QPushButton *button1 = new QPushButton("记事本", label);
    button1->setGeometry(0,0,100,100);
    QPushButton *button2 = new QPushButton("音乐", label);
    button2->setGeometry(100,0,100,100);

    QPushButton *button3 = new QPushButton("更换皮肤", label);
    button3->setGeometry(0,100,100,100);
    connect(button3,&QPushButton::clicked,[&](){
        haluoShow->skinWidget->show();
    });
    QPushButton *button4 = new QPushButton("退出", label);
    button4->setGeometry(100,100,100,100);
    connect(button4, &QPushButton::clicked, app, &QApplication::quit);

    this->setGeometry(0,0,200,200);
    this->setStyleSheet("background-color: rgba(255, 0, 0, 0.2);");
}
