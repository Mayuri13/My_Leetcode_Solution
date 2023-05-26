class Solution {
public:
    //Tabulation Solution
    bool isAllStars(string & S1, int i) {

  // S1 is taken in 1-based indexing
      for (int j = 1; j <= i; j++) {
        if (S1[j - 1] != '*')
          return false;
      }
      return true;
    }
    
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        dp[0][0] = 1;
        
        for(int j=1; j<=m; j++){
            if(isAllStars(p,j))
                dp[0][j] = 1;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if((s[i-1]==p[j-1]) || (p[j-1]=='?'))
                    dp[i][j] = dp[i-1][j-1];
                else if(p[j-1]=='*')
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
        }
        return dp[n][m];
    }
    
    
    //Memoization Solution
//     bool find(int i, int j, vector<vector<int>>&dp, string s, string p){
//         if(i<0 && j<0) return true;
//         if(j<0 && i>=0) return false;
//         if(i<0 && j>=0){
//             for(int ii=0; ii<=j; ii++){
//                 if(p[ii]!='*')
//                     return false;
//             }
//             return true;
//         }
//         if(dp[i][j]!=-1) return dp[i][j];
//         if((s[i]==p[j]) || (p[j]=='?')){
//             dp[i][j] = find(i-1,j-1,dp,s,p);
//             return dp[i][j];
//         }
//         if(p[j]=='*'){
//             dp[i][j] = find(i-1,j,dp,s,p) || find(i,j-1,dp,s,p);
//             return dp[i][j];
//         } 
//         return false;
//     }
    
//     bool isMatch(string s, string p) {
//         int n = s.size(), m = p.size();
//         vector<vector<int>>dp(n,vector<int>(m,-1));
//         return find(n-1,m-1,dp,s,p);
//         // return true;
//     }
};