#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

int main()
{
    std::vector<int> v {4,1,3,5,2,3,1,7};

    auto printLambda = []<typename T>(const T &elem){
        std::cout << elem << ",";
    };

    std::cout << "\n Lambda Contents = ";
    std::for_each(v.begin(),v.end(),printLambda);

    //sorting in descneindg order
    auto desLambda = [](const int &a, const int &b)
    {
       return a > b;
    };
    std::sort(v.begin(),v.end(),desLambda);

    std::cout << "\n Lambda Contents After Sorting = ";
    std::for_each(v.begin(),v.end(),printLambda);

    std::cout << "\n";

    //count 
    int count = std::count_if(v.begin(),v.end(),[](const int &a)
    {
        return a >= 2;
    });

    std::cout << "\n Elements greater than 2 are count = " << count << "\n";

    //Using accumulate
    int sum = accumulate(v.begin(),v.end(),0);//returns sum
    std::cout << "\n TOTAL SUM = " << sum << "\n";


    int product = accumulate(v.begin(),v.end(),1,[](const int &i,const int &j)
    {
        return i * j;
    });
    std::cout << "\n TOTAL Product = " << product << "\n";



}
