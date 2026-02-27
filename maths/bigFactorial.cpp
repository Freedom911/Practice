#include <iostream>
#include <vector>
#include <algorithm>



std::vector<int> Prod(std::vector<int> elem,int x)
{
    std::reverse(elem.begin(),elem.end());
    int carry = 0;
    std::vector<int> res;

    for(int i = 0; i < elem.size(); i++)
    {
        int mul = (elem[i] * x) + carry;
        int prod = mul % 10;
        carry = mul / 10;
        res.push_back(prod);
    }

    while(carry)
    {
        res.push_back(carry % 10);
        carry = carry / 10;
    }

    std::reverse(res.begin(),res.end());

    return res;
}

void Fact(int elem)
{
    if(elem <= 1)
    {
        std::cout <<  elem << "\n";
    }


    std::vector<int> res{1};

    for(int i = 2; i <= elem; i++)
    {
        res = Prod(res,i);
    }
    
    std::cout << "\n Factorial of " << elem << " is = ";
    std::for_each(res.begin(),res.end(),[](const int &elem){
        std::cout << elem;
    });
    std::cout << "\n";
}

int main()
{
    int i = 0;
    std::cout << "\n Enter \n";
    std::cin >> i;
    Fact(i);



}