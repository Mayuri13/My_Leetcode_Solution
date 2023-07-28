class Solution {
public:
    //This function will return score of player1 after all optimal turns
    int find(int i, int j, vector<int>&nums, vector<vector<int>>&dp){
        if(i+1==j)
            return max(nums[i],nums[j]);
        if(i==j)
            return nums[i];
        if(dp[i][j]!=-1)
            return dp[i][j];
        dp[i][j] = max(nums[i]+min(find(i+2,j,nums,dp),find(i+1,j-1,nums,dp)),
                   nums[j]+min(find(i+1,j-1,nums,dp),find(i,j-2,nums,dp)));
        return dp[i][j];
        
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size(), sum=0;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int p1 = find(0,n-1,nums,dp);
        for(int i=0; i<n; i++){
            sum+=nums[i];
        }
        int p2 = sum-p1;
        if(p1>=p2)
            return true;
        return false;
    }
};