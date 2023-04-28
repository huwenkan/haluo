#include "mousemacrowidget.h"

#include <QDebug>
MouseMacroWidget::MouseMacroWidget(QWidget *parent) : QWidget(parent)
{
    startThread = new StartThread();
    controllerThread = new ControllerThread();
    keyControllerThread = new KeyControllerThread();
    startThread->start();
    controllerThread->start();
    keyControllerThread->start();
}
