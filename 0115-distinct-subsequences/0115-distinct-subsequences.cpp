class Solution {
public:
    int find(int i,int j,vector<vector<int>>&dp,string s,string t){
        if(j<0)
            return 1;
        if(i<0)
            return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]){
            dp[i][j] = find(i-1,j-1,dp,s,t) + find(i-1,j,dp,s,t);
            return dp[i][j];
        }
        
        dp[i][j] = find(i-1,j,dp,s,t);
        return dp[i][j];
        // return p + np1 + np2;
        
    }
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return find(n-1,m-1,dp,s,t);
    }
};