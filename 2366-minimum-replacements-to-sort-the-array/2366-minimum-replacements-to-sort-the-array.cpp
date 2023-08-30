class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans = 0;
        int prev = 1e9;
        for(int i=nums.size()-1; i>=0 ;i--){
            if(nums[i]<=prev){
                prev = nums[i];
                continue;
            }
            long long parts = ceil(nums[i]/(double)prev);
            ans += parts-1;
            prev = nums[i]/parts;
        }
        return ans;
    }
};