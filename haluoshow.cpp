#include "haluoshow.h"
#include "ui_haluoshow.h"

HaluoShow::HaluoShow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HaluoShow)
{
    ui->setupUi(this);
    haluoShwoLabel = new HaluoShowLabel(this);
    resize(400,400);
}

HaluoShow::~HaluoShow()
{
    delete ui;
}
