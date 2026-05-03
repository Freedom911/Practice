#include <iostream>
#include <vector>
#include <algorithm>

void foo(std::vector<int> &vec,std::vector<int> &temp,int index)
{
    //if(vec.size() == 0 || index >= vec.size())
    {
       
        std::for_each(temp.begin(),temp.end(),[](const int &elem){
            std::cout << elem << ",";
        });
        std::cout << "\n";
        //return;
    }

    //two choices
    //Pick
    for(int i = index; i < vec.size(); i++)
    {
        if(i > index && vec[i] == vec[i-1])
        {
            continue;
        }

         temp.push_back(vec[i]);
         foo(vec,temp,i + 1);
         temp.pop_back();
         //foo(vec,temp,i + 1);//Dont Pick

    }
   
}

int main()
{
    std::vector<int>vec{1,2,2};
    std::vector<int>temp;
    int sum = 0;
    foo(vec,temp,0);
}