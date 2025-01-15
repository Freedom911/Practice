//Std function is a wrapper which can store and call any function
#include <iostream>
#include <functional>

int add(const int &x,const int &y)
{
    return x + y;
}


int mul(const int &x,const int &y)
{
    return x * y;
}

int sub(const int &x,const int &y)
{
    return x - y;
}

class Foo
{
  public:
  int adder(int a,int b)
  {
      return a + b;
  }
};

int main()
{
    //1. Normal Usage
    std::function<int(const int&,const int&)> calFun = (add);

    std::cout << calFun(3,4) << "\n";
    //32 size will come
    std::cout << "SIZE OF FUNCTION = " << sizeof(calFun) << "\n";

    
    //2. Wow we can store  in Functions
    std::vector<std::function<int(const int&,const int&)>>AllFunctions;
    AllFunctions.push_back(add);
    AllFunctions.push_back(sub);
    AllFunctions.push_back(mul);

    for(int i = 0; i < AllFunctions.size(); i++)
    {
        std::cout << AllFunctions[i](6,3) << "\n";
    }


    //3.incase of overloading we need to static cast 
    //std::function<int(const int&,const int&)> calFun = static_cast<int(*)(const int&,const int&)>(add);

    //4.Class Function
    std::function<int(Foo,const int&,const int&)> calFunAdder = &Foo::adder;
    Foo c;
    std::cout << "\n Class Function = " << calFunAdder(c,3,4) << "\n";
   

}
