class Solution {
public:
    int find(int i, vector<string>& strs, vector<vector<vector<int>>>&dp, int m, int n){
        if(i==strs.size())
            return 0;
        if(dp[i][m][n]!=-1)
            return dp[i][m][n];
        int zero = 0, one = 0;
        for(int j=0; j<strs[i].size(); j++){
            if(strs[i][j]=='0') zero++;
            else one++;
        }
        int pick = 0;
        if(zero<=m && one<=n){
            pick = 1 + find(i+1,strs,dp,m-zero,n-one);
        }
        int notP = find(i+1,strs,dp,m,n);
        dp[i][m][n] = max(pick,notP);
        return dp[i][m][n];
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();
        vector<vector<vector<int>>>dp(sz+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return find(0,strs,dp,m,n);
    }
};