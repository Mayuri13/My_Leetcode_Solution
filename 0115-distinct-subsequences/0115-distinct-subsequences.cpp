class Solution {
public:
    //Tabulation Solution
    int prime = 1e9+7;
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        dp[0][0] = 1;
        for(int i=1; i<=n; i++){
            for(int j=0; j<=m; j++){
                if(j==0)
                    dp[i][j] = 1;
                else{
                    if(s[i-1]==t[j-1])
                        dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%prime;
                    
                    else
                        dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }
    
    
    //Memoization Solution
//     int find(int i,int j,vector<vector<int>>&dp,string s,string t){
        
//         if(j<0)
//             return 1;
//         if(i<0)
//             return 0;
//         if(dp[i][j]!=-1) return dp[i][j];
//         if(s[i]==t[j]){
//             dp[i][j] = find(i-1,j-1,dp,s,t) + find(i-1,j,dp,s,t);
//             return dp[i][j];
//         }
        
//         dp[i][j] = find(i-1,j,dp,s,t);
//         return dp[i][j];
//         // return p + np1 + np2;
        
//     }
//     int numDistinct(string s, string t) {
//         int n = s.size(), m = t.size();
//         vector<vector<int>>dp(n,vector<int>(m,-1));
//         return find(n-1,m-1,dp,s,t);
//     }
};