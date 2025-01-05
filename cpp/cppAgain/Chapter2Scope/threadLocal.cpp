#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

thread_local int val = 0;
int valNotThreadLocal = 0;

std::mutex mux;

void foo(int threadID)
{
    int i = 0;
    while(i < 5)
    {
        val++;
        std::lock_guard<std::mutex> locker(mux);
        valNotThreadLocal++;
        std::cout << "Thread ID = " << threadID << ",";
        std::cout << "Thread Local =  " << val << " Not Local = " << valNotThreadLocal << "\n";
        i++;
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

//Each thread will have separate instance of a static variable
void fooStatic()
{
    thread_local static int i = 0;
}

int main()
{
   std::thread t1(foo,1);
   std::thread t2(foo,2);
   std::thread t3(foo,3);
   std::thread t4(foo,4);

   t1.join();
   t2.join();
   t3.join();
   t4.join();
}
