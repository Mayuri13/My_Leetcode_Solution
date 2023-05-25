class Solution {
public:
    int find(int i, int j, vector<vector<int>>&dp, string w1, string w2){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j] != -1) return dp[i][j];
        if(w1[i]==w2[j]){
            dp[i][j] = find(i-1,j-1,dp,w1,w2);
            return dp[i][j];
        }
        dp[i][j] = min(min(1+find(i-1,j,dp,w1,w2),1+find(i-1,j-1,dp,w1,w2)),1+find(i,j-1,dp,w1,w2));
        return dp[i][j];
    }
    
    int minDistance(string w1, string w2) {
        int n = w1.size(), m = w2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return find(n-1,m-1,dp,w1,w2);
    }
};