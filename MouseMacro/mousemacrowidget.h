#ifndef MOUSEMACROWIDGET_H
#define MOUSEMACROWIDGET_H

#include "keycontrollerthread.h"
#include "clickthread.h"

#include <QWidget>
#include <Windows.h>

class KeyControllerThread;
class ClickThread;

class MouseMacroWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MouseMacroWidget(QWidget *parent = nullptr);

    static bool ENABLE_MACRO;
    KeyControllerThread *keyControllerThread;
    ClickThread *clickThread;

signals:

};

#endif // MOUSEMACROWIDGET_H
