// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#include <string>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    string decodedString(string s){
      // code here
      string s1,torep;
      stack<char> st;
      for(int i = 0; i < s.length(); i++)
      {
	char ch = s[i];
	if(ch != ']')
	{
	  if(ch == '[' && !isdigit(s[i+1]))
	  {
	    torep +=s[i+1];
	  }

	  st.push(ch);
	}
	else
	{
	  while(!st.empty())
	  {
	    if(st.top() == '[')
	    {
	      st.pop();
	      if(!st.empty())
	      {
		char t = st.top();

		if(isdigit(t))
		{
		  st.pop();
		  int repeat = t - '0';

		  std::string s2;
		  for(int i = 0; i < repeat-1; i++)
		  {
		    s2 += torep;
		  }
		  std::cout << "WREPEAT = " << repeat << " HEY = " << s2 << "\n";
		  s1 = s1 + s2;
		  std::cout << "REPEAT = " << repeat << " HEY = " << s1 << "\n";
		  torep = ""; 

		}
		else
		{
		  s1 = t + s1;
		}
	      }
	      break;
	    }
	    s1 = st.top() + s1;
	    st.pop();

	  }
	}
      }
      return s1;
    }
};

// { Driver Code Starts.

int main(){
  int t;
  cin>>t;
  while(t--){
    string s;
    cin>>s;

    Solution ob;
    cout<<ob.decodedString(s)<<"\n";
  }
  return 0;
}  // } Driver Code Ends
