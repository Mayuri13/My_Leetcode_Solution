class Solution {
public:
    // //Tabulation Solution
    // int lengthOfLIS(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<vector<int>>dp(n+1,vector<int>(n,0));
    //     for(int i=n-1; i>=0; i--){
    //         for(int j=n-1; j>=0; j--){
    //             int p=0;
    //             if(j==0 || (nums[j]<nums[i]))
    //                 p = 1+dp[i+1][i];
    //             int np = dp[i+1][j];
    //             dp[i][j] = max(p,np);
    //         }
    //     }
    //     return dp[0][0];
    // }
    
    //Memoization Solution
    int find(int i, int prev, vector<vector<int>>&dp, vector<int>&nums){
        if(i==nums.size())
            return 0;
        if(dp[i][prev+1]!=-1)
            return dp[i][prev+1];
        int p=0;
        if((prev == -1) || (nums[prev]<nums[i]))
            p = 1+find(i+1,i,dp,nums);
        int np = find(i+1,prev,dp,nums);
        dp[i][prev+1] = max(p,np);
        return dp[i][prev+1];
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return find(0,-1,dp,nums);
    }
};