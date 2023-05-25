class Solution {
public:
    //Tabulation Solution
    int minDistance(string w1, string w2) {
        int n = w1.size(), m = w2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int j=1; j<=m; j++){
            dp[0][j] = j;
        }
        for(int i=1; i<=n; i++){
            dp[i][0] = i;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(w1[i-1]==w2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(min(1+dp[i-1][j],1+dp[i-1][j-1]),1+dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
    
    //Memoization Solution
//     int find(int i, int j, vector<vector<int>>&dp, string w1, string w2){
        
//         if(i<0) return j+1;
//         if(j<0) return i+1;
//         if(dp[i][j] != -1) return dp[i][j];
//         if(w1[i]==w2[j]){
//             dp[i][j] = find(i-1,j-1,dp,w1,w2);
//             return dp[i][j];
//         }
//         dp[i][j] = min(min(1+find(i-1,j,dp,w1,w2),1+find(i-1,j-1,dp,w1,w2)),1+find(i,j-1,dp,w1,w2));
//         return dp[i][j];
//     }
    
//     int minDistance(string w1, string w2) {
//         int n = w1.size(), m = w2.size();
//         vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
//         return find(n-1,m-1,dp,w1,w2);
//     }
};