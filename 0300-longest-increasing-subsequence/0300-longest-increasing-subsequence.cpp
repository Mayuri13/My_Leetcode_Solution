class Solution {
public:
//Time Complexity - O(nlogn)
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), len = 1;
        vector<int>tmp;
        tmp.push_back(nums[0]);
        for(int i=1; i<n; i++){
            if(nums[i] > tmp.back()){
                tmp.push_back(nums[i]);
                len++;
            }
            else{
                int idx = lower_bound(tmp.begin(), tmp.end(), nums[i]) - tmp.begin();
                tmp[idx] = nums[i];
            }
        }
        return len;
    }

//Time complexity - O(n^2)
    // int lengthOfLIS(vector<int>& nums) {
    //     int n = nums.size(), ans = 1;
    //     vector<int>dp(n,1);
    //     for(int i=1; i<n; i++){
    //         for(int j=0; j<i; j++){
    //             if(nums[i] > nums[j]){
    //                 dp[i] = max(dp[i] , 1+dp[j]);
    //             }
    //         }
    //         ans = max(ans,dp[i]);
    //     }
    //     return ans;
    // }
};