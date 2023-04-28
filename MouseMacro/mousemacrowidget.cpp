#include "mousemacrowidget.h"

#include <QDebug>

bool MouseMacroWidget::ENABLE_MACRO = false;

MouseMacroWidget::MouseMacroWidget(QWidget *parent) : QWidget(parent)
{
    keyControllerThread = new KeyControllerThread();
    clickThread = new ClickThread();
    keyControllerThread->start();
    clickThread->start();
    KeyControllerThread::mtx->lock();
}
