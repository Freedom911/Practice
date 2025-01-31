//The following example shows the usage of lambda function in real world
//0. Problem - Given a vector of int print all elements
//1. Problem - Given a vector sum all its elmeent who are less than 5 and return sum
//2. Problem - Given a vector multiply all its element less than 5 1,2,3,4 = 1 * 2 * 3 * 4 and return product
//3. Problem - Given vector of strings. Remove strings whose length is even 
//4. Template lambda for printing
//5. Problem - Given a vector of int. Update each entry of vector by random number
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>

int main()
{
    std::vector<int> v{1,3,6,100,2,1,2,4};
    
    //0. Problem - Given a vector of string print all elements
    //Empty enclousre means no variable used in lambda from outside
    auto lam0 = [](const int &elem) {
        std::cout << elem << " ";
    };

    std::for_each(v.begin(),v.end(),lam0);


    //1. Problem - Given a vector sum all its elmeent who are less than 5 and return sum

    int SumCount = 0;
    //Now this lambda will be called every time for the vector so we need to pass SumCount with ref
    auto lam1 = [&SumCount](const int &elem){
      if(elem <= 5)
      {
        SumCount += elem;
      }
    };
    std::for_each(v.begin(),v.end(),lam1);
    std::cout << "\n Sum of elements who are less than 5 = " << SumCount << "\n";

    
    //2. Problem - Given a vector multiply all its element less than 5 1,2,3,4 = 1 * 2 * 3 * 4 and return product
    int Product = 1;
    auto lam2 = [&Product](const int &elem){
        if(elem <= 5 )
        {
            Product *= elem;
        }
    };
    std::for_each(v.begin(),v.end(),lam2);
    std::cout << "\n Product of elements who are less than 5 = " << Product << "\n";

    //3. Problem - Given vector of strings. Remove strings whose length is even 
    std::vector<std::string> vecStr{"hello","yellow","mail","tell","long","habbit","generator","rockstar"};

    //we will use cpp remove if(moves value to right) and erase finally removes
    auto lam3 = [](const std::string &str){
        return str.length() % 2 == 0;
    };
    vecStr.erase(std::remove_if(vecStr.begin(),vecStr.end(),lam3),vecStr.end());
    
    //4. template Lambda
    auto lamTempPrint = []<typename T>(const T &elem) {
        std::cout << elem << " ";
    };
    std::cout << "\n Removing Even Length String \n";
    std::for_each(vecStr.begin(),vecStr.end(),lamTempPrint);
    std::cout << "\n";


    //5. Problem - Given a vector of int. Update each entry of vector by random number
    std::vector<int> vec{1,2,3,4,5,6};
    std::random_device dev;
    std::mt19937 rng(dev());//mersenery twiseter
    std::uniform_int_distribution<std::mt19937::result_type> dist(1,30);

    std::cout << "Initially = ";
    std::for_each(vec.begin(),vec.end(),lamTempPrint);
    

    //passing num by reference as for each doesnt update value
    //so when modified inside the lambda changes are refelected
    auto lam4 = [&dist,&rng](int &num){
        num = num + dist(rng);//genereates random Number
    };
    std::for_each(vec.begin(),vec.end(),lam4);

    std::cout << "\nFinally = ";
    std::for_each(vec.begin(),vec.end(),lamTempPrint);
    std::cout << "\n";


}
