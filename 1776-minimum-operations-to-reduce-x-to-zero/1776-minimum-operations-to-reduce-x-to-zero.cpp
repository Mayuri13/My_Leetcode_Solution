class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
        }
        sum -= x;       //Our target sum from the required subarray
        int l = 0, tar = 0, ans = -1;
        for(int r=0; r<nums.size(); r++){
            tar += nums[r];
            while(tar > sum && l <= r){
                tar -= nums[l++]; 
            }
            if(tar == sum)
                ans = max(ans, (r-l+1));
        }
        if(ans == -1) return ans;
        return nums.size() - ans;
    }
};