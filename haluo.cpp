#include "haluo.h"
#include "ui_haluo.h"

haluo::haluo(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::haluo)
{
    ui->setupUi(this);
}

haluo::~haluo()
{
    delete ui;
}

