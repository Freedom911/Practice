// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

stack<int> _push(int arr[],int n);

void _getMinAtPop(stack<int>s);

 // } Driver Code Ends
//User function Template for C++

/* inserts elements of the array into 
   stack and return the stack
*/
stack<int> globalMin;
stack<int> _push(int arr[],int n)
{
    stack<int>elements;
    globalMin = elements;
    
    for(int i = 0; i <n;i++)
    {
        elements.push(arr[i]);
        if(globalMin.empty())
        {
            globalMin.push(arr[i]);
        }
        else
        {
            int topElement = globalMin.top();
            if(topElement > arr[i])
            {
	      globalMin.push(arr[i]);
	    }
        }
    }
    
    return elements;
   // your code here
}

/* print minimum element of the stack each time
   after popping
*/
void _getMinAtPop(stack<int>s)
{
    // your code here
    while(!s.empty())
    {
        if(globalMin.empty())
        break;
	 
        if(!globalMin.empty())
        std::cout << globalMin.top() << " ";

        if(s.top() == globalMin.top())
        {
            globalMin.pop();
        }
        
        s.pop();
    }
}

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    stack<int>mys=_push(arr,n);
	    _getMinAtPop(mys);
	    
	    
	    
	}
	return 0;
}

  // } Driver Code Ends
