// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
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
