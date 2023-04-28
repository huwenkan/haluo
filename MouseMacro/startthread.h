#ifndef STARTTHREAD_H
#define STARTTHREAD_H

#include "controllerthread.h"

#include <QThread>
#include <QKeyEvent>
#include <QDebug>
#include <QApplication>
#include <Windows.h>

using namespace std;

class StartThread : public QThread
{
public:
    static bool ENABLE_MACRO;
    static bool PRESS_X;
    static bool CONTINUE_PRESS;
    static mutex *mtx;

    StartThread();
    void run() override;
    static LRESULT CALLBACK  MouseProc(int nCode, WPARAM wParam, LPARAM lParam);
};

#endif // STARTTHREAD_H
