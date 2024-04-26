// ConnectRopesToMinimizeCostHeap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>

//Logic
//Given an array 1,2,3,4,5
//now we want to join all of them to minimize the cost
//1+2=3
//3 + 3=6
//6+4=10
//10+5=15
//3+6+10+15=34
//logic is greedy we take minimum  of two
//so first we pick 1 and 2 (3) then 3 and 3. then we pick out of 6,4,5 minimum two
//4 and 5 (9) then finally 9 plus 6 summing all we get 33 which is minimum
//so we use min heap and pick two and add sum on heap
//

int MinimumCostForConnectingHeap(const std::vector<int>& v)
{
    std::priority_queue<int, std::vector<int>, std::greater<int>> pr;
    for (auto& elem : v)
    {
        pr.push(elem);
    }
    int totalCost = 0;
    while (pr.empty() == false)
    {
        int elem1 = pr.top();
        pr.pop();

        if (pr.size() > 0)
        {
            int elem2 = pr.top();
            pr.pop();
            std::cout  << elem1 << " and " << elem2 << "\n";
            totalCost += elem1 + elem2;
            pr.push(elem1 + elem2);
        }
    }
    return totalCost;
}

int main()
{
    std::vector<int>v{ 1,2,3,4,5 };
    std::cout << "Minimum Cost = " << MinimumCostForConnectingHeap(v) << "\n";;
}


