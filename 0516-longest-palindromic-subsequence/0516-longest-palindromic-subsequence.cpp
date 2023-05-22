class Solution {
public:
    //Tabulation Solution
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0; i<n; i++){
            dp[i][i] = 1;
        }
        for(int i=n-2; i>=0; i--){
            for(int j=i+1; j<n; j++){
                if(s[i]==s[j]) 
                    dp[i][j] = 2 + dp[i+1][j-1];
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
        return dp[0][n-1];
    }
    
    
    // Memoization Solution
    
//     int find(int i1,int i2,vector<vector<int>>&dp,string s){
//         if(i1 > i2)
//             return 0;
//         if(i1==i2) return 1;
//         if(s[i1]==s[i2])
//             return 2+find(i1+1,i2-1,dp,s);
//         if(dp[i1][i2]!=-1) return dp[i1][i2];
        
//         dp[i1][i2] = max(find(i1+1,i2,dp,s),find(i1,i2-1,dp,s));
//         return dp[i1][i2];
//     }
//     int longestPalindromeSubseq(string s) {
//         int n = s.size(), m = 0;
//         vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
//         return find(0,n-1,dp,s);
//     }
};