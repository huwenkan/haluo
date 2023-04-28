#include "clickthread.h"

#include <QDebug>

ClickThread::ClickThread()
{

}

void ClickThread::run(){
    INPUT input[2];
    input[0].type = INPUT_MOUSE;
    input[0].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    input[1].type = INPUT_MOUSE;
    input[1].mi.dwFlags = MOUSEEVENTF_LEFTUP;
    while (true) {
        KeyControllerThread::mtx->lock();
        SendInput(2,input,sizeof(INPUT));
    }
}
