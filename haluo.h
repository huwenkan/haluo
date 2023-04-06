#ifndef HALUO_H
#define HALUO_H

#include "haluoshow.h"
#include "menuwidget.h"

#include <QWidget>
#include <QMouseEvent>
#include <QApplication>

//用于全局访问来更改状态
extern HaluoShow *haluoShow;

QT_BEGIN_NAMESPACE
namespace Ui { class haluo; }
QT_END_NAMESPACE

extern QApplication *app;

class haluo : public QWidget
{
    Q_OBJECT

public:
    haluo(QWidget *parent = nullptr);
    ~haluo();
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;

private:
    Ui::haluo *ui;
    QPoint dragPosition;
    bool childWidgetFlag = false;
    MenuWidget *menuWidget = nullptr;

};
#endif // HALUO_H
