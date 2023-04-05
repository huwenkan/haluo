#ifndef HALUOSHOW_H
#define HALUOSHOW_H

#include "haluoshowlabel.h"

#include <QWidget>

namespace Ui {
class HaluoShow;
}

class HaluoShow : public QWidget
{
    Q_OBJECT

public:
    explicit HaluoShow(QWidget *parent = nullptr);
    ~HaluoShow();

private:
    Ui::HaluoShow *ui;
    HaluoShowLabel *haluoShwoLabel;
};

#endif // HALUOSHOW_H
