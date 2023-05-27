class Solution {
public:
    int profit(int i, int buy, vector<vector<int>>&dp, vector<int>&prices){
        if(i>=prices.size())
            return 0; //as no monwy can be returned.. days exhausted
        if(dp[i][buy]!=-1)
            return dp[i][buy];
        // int p = 0;
        if(buy){
            dp[i][buy] = max((-prices[i]+profit(i+1,0,dp,prices)),(0+profit(i+1,1,dp,prices)));
        }
        //when we have already bought, so now we can either sale on ith day or not sale
        else{
            dp[i][buy] = max((prices[i]+profit(i+2,1,dp,prices)),(0+profit(i+1,0,dp,prices)));
        }
        return dp[i][buy];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return profit(0,1,dp,prices);
    }
};