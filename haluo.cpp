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
}

haluo::~haluo()
{
    delete ui;
}

