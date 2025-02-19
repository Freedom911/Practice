#include <iostream>
struct abc
{
    int a : 9;
};

struct bcd
{
   int b : 33;
};

struct cde
{
   int c : 60;
};
int main()
{
   std::cout << sizeof(abc) << "\n"; //4 as expected 9 means 2.something bytes which we round off to 4
   std::cout << sizeof(bcd) << "\n"; //8 as 33 means greater than 4 bytes
   std::cout << sizeof(bcd) << "\n"; //8 
}
