class Solution {
public:
    bool find(int i, vector<int>& dp, vector<int>& nums){
        if(i==nums.size())
            return true;
        if(dp[i]!=-1)
            return dp[i];
        if(i+1 < nums.size() && nums[i]==nums[i+1]){
            if(find(i+2,dp,nums)){
                dp[i] = true;
                return dp[i];
            }
        }
        if(i+2 < nums.size() && nums[i]==nums[i+1] && nums[i+1]==nums[i+2]){
            if(find(i+3,dp,nums)){
                dp[i] = true;
                return dp[i];
            }
        }
        if(i+2 < nums.size() && (nums[i] + 1 == nums[i+1]) && (nums[i+1] + 1 == nums[i+2])){
            if(find(i+3,dp,nums)){
                dp[i] = true;
                return dp[i];
            }
        }
        dp[i] = false;
        return dp[i];
    }
    bool validPartition(vector<int>& nums) {
        if(nums.size()==2)
            return nums[0]==nums[1];
        int n = nums.size();
        vector<int>dp(n+1,-1);
        return find(0,dp,nums);
    }
};