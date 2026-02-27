#include <iostream>
#include <functional>
int add(int x,int y)
{
    return x + y;
}

int mult(int x, int y)
{
    return x * y;
}

void doOper(int x, int y,std::function<int(int,int)> foo )
{
    std::cout << foo(x,y) << "\n";
}

int main()
{
    
    doOper(3,4,add);//the function is automatically converted to pointer so same as below
    doOper(3,4,&mult);

}