// { Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;
struct node{
	int salary;
	string name;
};

 // } Driver Code Ends
/* struct node{          // node structure
     int salary;
     string name;
 };
*/



class Solution{

	public:
	

	
	#if 1
	void merge(node arr[],int p,int q,int r)
	{
	    int l = q - p + 1;
	    int m = r - q;
	    
	    node L[l];
	    node R[m];
	    for(int i = 0; i < l; i++)
	    L[i] = arr[i + p];
	    
	    for(int i = 0; i < m; i++)
	    R[i] = arr[i + q + 1];
	    
	    int i = 0,j = 0,k = p;

	    while(i < l && j < m)
	    {
            
	        if(L[i].salary < R[j].salary)
	        {
	            arr[k] = L[i];
	      
	            i++;
	        }
	        else if (L[i].salary > R[j].salary)
	        {
	            arr[k] = R[j];
	            
	            j++;
	        }
	        else
	        {
	            if(L[i].name < R[j].name)
	            {
	               arr[k] = L[i];
	               
	               i++; 
	            }
	            else
	            {
	               arr[k] = R[j];
	               
	               j++;
	            }
	        }
	              k++;
	    }
	    
	    while(i < l)
	    {
	        arr[k] = L[i];
	        k++;
	        i++;
	    }
	    
	    	    
	    while(j < m)
	    {
           arr[k] = R[j];
	       k++;
	       j++;
	    }
	}
	#endif
	
	void mergesort(node arr[],int p,int r)
	{
	    if(p < r)
	    {
	        int q = (p +r)/2;
	        
	        mergesort(arr,p,q);
	        mergesort(arr,q+1,r);
	        merge(arr,p,q,r);
	    }
	}
	
	void sortRecords(node arr[], int n)
	{
	    mergesort(arr,0,n-1);
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
        cin>>n;
        node arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i].name>>arr[i].salary;
        

        Solution ob;
        ob.sortRecords(arr, n);
        for(int i=0;i<n;i++)
        	cout<<arr[i].name<<" "<<arr[i].salary<<" ";
	    cout << "\n";
	     
    }
    return 0;
}






  // } Driver Code Ends
