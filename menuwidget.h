#ifndef MENUWIDGET_H
#define MENUWIDGET_H

#include "haluo.h"
#include "haluoshowlabel.h"

#include <QWidget>
#include <QPushButton>
#include <QLabel>

class MenuWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MenuWidget(QWidget *parent = nullptr);

signals:

};

#endif // MENUWIDGET_H
