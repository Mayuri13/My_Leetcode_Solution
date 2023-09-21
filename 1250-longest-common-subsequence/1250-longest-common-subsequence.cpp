class Solution {
public:
    // int find(int i, int j, string text1, string text2, vector<vector<int>>&dp){
    //     if(i < 0 || j < 0) return 0;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     if(text1[i] == text2[j])
    //         dp[i][j] = 1 + find(i-1, j-1, text1, text2, dp);
    //     else
    //         dp[i][j]  = max(find(i-1, j, text1, text2, dp), find(i, j-1, text1, text2, dp));
    //     return dp[i][j];
    // }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<int>prev(m+1,0), curr(m+1,0);

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(text1[i-1] == text2[j-1])
                    curr[j] = 1 + prev[j-1];
                else
                    curr[j]  = max(prev[j], curr[j-1]);
            }
            prev = curr;
        }

        return curr[m];
    }
};