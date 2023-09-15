//
// Created by satellite on 2023-09-15.
//

#ifndef _ZERO_THREAD_H
#define _ZERO_THREAD_H

#include "thread"

class zero_thread {
public:
    zero_thread();
    virtual ~zero_thread();
    bool start();
    void stop();
    bool isAlive() const;
    std::thread* getThread();
    void join();
    void detach();
    static size_t CURRENT_THREADID();
protected:
    void threadEntry();
    virtual void run() = 0;
protected:
    bool running_;
    std::thread* th_;
};


#endif //_ZERO_THREAD_H
