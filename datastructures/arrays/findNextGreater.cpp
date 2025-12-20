//Find No which is next greatest with the same digits
//eg - 1 2 3 4 5 -> 1 2 3 5 4
//Will start from right side to find the no whose left side is less
#include <iostream>
#include <vector>
#include <algorithm>

std::ostream &operator << (std::ostream &os,const std::vector<int> &elem)
{
    for(auto &e:elem)
        os << e << " ";
    return os;
}

//better logic below
void findNextGreater(std::vector<int> &no)
{

    std::cout << "\n INITIAL VECGOT " << no << "\n";

    //step 1 find a no whose left side is less
    int i = no.size() - 1;
    for(; i> 0; i--)
    {
        if(no[i - 1] < no [i])
            break;
    }

    int elem = no[i - 1];
    //Step 2 find the next greater no
    int nextGreator = no[i];
    int j = i,k = i;
    for(j = i + 1; j< no.size(); j++)
    {
        if(no[j] > elem && no[j] < nextGreator)
        {
            nextGreator = no[j];
            k = j;
        }
    }

    std::swap(no[k],no[i-1]);

    std::sort(no.begin() + i,no.end());

    std::cout << "\n AFTER VECGOT " << no << "\n";

}

//Once again
/**
 * We have given a number assumbe 2 1 8 7 6 5 our task is to find next greater
 * eg 2 3 1 we have to find next greater not the greatest
 * Next greater 3 1 2
 *
 * Solution - 
 * To find the next greater number we try to replace the first lower number(pivot) 
 * than left side to its just greater
 * Why because if we replace a smaller number with just greater from the right side we get a larger number
 * for eg in 2 3 1 we start traversing from right and we report the first element which is smaller than right
 * the smaller one will be the pivot
 * 2 is the pivot. Now 2st next greater is 3 we get this by traversing from right 
 * we swap both 
 * 3 2 1
 * Now we reverse the number from the right side of pivot to get the number in ascending . Currently they 
 * are in desc
 * 3 1 2 this is the actual number
 * So there are two things
 * 1. First first the number which is smaller than its right side and replace with larger umber from right side
 * as it will be swapped to get a larget number. not from left side as replacing from left side(larger) will result in
 * smaller number overall
 * 2. After swapping we get the right side of number in a same order which is descending. now to minimize the max number
 *    we make it in ascneding order to get smaller
 *
 */
void findNextGreaterBetter(std::vector<int> &vec)
{
    int n = vec.size();
    if(n == 0)
    {
        std::cout << "\n Array is Empty \n";
    }

    auto lambda = [](const int &elem) {
        std::cout << elem << ",";
    };
    std::cout << "\n Array Content = ";
    std::for_each(vec.begin(),vec.end(),lambda);

    int pivotIndex = -1;
    for(int i = n - 1; i >= 0; i--)
    {
        if (vec[i-1] < vec[i])
        {
            pivotIndex = i -1;
            break;
        }
    }

    if(pivotIndex == -1)
    {
        //means the element is already at largest
        std::cout << "\n Array already at largest \n";
        return;
    }

    //find next greater from left
    for(int i = n - 1; i >= 0; i--)
    {
        //break as soon as we get larger
        if(vec[i] > vec[pivotIndex])
        {
            std::swap(vec[i],vec[pivotIndex]);
            break;
        }
    }
    //Step 1  complete we have done the sawpping part 

    //Step 2 we reverse the index after pivot)
    std::reverse(vec.begin() + pivotIndex + 1,vec.end());

    std::cout << "\n Array Next Greater Content = ";
    std::for_each(vec.begin(),vec.end(),lambda);
    std::cout << "\n";

}

/**
 * Now given a number
 * 3 1 2 we want ot find next smaller number. so our logic will be same
 * Two things we have to do
 * 1. Swapping - for swapping we replace a larger number with just its smaller
 *   3 is swapped with just smaller 2
 *   2 1 3
 * 2. Now reverse to get number in desc
 * 2 3 1
 *
 *
 */
void findNextLesserBetter(std::vector<int> &vec)
{
    int n = vec.size();
    if(n == 0)
    {
        std::cout << "\n Array is Empty \n";
    }

    auto lambda = [](const int &elem) {
        std::cout << elem << ",";
    };
    std::cout << "\n Array Content = ";
    std::for_each(vec.begin(),vec.end(),lambda);

    int pivotIndex = -1;
    for(int i = n - 1; i >= 0; i--)
    {
        //Find Index whose right side is 
        if (vec[i-1] > vec[i])
        {
            pivotIndex = i -1;
            break;
        }
    }

    if(pivotIndex == -1)
    {
        //means the element is already at largest
        std::cout << "\n Array already at smallest \n";
        return;
    }

    //find next just smaller from left
    for(int i = n - 1; i >= 0; i--)
    {
        //break as soon as we get larger
        if(vec[i] < vec[pivotIndex])
        {
            std::swap(vec[i],vec[pivotIndex]);
            break;
        }
    }
    //Step 1  complete we have done the sawpping part 

    //Step 2 we reverse the index after pivot)
    std::reverse(vec.begin() + pivotIndex + 1,vec.end());

    std::cout << "\n Array Next Smaller Content = ";
    std::for_each(vec.begin(),vec.end(),lambda);
    std::cout << "\n";

}


int main()
{
    {

        std::vector<int> no {2,1,8,7,6,5};

        findNextGreater(no);
    }
    {

        std::vector<int> no {2,1,8,7,6,5};
        findNextGreaterBetter(no);
    }
    {

        std::vector<int> no {2,1,8,7,6,5};
        findNextLesserBetter(no);
    }
}

