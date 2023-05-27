class Solution {
public:
    //Space Optimization
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>prev(2,vector<int>(5,0)), curr(2,vector<int>(5,0));
        for(int i=n-1; i>=0; i--){
            for(int j=1; j>=0; j--){
                for(int k=3; k>=0; k--){
                    if(j){
                        curr[j][k]= max((-prices[i]+prev[0][k+1]),(0+prev[1][k]));
                    }
                    else{
                        curr[j][k]= max((prices[i]+prev[1][k+1]),(0+prev[0][k]));
                    }
                }
            }
            prev = curr;
        }
        return prev[1][0];
    }
    
    //Tabulation Solution
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(5,0)));
//         for(int i=n-1; i>=0; i--){
//             for(int j=1; j>=0; j--){
//                 for(int k=3; k>=0; k--){
//                     if(j){
//                         dp[i][j][k]= max((-prices[i]+dp[i+1][0][k+1]),(0+dp[i+1][1][k]));
//                     }
//                     else{
//                         dp[i][j][k]= max((prices[i]+dp[i+1][1][k+1]),(0+dp[i+1][0][k]));
//                     }
//                 }
//             }
//         }
//         return dp[0][1][0];
//     }
    
    
    //Recursive Solution
    // int profit(int i, int buy, int cnt, vector<int>&prices){
    //     if(i==prices.size())
    //         return 0;
    //     if(cnt==4)
    //         return 0;
    //     // if(dp[i][buy]!=-1)
    //     //     return dp[i][buy];
    //     int p = 0;
    //     if(buy){
    //         p = max((-prices[i]+profit(i+1,0,cnt+1,prices)),(0+profit(i+1,1,cnt,prices)));
    //     }
    //     //when we have already bought, so now we can either sale on ith day or not sale
    //     else{
    //         p = max((prices[i]+profit(i+1,1,cnt+1,prices)),(0+profit(i+1,0,cnt,prices)));
    //     }
    //     return p;
    // }
    // int maxProfit(vector<int>& prices) {
    //     return profit(0,1,0,prices);
    // }
};