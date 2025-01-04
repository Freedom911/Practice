#include <iostream>

//pass by Values
constexpr float foo(float x,int n)
{
    float y = x * n;
    return y;
}

//pass by reference
constexpr float foo(float &x,int &n)
{
    x = x * n;
    return x;
}

//Compile time computiation of array length
template<typename T,int N>
constexpr int length(const T(&)[N])
{
    return N;
}


//Recursive ConstexprFunction
constexpr long long unsigned int fib(long long unsigned int n)
{
    return n <= 1 ? 1: fib(n-1) + fib(n-2);
}


long long unsigned int fibFoo(long long unsigned int n)
{
    return n <= 1 ? 1: fibFoo(n-1) + fibFoo(n-2);
}


class Foo
{
   public:
   constexpr explicit Foo(int i) : m_i(i){}
   constexpr int GetValue() const
   {
       return m_i;
   }

   private:
   int m_i;
};


int main()
{

    constexpr Foo foos(5);


    //Compile time
    constexpr float x = foo(2,3);
    constexpr int val = foos.GetValue();

    int nums[] { 1,2,3,4,5};
    constexpr int le = length(nums);


    //Run Time as the value doesnt need to ne known at compile time
    std::cout << foos.GetValue() << "\n";
    
    //fib(36);//this will take huge comppilation time but execution would be super fast breakpoint will also wont hit

     //long long int j = fib(36); //but this will be runtime breakpoint would be hit
     //const long lont int k = fib(36);// run time
     //constexpr long long int j = fib(36); //but this will be compile time and breakpoint wont be hit

    return -1;


}
