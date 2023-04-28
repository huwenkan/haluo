#ifndef CLICKTHREAD_H
#define CLICKTHREAD_H

#include "keycontrollerthread.h"

#include <QThread>

class ClickThread : public QThread
{
public:
    ClickThread();
    void run() override;
};

#endif // CLICKTHREAD_H
