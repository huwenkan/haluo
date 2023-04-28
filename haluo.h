#ifndef HALUO_H
#define HALUO_H

#include "haluoshow.h"
#include "menuwidget.h"
#include "music/musicwidget.h"
#include "note/notewidget.h"
#include "MouseMacro/mousemacrowidget.h"

#include <QWidget>
#include <QMouseEvent>
#include <QApplication>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QSystemTrayIcon>

class HaluoShow;
class HaluoShowLabel;
class MenuWidget;
class MusicWidget;
class NoteWidget;
class MouseMacroWidget;
class StartThread;

//用于全局访问来更改状态
extern HaluoShow *haluoShow;
extern MenuWidget *menuWidget;
extern MusicWidget *musicWidget;
extern NoteWidget *noteWidget;
extern MouseMacroWidget *mouseMacroWidget;

extern QApplication *app;

QT_BEGIN_NAMESPACE
namespace Ui { class haluo; }
QT_END_NAMESPACE

class haluo : public QWidget
{
    Q_OBJECT

public:
    haluo(QWidget *parent = nullptr);
    ~haluo();
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
//    void mouseDoubleClickEvent(QMouseEvent *event) override;

private:
    Ui::haluo *ui;
    QPoint dragPosition;

};
#endif // HALUO_H
