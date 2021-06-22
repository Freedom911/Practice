// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
  

  
    int minOperation(int n)
    {
        //code here.
        #if 0
        if(n == 0)
        return 0;
        
        if(n % 2 != 0)
        return 1 + minOperation(n-1);
        else
        return 1 + std::min(minOperation(n-1),minOperation(n/2));
        #endif
        vector<int> t(n+1,0);
        t[0] = 0;
        t[1] = 1;
        
        for(int i = 2; i < n+ 1; i++)
        {
            if(i % 2 == 0)
            {
                t[i] = 1 + std::min(t[i-1],t[i/2]);
            }
            else
            t[i] = 1 + t[i-1];
        }
        
        
        return t[n];
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        Solution ob;
	        cout<<ob.minOperation(n)<<endl;
	    }
}  // } Driver Code Ends
