//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Space Optimization
    int knapSack(int w, int wt[], int val[], int n) 
    { 
       vector<int>prev(w+1,0), curr(w+1,0);
       for(int j=0; j<=w; j++){
           if(wt[0]<=j) prev[j] = val[0];
       }
       
       for(int i=1; i<n; i++){
           for(int j=0; j<=w; j++){
               int p=0;
               if(wt[i]<=j)
                    p = val[i] + prev[j-wt[i]];
                int np = prev[j];
                curr[j]=max(np,p);
           }
           prev = curr;
       }
       
       return prev[w];
    }
    
    //Tabulation Solution
    // int knapSack(int w, int wt[], int val[], int n) 
    // { 
    //   vector<vector<int>>dp(n,vector<int>(w+1,0));
    //   for(int j=0; j<=w; j++){
    //       if(wt[0]<=j) dp[0][j] = val[0];
    //   }
       
    //   for(int i=1; i<n; i++){
    //       for(int j=0; j<=w; j++){
    //           int p=0;
    //           if(wt[i]<=j)
    //                 p = val[i] + dp[i-1][j-wt[i]];
    //             int np = dp[i-1][j];
    //             dp[i][j]=max(np,p);
    //       }
    //   }
       
    //   return dp[n-1][w];
    // }
    
    // int find(int ind, int w, int wt[], vector<vector<int>>&dp, int val[]){
    //     if(ind==0){
    //         if(wt[0]<=w) return val[0];
    //         return 0;
    //     }
    //     if(dp[ind][w] !=-1) return dp[ind][w];
    //     int p=0;
    //     if(wt[ind]<=w){
    //         p = val[ind] + find(ind-1, w-wt[ind], wt, dp, val);
    //     }
    //     int np = find(ind-1, w, wt, dp, val);
    //     dp[ind][w] = max(p,np);
    //     return dp[ind][w];
    // }
    
    // int knapSack(int w, int wt[], int val[], int n) 
    // { 
    //     vector<vector<int>>dp(n,vector<int>(w+1,-1));
    //     int mx = 0;
    //   return find(n-1,w,wt,dp,val);
    // }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends