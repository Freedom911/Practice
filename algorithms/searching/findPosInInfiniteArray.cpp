//Given an infinite array or that is we dont know the end 
//then find the key
//here first we take start = 0 and end = 2*start + 1
//we compare key if it is lower or greater than end
//if greater than end then move start = end and make end = 2*start + 1
//if less then we find end index and then finally do bs
#include <iostream>
#include <vector>

int findEndIndex(std::vector<int> v,int key)
{
  int p = 0;
  int end = 0;
  while(key > v[end] && end < v.size()) // theoretically in infinite array we dont know the size
                                       //here we are only doing to avoid exception
  {
    p = end;
    end = 2*p + 1;
  }
  return end;
}

int findElement(std::vector<int> v,int key)
{
  int p = 0;
  int q = findEndIndex(v,key);
  int mid = -1;

  while(p <= q)
  {
     mid = p + (q-p)/2;
     if(v[mid] == key)
     {
       return mid;
     }

     if(v[mid] > key)
       q = mid - 1;
     else
       p = mid + 1;
  }

  return mid;
}


int main()
{
  std::cout << findElement({1,2,3,4,5,6,7,8,9,10,11,12},7) << "\n";
}
