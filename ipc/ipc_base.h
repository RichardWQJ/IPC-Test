#ifndef _IPC_BASE_H_
#define _IPC_BASE_H_

#include <stdint.h>
#include <mqueue.h>

// #define nullptr (void *)0

class IPC_Base
{
private:
    /* data */
    char *m_mq_name[2] = {nullptr, nullptr};

public:
    IPC_Base(/* args */);
    virtual ~IPC_Base();

    void create();
    void send();
    void recieve();
};

#endif
