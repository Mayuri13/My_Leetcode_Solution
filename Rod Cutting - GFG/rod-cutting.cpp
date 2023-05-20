//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int find(int i, int r, vector<vector<int>>&dp, int price[]){
        if(r==0) return 0;
        if(i==0){
            if(r%(i+1)==0) 
                return (r/(i+1)*price[i]);
            else 
                return 0;
        }
        if(dp[i][r]!=-1) return dp[i][r];
        int p=0;
        if((i+1)<=r)
            p = price[i] + find(i,r-(i+1),dp,price);
        int np = find(i-1,r,dp,price);
        dp[i][r] = max(p,np);
        return dp[i][r];
    }
    int cutRod(int price[], int n) {
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return find(n-1, n, dp, price);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends