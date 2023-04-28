#ifndef MOUSECONTROLLERTHREAD_H
#define MOUSECONTROLLERTHREAD_H

#include "startthread.h"

#include <QThread>
#include <Windows.h>

class ControllerThread : public QThread
{
public:
    ControllerThread();
    void run() override;
    static LRESULT CALLBACK MouseProc(int nCode, WPARAM wParam, LPARAM lParam);

    static bool PRESS_LEFT;
};

#endif // MOUSECONTROLLERTHREAD_H
