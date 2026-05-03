#include <iostream>
#include <vector>
#include <algorithm>

void foo(std::vector<int> &vec,std::vector<int> &temp,int index)
{
    if(vec.size() == 0 || index >= vec.size())
    {
        std::for_each(temp.begin(),temp.end(),[](const int &elem) {
            std::cout << elem << ",";
        });
        std::cout << "\n";
        return;
    }

    //two choices
    //Pick
    temp.push_back(vec[index]);
    foo(vec,temp,index + 1);
    temp.pop_back();
    foo(vec,temp,index + 1);//Dont Pick
}

int main()
{
    std::vector<int>vec{2,3,5};
    std::vector<int>temp;

    foo(vec,temp,0);
}