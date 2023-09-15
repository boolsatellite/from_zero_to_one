//
// Created by satellite on 2023-09-15.
//

#include <sstream>
#include "zero_thread.h"

zero_thread::zero_thread()
    :running_(false) , th_(nullptr){}

zero_thread::~zero_thread() {
    if(th_ != nullptr) {
        if(th_->joinable()) {
            th_->detach();
        }
        delete th_;
        th_ = nullptr;
    }
}

bool zero_thread::start() {
    if(running_) {
        return false;
    }
    try {
        th_ = new std::thread(&zero_thread::threadEntry , this);
    } catch (...) {
        throw "zero::thread::start thread error";
    }
    return true;
}

void zero_thread::threadEntry() {
    running_ = true;
    try {
        run();
    } catch (std::exception & ex) {
        running_ = false;
        throw ex;
    } catch (...) {
        running_ = false;
        throw;
    }
    running_ = false;
}

size_t zero_thread::CURRENT_THREADID() {
    static thread_local size_t threadId = 0;
    if(threadId == 0 )
    {
        std::stringstream ss;
        ss << std::this_thread::get_id();
        threadId = strtol(ss.str().c_str(), NULL, 0);
    }
    return threadId;
}
void zero_thread::stop()
{
    running_ = false;
}

bool zero_thread::isAlive() const
{
    return running_;
}

void zero_thread::join()
{
    if (th_->joinable())
    {
        th_->join();  // 不是detach才去join
    }
}

void zero_thread::detach()
{
    th_->detach();
}

std::thread *zero_thread::getThread() {
    return th_;
}
