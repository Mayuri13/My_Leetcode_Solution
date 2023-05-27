class Solution {
public:
    //Tabulation Solution
    int maxProfit(vector<int>& prices, int fee){
        int n = prices.size();
        vector<int>prev(2,0), curr(2,0);
        
        for(int i=n-1; i>=0; i--){
            for(int j=1; j>=0; j--){
                if(j){
                    curr[j]= max((-prices[i]+prev[0]),(0+prev[1]));
                }
                else{
                    curr[j]= max((prices[i]-fee+prev[1]),(0+prev[0]));
                }
            }
            prev = curr;
        }
        
        return prev[1];
    }
     //Memoization Solution
    // int profit(int i, int buy, vector<vector<int>>&dp, int fee, vector<int>&prices){
    //     if(i>=prices.size())
    //         return 0; //as no monwy can be returned.. days exhausted
    //     if(dp[i][buy]!=-1)
    //         return dp[i][buy];
    //     // int p = 0;
    //     if(buy){
    //         dp[i][buy] = max((-prices[i]+profit(i+1,0,dp,fee,prices)),(0+profit(i+1,1,dp,fee,prices)));
    //     }
    //     //when we have already bought, so now we can either sale on ith day or not sale
    //     else{
    //         dp[i][buy] = max((prices[i]-fee+profit(i+1,1,dp,fee,prices)),(0+profit(i+1,0,dp,fee,prices)));
    //     }
    //     return dp[i][buy];
    // }
    // int maxProfit(vector<int>& prices, int fee) {
    //     int n = prices.size();
    //     vector<vector<int>>dp(n,vector<int>(2,-1));
    //     return profit(0,1,dp,fee,prices);
    // }
};