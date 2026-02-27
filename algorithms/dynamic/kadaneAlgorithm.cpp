// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    ////doesnt handles negative case also.
    int maxSubarraySum(int arr[], int n){

      // Your code here
      //Using Brute Force We can go for O(N2)
      //Observation whenever we get negative sum we make it 0
      //and proceed. This is a dp problem moreover this dp problem is optimized
      //to have O(1) space complexity

      int currSum = 0;
      int maxSum = std::numeric_limits<int>::min();
      for(int i = 0; i < n; i++)
      {
	currSum = currSum + arr[i];

	if(currSum > maxSum)
	  maxSum = currSum;

	if(currSum < 0)
	  currSum = 0;
      }

      return maxSum;

    }
};
#if 0
//handles negative case also.
vector<int> maxSubarray(vector<int> arr) 
{
    int subSeqSum = 0;
    int subArr = 0;
    int maxTillNowSub = std::numeric_limits<int>::min();
    int maxElementSoFor = std::numeric_limits<int>::min();


    
    for(int i = 0; i < arr.size(); i++)
    {
        maxElementSoFor = std::max(arr[i],maxElementSoFor);
        if(arr[i] > 0)
        {
            subSeqSum += arr[i]; 
        }

        subArr += arr[i];

        if(subArr < 0)
        {
            subArr = 0;
        }

        maxTillNowSub = std::max(subArr,maxTillNowSub);
    }

    if(maxElementSoFor <= 0)
    {
        return{maxElementSoFor,maxElementSoFor};
    }

    return {maxTillNowSub,subSeqSum};
}
#endif

// { Driver Code Starts.

int main()
{
  int t,n;

  cin>>t; //input testcases
  while(t--) //while testcases exist
  {

    cin>>n; //input size of array

    int a[n];

    for(int i=0;i<n;i++)
      cin>>a[i]; //inputting elements of array

    Solution ob;

    cout << ob.maxSubarraySum(a, n) << endl;
  }
}
// } Driver Code Ends
