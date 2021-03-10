// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
    string MaxZero(string a[],int n)
    {
      string str;
      int count = std::numeric_limits<int>::min();
      for(int i = 0; i < n; i++)
      {
	string s = a[i];
	int totalZero = 0;
	for(char ch:s)
	{
	  if(ch == '0')
	    totalZero ++;
	}
	if(totalZero > count)
	  count = totalZero;
      }
      ostringstream out;
      out << count;
      return out.str();     
    }

};


// { Driver Code Starts.

int main() 
{

  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    string a[n];
    for(int i = 0;i<n;i++){
      cin >> a[i];
    }




    Solution ob;
    cout << ob.MaxZero(a,n) ;


    cout << "\n";

  }
  return 0;
}  // } Driver Code Ends
