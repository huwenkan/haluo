#ifndef MOUSEMACROWIDGET_H
#define MOUSEMACROWIDGET_H

#include "startthread.h"
#include "controllerthread.h"
#include "keycontrollerthread.h"

#include <QWidget>
#include <QKeyEvent>
#include <Windows.h>

class MouseMacroWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MouseMacroWidget(QWidget *parent = nullptr);

    StartThread *startThread;
    ControllerThread *controllerThread;
    KeyControllerThread *keyControllerThread;

signals:

};

#endif // MOUSEMACROWIDGET_H
