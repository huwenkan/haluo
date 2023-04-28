#ifndef KEYCONTROLLERTHREAD_H
#define KEYCONTROLLERTHREAD_H

#include "startthread.h"

#include <QThread>
#include <windows.h>

class KeyControllerThread : public QThread
{
public:
    KeyControllerThread();
    void run() override;
    static LRESULT CALLBACK KeyProc(int nCode, WPARAM wParam, LPARAM lParam);
};

#endif // KEYCONTROLLERTHREAD_H
