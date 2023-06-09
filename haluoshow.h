#ifndef HALUOSHOW_H
#define HALUOSHOW_H

#include "haluoshowlabel.h"
#include "haluo.h"

#include <QWidget>
#include <QPushButton>

//label标签用于全局访问来更改状态
extern HaluoShowLabel *haluoShwoLabel;

namespace Ui {
class HaluoShow;
}

class HaluoShow : public QWidget
{
    Q_OBJECT

public:
    explicit HaluoShow(QWidget *parent = nullptr);
    ~HaluoShow();
    QWidget *skinWidget;
    QLabel *skinLabel;

    void connectButton(QPushButton *button1,QPixmap *haluoStaticPixmap[],QPixmap *haluoTouchPixmap[],QString style);
    
private:
    Ui::HaluoShow *ui;
};

#endif // HALUOSHOW_H
