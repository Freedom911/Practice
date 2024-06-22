// ThreadLocal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>

thread_local int var = 10;

class A
{
public:
    mutable int y;

    void set(int vs) const
    {
        y = vs;
    }
};


int main()
{

    //1.Auto Storage Class Variables inside block.Life - till end of scope,default value garbage,scope local
    {
        int x = 3;
        int j = 4;
    }

    //2.Extern.Scope is globl,default value is 0,lifetime till end of program
    extern int k;
    int k = 3;

    //3.Static Storage Class - Used for internal linkage .Initialized only once.Scope Local,Default Value 0,Lifetime till the end of program
    static int value = 10;

    //4.Register Storage Class - Just liek auto but here the value is stored in register.Depreciated in C++17
    register int regVal = 3;

    //5.Mutable Storage Class- We can modify value through the const function
    A a;
    a.set(4);
    std::cout << a.y << "\n";

    //6.Thread_local. Each Thread  will get its own copy
    var += 5;
    std::thread t1([]() {
        var += 18;
        std::cout << "Var value in thread 1 = " << var << "\n"; //28
        });

    std::thread t2([]() {
        var += 10;
        std::cout << "Var value in thread 2 = " << var << "\n"; //20
        });


    t1.join();
    t2.join();

    std::cout << "\n In Main thread = " << var << "\n"; //15
}

