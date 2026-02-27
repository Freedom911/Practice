#include <iostream>
#include <bitset>
#include <vector>
/**
 * Solution 1
 
// 10^9 + 1 to account for 0-indexing if needed
std::bitset<1000000001> track; 

void solve(std::vector<int> elem) 
{
    for(int i = 0; i < elem.size(); i++)
    {
        if(elem[i] > 0)
        track.set(elem[i]);
    }

    for(auto i = 1; i < 1000000001; i++)
    {
        if(track.test(i) == false)
        {
            std::cout << "Smallest Missing = " << i << "\n";
            return;
        }
    }

}
*/
//We apply cyclic sort.
//So we can say that for a vector the range of missing number can be from 1 to N and if not found then N + 1
//eg [3,5,-1,1] then we can have 1 to 4 missing number or n+1 
//in case [1,2,3,4] then missing no is 5

int findSmallestMissingPositive(std::vector<int> orderNumbers) 
{
    if(orderNumbers.size() == 0)
    {
        return 1;
    }

    size_t  N = orderNumbers.size();
    //Cyclic Sort Applying
    int start{0};
    while(start < N)
    {
        if(orderNumbers[start] <= 0 || orderNumbers[start] > N)
        {
            start++;
            continue;
        }
        int correctIndex = orderNumbers[start] - 1;
        if(orderNumbers[start] != orderNumbers[correctIndex])
        {
            std::swap(orderNumbers[start],orderNumbers[correctIndex]);
        }
        else
        {
            start++;
        }
    }

    //now validation part
    start = 0;
    for(start = 0; start < N; start++)
    {
        if(orderNumbers[start] != start + 1)
        {
            return start + 1;
        } 
    }

    return N + 1;

}



int main()
{
    std::cout << "\n MISSING = " << findSmallestMissingPositive({1,2,3,4});
}