//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minmoves(vector<vector<bool>>& G, vector<bool>& visited, int u, int &n, vector<int>& dp){
        if(u == n){
            return 0;
        }
        else if(dp[u] != -1){
            return dp[u];
        }
        else{
            int ans = n;
            for(int v = u; v < n; v++){
                if(!visited[v] && G[u][v]){
                    visited[v] = true;
                    ans = min(ans, minmoves(G, visited, v + 1, n, dp) + 1);
                    visited[v] = false;
                }
            }
            return dp[u] = ans;
        }
    }
    int palindromicPartition(string str)
    {
        // code here
        int n = str.size();
        vector<vector<bool>>G(n,vector<bool>(n,false));
        // First Check For Odd Palindromes
        for(int i = 0; i < n; i++){
            int s = i,e = i;
            while(s >= 0 && e < n && str[s] == str[e]){
                G[s][e] = true;
                s--, e++;
            }
        }
        
        // Check For Even Palindromes
        for(int i = 0; i < n; i++){
            int s = i-1, e = i;
            while(s >= 0 && e < n && str[s] == str[e]){
                G[s][e] = true;
                s--, e++;
            }
        }
        
        vector<bool>visited(n, false); vector<int>dp(n,-1);
        int ans = minmoves(G, visited, 0, n, dp);
        return ans - 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends