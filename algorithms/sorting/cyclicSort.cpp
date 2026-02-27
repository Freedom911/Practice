/**
 * Cyclic Sort is unstable kind of sort
 * eg input = [2,6,4,3,1,5]
 * Solution is we start from oth index and try to make element at start index to be at correct Pos
 * How by continuously swapping
 * Swap 2 since 2 is not at correct index i.e 1
 * [6,2,4,3,1,5]
 * now keep at start until we dont have right element
 * 5,2,4,3,1,6
 * 1,2,4,3,5,6 and so on it sorts. but the range of element is 1 to N
 */
#include <iostream>
#include <vector>
void cyclicSort(std::vector<int> &elem)
{
    int start = 0;
    while(start < elem.size())
    {
        int correctIndex = elem[start] - 1;
        if(elem[start] != elem[correctIndex])
        {
            std::swap(elem[start],elem[correctIndex]);
        }
        else
        {
            start++;
        }
    }

    for(int i = 0; i < elem.size(); i++)
    {
        std::cout << elem[i] << ",";
    }
}

int main()
{
    std::vector<int> vec{2,6,4,3,1,5};
    cyclicSort(vec);
}