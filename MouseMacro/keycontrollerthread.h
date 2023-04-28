#ifndef KEYCONTROLLERTHREAD_H
#define KEYCONTROLLERTHREAD_H

#include "mousemacrowidget.h"

#include <QThread>
#include <windows.h>

using namespace std;

class KeyControllerThread : public QThread
{
public:
    KeyControllerThread();
    void run() override;
    static LRESULT CALLBACK KeyProc(int nCode, WPARAM wParam, LPARAM lParam);

    static bool PRESS_X;
    static mutex *mtx;

};

#endif // KEYCONTROLLERTHREAD_H
