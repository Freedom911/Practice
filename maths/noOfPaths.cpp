// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

 // } Driver Code Ends
long long  numberOfPaths(int i,int j)
{
    std::cout << "\n CALLED = ";
    if(i == 0 || j == 0)
    {
      return 1;
    }
    
    return numberOfPaths(i-1,j) + numberOfPaths(i,j-1);
}

// { Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>m>>n;
	    cout << numberOfPaths(m-1, n-1)<<endl;
	}
    return 0;
}  // } Driver Code Ends
