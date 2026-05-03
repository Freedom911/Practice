/**
 * Median For Running Stream
 * So basically 
 * 
 * Find Median from Running Data Stream
Last Updated : 15 Oct, 2025
Given a data stream arr[] where integers are read sequentially, 
Determine the median of the elements encountered so far after each new integer is read.

There are two cases for median on the basis of data set size.

If the data set has an odd number then the middle one will be consider as median.
If the data set has an even number then there is
 no distinct middle value and the median will be the arithmetic mean of the two middle values.
Example:

Input:  arr[] = [5, 15, 1, 3, 2, 8]
Output: [5.00, 10.00, 5.00, 4.00, 3.00, 4.00] 

Solution 1 
After Every Insert Run Some Sorting ALgo and pick the nth number
Time Complexity O(n * nlogn). n for total elements and nlogn for sorting

Solution 2 - 
We use Heap. Much like Binary search on asnwer concept where we divided the array into 2 parts
 and pick the median from the max on left side and min on right side we will do same here

 We Take Two heaps which is max and min heap. the max heap is for left side and min for right
 as from left we only want max and from right we want min
 We try to make sure that the size of both heap is same which allows division in equal parts
 Time Complexity is O(n * log n). n for loop and log n for heap
*/
#include<iostream>
#include <queue>
#include <vector>

void print(std::vector<int> stream)
{
    if(stream.size() == 0)
    {
        return ;
    }

    std::priority_queue<int> leftMaxQ;
    std::priority_queue<int,std::vector<int>,std::greater<int>>rightMinQ;
    for(int i = 0; i < stream.size(); i++)
    {
        leftMaxQ.push(stream[i]);

        //Pick the max and dhaka marke push to right
        int elem = leftMaxQ.top();
        leftMaxQ.pop();
        rightMinQ.push(elem);

        //Check if size mismatch
        if(rightMinQ.size() > leftMaxQ.size())
        {
            int minE = rightMinQ.top();
            rightMinQ.pop();
            leftMaxQ.push(minE);
        }

         double median;
        
        if (leftMaxQ.size() != rightMinQ.size())
 
                  std::cout << leftMaxQ.top() << " ";
        else
            std::cout << (double)(leftMaxQ.top() + rightMinQ.top()) / 2 << " ";
        

    }
    std::cout << "\n";
}

int main()
{
    print({5, 15, 1, 3, 2, 8});
}
 
