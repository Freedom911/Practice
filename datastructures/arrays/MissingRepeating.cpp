/**
 *
 * Problem Connected to Logic a + b * n where a is original value and b is new
 * Continuation to frequency 
 *
 * Given an unsorted array arr[] of size n, 
 * containing elements from the range 1 to n, 
 * it is known that one number in this range is missing, 
 * and another number occurs twice in the array, find both the duplicate number and the missing number.

Examples:

    Input: arr[] = [3, 1, 3]
    Output: [3, 2]
    Explanation: 3 is occurs twice and 2 is missing.

    Input: arr[] = [4, 3, 6, 2, 1, 1]
    Output: [1, 5]
    Explanation: 1 is occurs twice and 5 is missing.
 *
 *
 * Solution 1 -
 * We use Unordered set and we check if number is repeated. then we loop through the unordered set
 * to find missing number
 * Time and Space O(N)
 *
 * Solution 2 - using count Array.
 * We keep a new array that keeps track of the occurance of numer
 * eg arr = [3,1,3]
 * count = [0,0,0] initially
 * then we decrement arr as the array is 0 based.
 * arr = [2,0,2]
 * so basically we increase the count by 1 at the index mentioned in arr
 * count=[1,0,2]
 * To report missing we check who is 0 and for repeating count = 2
 * Time and Space O(N)
 *
 * Solution 3 - Keeping Count in the original array
 * we use the formula a + b *n where a is original and b will be 1 and n is no of elements
 * to get original value we % and to get b which is occurance we divide
 * Time O(n) space O(1)
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

void PrintRepeatingMissing(std::vector<int> &v)
{
    size_t n = v.size();
    if(n == 0)
    {
        std::cout << "\n Array is empty \n";
        return;
    }

    for(int i = 0; i < n; i++)
    {
        v[i]--;//to get 0 based value
    }

    for(int i = 0; i < n; i++)
    {
        int a = v[i] % n;
        v[a] += 1 * n;
    }
    
    for(int i = 0; i < n; i++)
    {
        int occ = v[i] / n;
        if(occ == 0)
        {
            std::cout << "\n ELEMENT MISSING = " << i + 1 << "\n";
        }
        else if(occ == 2)
        {
            std::cout << "\n Element Repeating = " << i + 1 << "\n";
        }

    }

    //get back original array
    for(int i = 0; i < n; i++)
    {
        int orig = v[i] % n;
        v[i] = orig;
        v[i]++;
    }

    std::cout << "\n ORIGINALL ARRAY = " ;
    auto lambda = [](const int &elem){
        std::cout << elem << ",";
    };
    std::for_each(v.begin(),v.end(),lambda);




}

int main()
{
    //std::vector<int> arr {3,1,3};
    std::vector<int> arr {4, 3, 6, 2, 1, 1};
    PrintRepeatingMissing(arr);
}
