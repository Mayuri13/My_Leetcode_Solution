class Solution {
public:
    //Tabulation Solution
    int longestCommonSubsequence(string t1, string t2) {
        int n = t1.size(), m = t2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        for(int i=0; i<=m; i++){
            dp[0][i]=0;
        }
        for(int i=0; i<=n; i++){
            dp[i][0]=0;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(t1[i-1]==t2[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
    
    
    //Memoization Solution
    
    // int find(int i1,int i2,vector<vector<int>>&dp,string t1,string t2){
    //     if(i1<0 || i2<0)
    //         return 0;
    //     if(dp[i1][i2]!=-1) return dp[i1][i2];
    //     if(t1[i1]==t2[i2])
    //         return 1+find(i1-1,i2-1,dp,t1,t2);
    //     dp[i1][i2] = max(find(i1-1,i2,dp,t1,t2),find(i1,i2-1,dp,t1,t2));
    //     return dp[i1][i2];
    // }
    // int longestCommonSubsequence(string t1, string t2) {
    //     int n = t1.size(), m = t2.size();
    //     vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    //     return find(n-1,m-1,dp,t1,t2);
    // }
};