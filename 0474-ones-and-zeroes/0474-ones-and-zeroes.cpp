class Solution {
public:
    //Space Optimization
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();
        vector<vector<int>>curr(m+1,vector<int>(n+1,0)), prev(m+1,vector<int>(n+1,0));
        for(int i=sz-1; i>=0; i--){
            for(int j=0; j<=m; j++){
                for(int k=0; k<=n; k++){
                    int zero = 0, one = 0;
                    for(int x=0; x<strs[i].size(); x++){
                        if(strs[i][x]=='0') zero++;
                        else one++;
                    }
                    int pick = 0;
                    if(zero <=j && one<=k){
                        pick = 1 + prev[j-zero][k-one];
                    }
                    int notP = prev[j][k];
                    curr[j][k] = max(pick,notP);
                }
            }
            prev = curr;
        }
        
        return prev[m][n];
    }
    
    //Tabulation Solution
//     int findMaxForm(vector<string>& strs, int m, int n) {
//         int sz = strs.size();
//         vector<vector<vector<int>>>dp(sz+1,vector<vector<int>>(m+1,vector<int>(n+1,0)));
//         for(int i=sz-1; i>=0; i--){
//             for(int j=0; j<=m; j++){
//                 for(int k=0; k<=n; k++){
//                     int zero = 0, one = 0;
//                     for(int x=0; x<strs[i].size(); x++){
//                         if(strs[i][x]=='0') zero++;
//                         else one++;
//                     }
//                     int pick = 0;
//                     if(zero <=j && one<=k){
//                         pick = 1 + dp[i+1][j-zero][k-one];
//                     }
//                     int notP = dp[i+1][j][k];
//                     dp[i][j][k] = max(pick,notP);
//                 }
//             }
//         }
        
//         return dp[0][m][n];
//     }
    
    //Memoization Solution
    // int find(int i, vector<string>& strs, vector<vector<vector<int>>>&dp, int m, int n){
    //     if(i==strs.size())
    //         return 0;
    //     if(dp[i][m][n]!=-1)
    //         return dp[i][m][n];
    //     int zero = 0, one = 0;
    //     for(int j=0; j<strs[i].size(); j++){
    //         if(strs[i][j]=='0') zero++;
    //         else one++;
    //     }
    //     //picking a string whose number of ones's and zero's are less than or equal to n and m
    //     int pick = 0;
    //     if(zero<=m && one<=n){
    //         pick = 1 + find(i+1,strs,dp,m-zero,n-one);
    //     }
    //     int notP = find(i+1,strs,dp,m,n);
    //     dp[i][m][n] = max(pick,notP);
    //     return dp[i][m][n];
    // }
    // int findMaxForm(vector<string>& strs, int m, int n) {
    //     int sz = strs.size();
    //     vector<vector<vector<int>>>dp(sz+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
    //     return find(0,strs,dp,m,n);
    // }
    
};