//https://practice.geeksforgeeks.org/problems/maximum-money2855/1/?company[]=Amazon&company[]=Amazon&difficulty[]=-2&difficulty[]=-1&difficulty[]=0&page=1&query=company[]Amazondifficulty[]-2difficulty[]-1difficulty[]0page1company[]Amazon

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int maximizeMoney(int N , int K) {
        int count = 0;
        for(int i = 0; i < N; i+=2)
        {
            count += K;
        }
        
        return count;
        // code here
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;

        cin>>N>>K;

        Solution ob;
        cout << ob.maximizeMoney(N,K) << endl;
    }
    return 0;
}  // } Driver Code Ends
