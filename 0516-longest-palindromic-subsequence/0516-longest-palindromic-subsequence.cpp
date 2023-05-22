class Solution {
public:
    //Tabulation Solution
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<int>prev(n,0), curr(n,0);
        prev[n-1] = 1;
        for(int i=n-2; i>=0; i--){
            for(int j=i; j<n; j++){
                if(i==j) 
                    curr[j] = 1;
                else{
                    if(s[i]==s[j]) 
                        curr[j] = 2 + prev[j-1];
                    else
                        curr[j] = max(prev[j], curr[j-1]);
                }
            }
            prev = curr;
        }
        return prev[n-1];
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