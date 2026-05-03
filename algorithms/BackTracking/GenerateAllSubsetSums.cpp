#include <iostream>
#include <vector>
#include <algorithm>

void foo(std::vector<int> &vec,int &sum,int index)
{
    if(vec.size() == 0 || index >= vec.size())
    {
       
        std::cout << "Sum = " << sum << "\n";
        return;
    }

    //two choices
    //Pick
    sum+= vec[index];
    foo(vec,sum,index + 1);
    sum -= vec[index];
    foo(vec,sum,index + 1);//Dont Pick
}

int main()
{
    std::vector<int>vec{3,2};
    std::vector<int>temp;
    int sum = 0;
    foo(vec,sum,0);
}