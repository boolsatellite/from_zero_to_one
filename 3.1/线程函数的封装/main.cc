//
// Created by satellite on 2023-09-15.
//
#include "zero_thread.h"
#include "iostream"
using namespace std;

class A: public zero_thread
{
public:
    void run()
    {
        while (running_)
        {
            cout << "print A " << endl;
            std::this_thread::sleep_for(std::chrono::seconds(5));
        }
        cout << "----- leave A " << endl;
    }
};

class B: public zero_thread
{
public:
    void run()
    {
        while (running_)
        {
            cout << "print B " << endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
        cout << "----- leave B " << endl;
    }
};

int main()
{
    {
        A a;
        a.start();
        B b;
        b.start();
        std::this_thread::sleep_for(std::chrono::seconds(5));
        a.stop();
        a.join();
        b.stop();
        b.join();  // 需要我们自己join
    }
    cout << "Hello World!" << endl;
    return 0;
}
