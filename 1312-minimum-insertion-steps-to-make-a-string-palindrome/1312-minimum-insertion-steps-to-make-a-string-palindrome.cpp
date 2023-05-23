class Solution {
public:
    
    //Tabulation Solution
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=n-2; i>=0; i--){
            for(int j=i+1; j<n; j++){
                if(s[i] == s[j])
                    dp[i][j] = dp[i+1][j-1];
                else{
                    dp[i][j] = min(dp[i+1][j],dp[i][j-1]);
                    dp[i][j]++;
                }
            }
        }
        return dp[0][n-1];
    }
    
    //Memoization Solution
//     int find(int i, int j, vector<vector<int>>&dp, string s){
//         if(i>=j)
//             return 0;
//         if(s[i] == s[j])
//             return find(i+1,j-1,dp,s);
//         if(dp[i][j]!= -1) 
//             return dp[i][j];
//         int l = 1 + find(i+1,j,dp,s);
//         int r = 1 + find(i,j-1,dp,s);
//         dp[i][j] = min(l,r);
//         return dp[i][j];
        
//     }
//     int minInsertions(string s) {
//         int n = s.size();
//         vector<vector<int>>dp(n,vector<int>(n,-1));
//         return find(0,n-1,dp,s);
//     }
};