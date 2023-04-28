#include "controllerthread.h"

bool ControllerThread::PRESS_LEFT=true;

ControllerThread::ControllerThread()
{
}

void ControllerThread::run(){
    HHOOK mouseHook = SetWindowsHookEx(WH_MOUSE_LL, ControllerThread::MouseProc, NULL, 0);
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    UnhookWindowsHookEx(mouseHook);
}
LRESULT CALLBACK ControllerThread::MouseProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    if (nCode < 0)
    {
        return CallNextHookEx(NULL, nCode, wParam, lParam);
    }
    //宏功能--消抖
    if(StartThread::ENABLE_MACRO && StartThread::PRESS_X){
        if (nCode == HC_ACTION && (wParam == WM_LBUTTONDOWN || wParam == WM_LBUTTONUP))
        {
           // 如果是左键按下事件
           if (wParam == WM_LBUTTONDOWN)
           {
               if(PRESS_LEFT){
                   qDebug()<<"左键按下";
                   PRESS_LEFT=false;
                   StartThread::mtx->unlock();
               }
           }
           // 如果是左键弹起事件
           else if (wParam == WM_LBUTTONUP)
           {
               StartThread::mtx->lock();
               PRESS_LEFT=true;
               qDebug()<<"左键抬起";
           }
        }
    }

    return CallNextHookEx(NULL, nCode, wParam, lParam);
}
