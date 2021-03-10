// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
  public:



    string modify (string s)
    {
      // your code here


      string t;
      bool isUpper = false;
      for(int i = 0; i < s.size(); i++)
      {

	if(i == 0)
	{
	  isUpper = isupper(s[i]);
	}

	int value = s[i];
	if(isUpper)
	{

	  if(value >= (int)'A' && value <= (int)'Z')
	  {

	  }
	  else
	  {
	    s[i] = s[i] - (int)('a'-'A');
	  }
	}
	else
	{
	  if(value >= (int)'A' && value <= (int)'Z')
	  {
	    s[i] = s[i] + (int)('a'-'A');
	  }
	  else
	  {

	  }
	}
      }

      return s;
    }
};

// { Driver Code Starts.
int main()
{
  int t; cin >> t;
  while (t--)
  {
    string s; cin >> s;
    Solution ob;
    cout << ob.modify (s) << endl;
  }
}  // } Driver Code Ends
