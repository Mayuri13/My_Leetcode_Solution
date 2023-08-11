class Solution {
public:
    //Space Optimization
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int>prev(amount+1,0), curr(amount+1,0);
        for(int j=0; j<=amount; j++){
            if(j%coins[0]==0) 
                prev[j]=1;
        }
        for(int i=1; i<n; i++){
            for(int j=0; j<=amount; j++){
                int p = 0;
                if(coins[i]<=j)
                    p = curr[j-coins[i]];
                int np = prev[j];
                curr[j]=np+p;
            }
            prev = curr;
        }
        return prev[amount];
    }

    //Tabulation Solution
    // int change(int amount, vector<int>& coins) {
    //     int n = coins.size();
    //     vector<vector<int>>dp(n, vector<int>(amount+1,0));
    //     for(int j=0; j<=amount; j++){
    //         if(j%coins[0]==0) 
    //             dp[0][j]=1;
    //     }
    //     for(int i=1; i<n; i++){
    //         for(int j=0; j<=amount; j++){
    //             int p = 0;
    //             if(coins[i]<=j)
    //                 p = dp[i][j-coins[i]];
    //             int np = dp[i-1][j];
    //             dp[i][j]=np+p;
    //         }
    //     }
    //     return dp[n-1][amount];
    // }

    //Memoization Solution
    // int find(int ind, vector<int>&coins, vector<vector<int>>&dp, int amt){
    //     if(amt==0) return 1;
    //     if(ind==0){
    //         //as we need only count of combinations so answer should be 1 or 0
    //         return (amt%coins[0]==0);
    //     }
    //     if(dp[ind][amt]!=-1) return dp[ind][amt];
    //     int p = 0;
    //     if(coins[ind]<=amt)
    //         p = find(ind,coins,dp,amt-coins[ind]);
    //     int np = find(ind-1,coins,dp,amt);
    //     dp[ind][amt] = p + np;
    //     return dp[ind][amt];
    // }

    // int change(int amount, vector<int>& coins) {
    //     int n = coins.size();
    //     vector<vector<int>>dp(n, vector<int>(amount+1,-1));
    //     return find(n-1, coins, dp, amount);
    // }
};