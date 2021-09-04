#include <iostream>
class Solution
{
    public:
    int peakElement(int arr[], int n)
    {
      if(n == 2 && (arr[0] > arr[1] || arr[1] > arr[0]))
      return 1;
        
      for(int i = 1; i < n - 1; i++)
      {
          if(arr[i] > arr[i -1] && arr[i] > arr[i+1]  )
          return 1;
      }
      
      return 0;
    }
};
int main()
{
  Solution s;
  int arr[] = {6 ,1 ,15, 19 ,9, 13 ,12 ,6 ,7 ,2 ,10 ,4 ,1 ,14 ,11 ,14 ,14 ,13};
  std::cout << "\n " << s.peakElement(arr,18);
}
