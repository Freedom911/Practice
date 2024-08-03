//Problem statement - we need to print first negative number in each window of size k
//if not present then print 0
#include <iostream>
#include <vector>
#include <queue>
#include <list>
void PrintFirstNegative(std::vector<int> v,int k)
{
    int j = 0;//end Position of window
    int n = v.size();
    int i = 0;//Start Position of window
    std::list<int>li;

    //here i and j are initially 0
    //we keep incrementing j. now when we hit the window size we just move the i
    //i is the startingPosition ofWindow

    while(j < n)
    {
        if(v[j] < 0)
        li.push_back(v[j]); //Push only negative

        if(j-i+1==k) //if window size hit
        {
            if(li.size() == 0) //means no negative
            {
                std::cout << 0 << ",";
            }
            else
            {
                std::cout << li.front() << ",";
            }
             //if before sliding we see the list front is equal to start position ofwindow
             //thhen we remove from our list. Why ?
             //because we are sliding the window to side and the v[i] element will be excluded
             //from window so we remove from our list as well because the element now wont be
             //in our answer
            if(li.front() == v[i])
            {
                li.pop_front();
            }

            i++;
        }

        j++;

    }

}

int main()
{
    PrintFirstNegative({12,-1,-7,8,-15,30,16,28},3);
}
