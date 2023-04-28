#include "startthread.h"

bool StartThread::PRESS_X = false;
bool StartThread::ENABLE_MACRO=false;
bool StartThread::CONTINUE_PRESS=false;
mutex *StartThread::mtx=new mutex();

StartThread::StartThread()
{
    //程序启动时先锁定
    mtx->lock();
}

void StartThread::run(){
    HHOOK mouseHook = SetWindowsHookEx(WH_MOUSE_LL, StartThread::MouseProc, NULL, 0);
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        qDebug()<<"GetMessage点击";
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    UnhookWindowsHookEx(mouseHook);

}
LRESULT CALLBACK StartThread::MouseProc(int nCode, WPARAM wParam, LPARAM lParam){
    HWND hwndTarget = FindWindow(NULL, L"Window Title");
    if (nCode < 0)
    {
        return CallNextHookEx(NULL, nCode, wParam, lParam);
    }
    INPUT input[1];
    input[0].type = INPUT_MOUSE;
    input[0].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
//    input[1].type = INPUT_MOUSE;
//    input[1].mi.dwFlags = MOUSEEVENTF_LEFTUP;
    if(StartThread::ENABLE_MACRO && StartThread::PRESS_X && ControllerThread::PRESS_LEFT){

    }
    return CallNextHookEx(NULL, nCode, wParam, lParam);
}

