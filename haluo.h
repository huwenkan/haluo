#ifndef HALUO_H
#define HALUO_H

#include "haluoshow.h"
#include "menuwidget.h"
#include "music/musicwidget.h"
#include "note/notewidget.h"

#include <QWidget>
#include <QMouseEvent>
#include <QApplication>

class HaluoShow;
class HaluoShowLabel;
class MenuWidget;
class MusicWidget;
class NoteWidget;

//用于全局访问来更改状态
extern HaluoShow *haluoShow;
extern MenuWidget *menuWidget;
extern MusicWidget *musicWidget;
extern NoteWidget *noteWidget;

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

};
#endif // HALUO_H
