#include "keycontrollerthread.h"

KeyControllerThread::KeyControllerThread()
{

}
void KeyControllerThread::run(){
    HHOOK keyHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyControllerThread::KeyProc, NULL, 0);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    UnhookWindowsHookEx(keyHook);
}
//键盘事件回调函数
LRESULT CALLBACK KeyControllerThread::KeyProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    if (nCode < 0)
    {
        return CallNextHookEx(NULL, nCode, wParam, lParam);
    }
    //检测按下的按键是否要开启宏功能
    if (nCode == HC_ACTION && (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN))
    {
        KBDLLHOOKSTRUCT* p = reinterpret_cast<KBDLLHOOKSTRUCT*>(lParam);
        wchar_t keyName[256];
        if (GetKeyNameTextW(p->scanCode << 16, keyName, 256))
        {
            QString name = QString::fromWCharArray(keyName);
            if(name.compare("X")==0 && !StartThread::PRESS_X){
                qDebug()<<"按下X";
                StartThread::PRESS_X = true;
            } else if(name.compare("X")==0 && StartThread::PRESS_X){
                StartThread::PRESS_X = false;
                qDebug()<<"再次按下X";
            }
        }
    }

    return CallNextHookEx(NULL, nCode, wParam, lParam);
}
